// Mapping.h: interface for the CMapping class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPPING_H__B9BDED61_96EB_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_MAPPING_H__B9BDED61_96EB_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../combat/MudConfig.h"

#include <string>
#include <map>
#include <vector>
using namespace std;

#define NEXT(x)			(x)->next
#define REFS(x)			(x)->refs
#define EXTRA_REF(x)	(x)->extra_ref
#define SIZE(x)			(x)->size
#define BLOCK(x)		(((block_t *)(x)) - 1)	/* pointer arithmetic */
#define STRING(x)		((char *)(x + 1))

#define		HTABLE_SIZE		1024
//string table

//mapping
#define T_UNDEFINED			0x0
#define T_NUMBER			0x2
#define T_STRING			0x4
#define T_MAPPING			0x8
#define T_ARRAY				0x10

#define STRING_MALLOC		0x1 /* has a length an ref count */
#define STRING_HASHED		0x2 /* is in the shared string table */
#define STRING_CONSTANT		0

#define	MAX_MAPPING_SIZE	32768
#define MAX_TABLE_SIZE	32768
#define FILL_PERCENT	80
#define MAP_LOCKED		0x80000000
#define MAP_COUNT		(count & ~MAP_LOCKED)
#define MNB_SIZE		256
#define MAP_HASH_TABLE_SIZE		8	/* must be a power of 2 */

#define MAP_POINTER_HASH(x) (((size_t)x) >> 4)

//字符串阵列。唯一性。
class CVector
{
public:
	typedef vector<string>VECTOR_STR;
	typedef VECTOR_STR::iterator iterator;

	long LoadBuffer(const char * buffer);

	const char * GetBuffer()
	{
		m_string.erase();
		m_string+="({";
		for(iterator p = m_Array.begin(); p != m_Array.end(); ++p)
		{
			m_string.append(1, '\"');
			m_string.append(* p);
			m_string.append("\",");
		}
		m_string +="})";
		return m_string.c_str();
	};

	iterator begin()
	{
		return m_Array.begin();
	};
	
	iterator end()
	{
		return m_Array.end();
	};

	void append(string t)
	{
		iterator p = find(t);
		if(p == m_Array.end()) m_Array.push_back(t);
	};

	void remove(string t)
	{
		iterator p = find(t);
		if(p != m_Array.end() ) m_Array.erase(p);
	};

	iterator find(string t)
	{
		iterator p;
		for (p = m_Array.begin(); p != m_Array.end(); ++p)
			if( t == *p)
			{
				return p;
			}

		return p;
	};

	const char * operator[](unsigned int pos)
	{
		if(pos < 0 || pos > m_Array.size() ) return "";
		return m_Array[pos].c_str();
	};

	void clear()
	{
		m_Array.clear();
	};

	long count()
	{
		return m_Array.size();
	}

	int get_save_size()
	{
		iterator p;
		int count = 0;
		for (p = m_Array.begin(); p != m_Array.end(); ++p)
			count += ((*p).length() + 3);

		return count + 5;
	}

	CVector(){};
	~CVector()
	{
		clear();
	};

protected:
	VECTOR_STR m_Array;
	string		m_string;
	
};

//映射类。键为字符串，值类型支持整形，字符串，映射，和字符串阵列。
class CMapping 
{
public:
	typedef struct block_s {
		struct block_s * next;	

		unsigned short size;	
		unsigned short refs;	
	}block_t;

	typedef struct svalue_s{
		int		type;
		int		subtype;

		union{
			long	number;
			char	* string;
			CMapping * map;
			CVector	 * arr;
		}u;
	}svalue_t;

	typedef struct mapping_node_s {
		struct mapping_node_s * next;
		svalue_t values[2];
	}mapping_node_t;

	typedef struct mapping_node_block_s {
		struct mapping_node_block_s *next;
		mapping_node_t nodes[MNB_SIZE];
	}mapping_node_block_t;

public:
	void copyMapping(CMapping * m);
	void free_map();
	char * make_shared_string(const char * str);
	block_t * alloc_new_string(const char * string, int h);
	char * findstring(const char * s);
	block_t * sfindblock(const char * s, int h);

	svalue_t * find_string_in_mapping(const char * p);
	svalue_t * find_in_mapping(svalue_t * lv);

	void free_node(mapping_node_t * mn); 
	void mapping_delete(svalue_t * lv);

	mapping_node_t * node_find_in_mapping(svalue_t * lv);
	svalue_t * insert_in_mapping(const char * key);
	mapping_node_t * new_map_node();
	int msameval(svalue_t * arg1, svalue_t * arg2);
	svalue_t * find_for_insert(svalue_t * lv, int doTheFree);
	void keys(CVector & v);
	void values(CVector & v);

	CVector * add(const char * key, CVector & v);
	int undefinedp(const char * key);

	void set(const char * key, const char * val);
	void set(const char * key, long val);
	void set(const char * key, CMapping & mapping);
	void set(const char * key, CVector & vector);

	void del(const char * key);

	long query(const char * key);
	const char * querystr(const char * key);
	CMapping * querymap(const char * key);
	CVector * queryvec(const char * key);
	
	long add(const char * key, long nValue);

	//提供遍历用函式。
	long LoadBuffer(const char * buffer);
	const char * GetBuffer();

	void clear();
	int GetCount();
	
	CMapping();
	virtual ~CMapping();

	int growmap();

	static int node_hash(mapping_node_t * mn) 
	{    return MAP_POINTER_HASH(mn->values[0].u.number); }

protected:
	void allocate_mapping(int n);
	void free_svalue(svalue_t * v);
	int svalue_to_int(svalue_t * v);
	static char * make_string(const char * value);
	static void free_string_svalue(svalue_t * v);
	
	void free_string(const char * ptr);	
	
public:
	LONG & operator[](const char * key);
	int svalue_save_size(svalue_t * v);
	void save_svalue(svalue_t * v, char ** buf);
	CMapping * get_master_map(const char * key, const char ** subkey, int insertmap, const char * comm);
	
	mapping_node_t **table;
	int	 table_size;
	int	 unfilled;
	int	 count;

	long Value(string a);
	char * m_Mapping;	

	long m_nValue;
};

void free_mapping_block();

#endif // !defined(AFX_MAPPING_H__B9BDED61_96EB_11D4_98AB_0050BABC5212__INCLUDED_)
