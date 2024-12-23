// Mapping.cpp: implementation of the CMapping class.
//
//////////////////////////////////////////////////////////////////////
#include <cstring>
#include <limits.h>
#include "stdafx.h"
#include "stdio.h"
#include "Mapping2.h"
#include "Globle.h"
#include "../table/hash.h"

#define ALLOCATE(ptr, type, desc) (ptr = (type *)malloc(sizeof(type))); 
#define CALLOCATE(ptr, num, type, desc) (ptr = (type *)malloc(sizeof(type[1]) * (num))); 
#define RESIZE(ptr, num, type, desc) ((type *)realloc((void *)ptr, sizeof(type[1]) * (num)));
#define FREE(ptr, des) (free(ptr)); 

//与内存分配相关的一组macros
/*
#define ALLOCATE(ptr, type, desc) (ptr = (type *)malloc(sizeof(type))); register_new((unsigned char *)ptr, sizeof(type));
#define CALLOCATE(ptr, num, type, desc) (ptr = (type *)malloc(sizeof(type[1]) * (num))); register_new((unsigned char *)ptr, sizeof(type[1]) * (num));
#define RESIZE(ptr, num, type, desc) ((type *)realloc((void *)ptr, sizeof(type[1]) * (num))); register_renew((unsigned char *)ptr, sizeof(type[1]) * (num));
#define FREE(ptr, des) (free(ptr)); free_new((unsigned char *)ptr);

void register_new(unsigned char * val, LONG size)
{
	LONG ptr = (LONG) val;
	MEMLIST::iterator p;

	if( (p = memlist.find(ptr)) != memlist.end())
	{
		output_error("ERROR:没释放就分配了同一地址:%ld size:%ld!", ptr, size);
	}
	else
	{
		output_error("new:%ld size:%ld", ptr, size);
	}
	
	memlist[ptr] = size;
}

void register_renew(unsigned char * p, LONG size)
{
	LONG ptr = (LONG)p;

	if( memlist.find(ptr) == memlist.end())
	{
		output_error("ERROR:重新分配未分配的地址.%ld size:%ld!", ptr, size);
	}
	else
	{
		output_error("renew:%ld from size:%ld to size", ptr, memlist[ptr], size);
	}

	memlist[ptr] = size;
}

void free_new(unsigned char * p)
{
	LONG ptr = (LONG) p;
	output_error("free:%ld size:%ld", ptr, memlist[ptr]);
	memlist.erase(ptr);
}
*/
CMapping::mapping_node_t * free_nodes = 0;
CMapping::mapping_node_block_t * mapping_node_blocks = 0;
int		total_mapping_numbers = 0;
CMapping::svalue_t	const0u;

int		htable_size_minus_one, htable_size;
CMapping::block_t ** base_table;


//debug lanwood 2001-07-30
const char * print_svalue(const char * key, CMapping::svalue_t * sv)
{
	static char msg[255];

	if(sv->type == T_NUMBER)
		return snprintf(msg, 255, "%s : %d", key, sv->u.number);
	else if(sv->type == T_STRING)
		return snprintf(msg, 255, "%s : %s", key, sv->u.string);
	else if(sv->type == T_ARRAY)
		return snprintf(msg, 255, "%s : ({})", key);
	else if(sv->type == T_MAPPING)
		return snprintf(msg, 255, "%s : ([])", key);
	
	return "free -> undefined!";
}

void printf_all_mappings()
{
	CMapping::mapping_node_block_t * p = mapping_node_blocks;

	output_error("total mapping numbers:%ld", total_mapping_numbers);
	while(p)
	{
		CMapping::mapping_node_t * node = p->nodes;
		p = p->next;

		while(node)
		{
			CMapping::svalue_t * key = node->values;
			CMapping::svalue_t * val = node->values + 1;

			node = node->next;

			output_error(print_svalue(key->u.string, val));
		}
	}
}

void free_mapping_block()
{
	CMapping::mapping_node_block_t * mnb;

	while((mnb = mapping_node_blocks))
	{
		mapping_node_blocks = mnb->next;
		FREE(mnb, "free_mapping_block");
	}	
}

#define	MAX_STRING_LENGTH		2048
#define StrHash(s) (whashstr((s), 20) & (htable_size_minus_one))
#define hfindblock(s, h) sfindblock(s, h = StrHash(s))
#define findblock(s) sfindblock(s, StrHash(s))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
void CMapping::free_string(const char * str)
{
    block_t **prev, *b;
    int h;

    b = BLOCK(str);

	if(b != findblock(str))
		output_error("free_string called on non-shared string:%s", str);
    //DEBUG_CHECK1(b != findblock(str),"stralloc.c: free_string called on non-shared string: %s.\n", str);
        
    if (!REFS(b)) return;

    REFS(b)--;
    if (REFS(b) > 0)
	return;

    h = StrHash(str);
    prev = base_table + h;
    while ((b = *prev)) 
	{
		if (STRING(b) == str) 
		{
			*prev = NEXT(b);
			break;
		}
		prev = &(NEXT(b));
    }

	if(!b)
		output_error("free_string: not found in string table! %s", str);
    //DEBUG_CHECK1(!b, "free_string: not found in string table! (\"%s\")\n", str);
//    SUB_NEW_STRING(SIZE(b), sizeof(block_t));
    FREE(b, "free_string");    
}

char * CMapping::make_shared_string(const char * str)
{
    block_t *b;
    int h;

    b = hfindblock(str, h);	/* hfindblock macro sets h = StrHash(s) */
    if (!b) 
	{
		b = alloc_new_string(str, h);
    } 
	else 
	{
		if (REFS(b))
			REFS(b)++;
	}
    
    return (STRING(b));
}

/* alloc_new_string: Make a space for a string.  */
CMapping::block_t * CMapping::alloc_new_string(const char * string, int h)
{
    block_t * b;
    int len = strlen(string);
    int size;

    if (len > MAX_STRING_LENGTH) 
	{
		len = MAX_STRING_LENGTH;
    }
    size = sizeof(block_t) + len + 1;
    b = (block_t *)malloc(size);
    strncpy(STRING(b), string, len);
    STRING(b)[len] = '\0';	/* strncpy doesn't put on \0 if 'from' too long */
    SIZE(b) = (len > USHRT_MAX ? USHRT_MAX : len);
    REFS(b) = 1;
    NEXT(b) = base_table[h];
    base_table[h] = b;
    return (b);
}

CMapping::block_t * CMapping::sfindblock (const char * s, int h)
{
    block_t *curr, *prev;

    curr = base_table[h];
    prev = NULL;

    while (curr) 
	{
		if (* (STRING(curr)) == *s && !strcmp(STRING(curr), s)) 
		{	/* found it */
			if (prev) 
			{		/* not at head of list */
				NEXT(prev) = NEXT(curr);
				NEXT(curr) = base_table[h];
				base_table[h] = curr;
			}
			return (curr);	/* pointer to string */
		}
		prev = curr;
		curr = NEXT(curr);
    }
    return ((block_t *) 0);	/* not found */
}

char * CMapping::findstring(const char * s)
{
    block_t *b;

    if ((b = findblock(s))) 
	{
		return STRING(b);
    } 
	else 
	{
		return (NULL);
    }
}

CMapping::svalue_t * CMapping::find_in_mapping(svalue_t * lv)
{
	int i = MAP_POINTER_HASH(lv->u.number) & table_size;
	mapping_node_t * n = table[i];

	while (n) 
	{
	    if (msameval(n->values, lv)) 
			return n->values + 1;
	    n = n->next;
	}

	return &const0u;
}

CMapping::svalue_t * CMapping::find_string_in_mapping(const char * p)
{
    char *ss = findstring(p);
    int i;
    mapping_node_t *n;
    
    if (!ss) return &const0u;
    i = MAP_POINTER_HASH(ss);
    n = table[i & table_size];
    
    while (n) 
	{
		if (n->values->type == T_STRING && n->values->u.string == ss)
			return n->values + 1;
		n = n->next;
    }

    return &const0u;
}

void CMapping::mapping_delete(svalue_t * lv)
{
	int i = MAP_POINTER_HASH(lv->u.number) & table_size;
	mapping_node_t **prev = table + i, *elt;

	if ((elt = *prev)) 
	{
	    do 
		{
			if (msameval(elt->values, lv)) 
			{
				if (!(*prev = elt->next) && !table[i]) 
				{
					unfilled++;
				}
				count--;
				free_svalue(elt->values);
				free_node(elt);
				return;
			}
			prev = &(elt->next);
	    }while ((elt = elt->next));
	} 
}

CMapping::mapping_node_t * CMapping::new_map_node() 
{
    mapping_node_block_t * mnb;
    mapping_node_t * ret;
    int i;

    if ((ret = free_nodes)) 
	{
		free_nodes = ret->next;
    } 
	else 
	{
		ALLOCATE(mnb, mapping_node_block_t, "new_map_node");
		mnb->next = mapping_node_blocks;
		mapping_node_blocks = mnb;
		mnb->nodes[MNB_SIZE - 1].next = 0;
		for (i = MNB_SIZE - 1; i--; )
			mnb->nodes[i].next = &mnb->nodes[i+1];
		ret = &mnb->nodes[0];
		free_nodes = &mnb->nodes[1];
    }
    return ret;
} 

int CMapping::msameval(svalue_t * arg1, svalue_t * arg2) 
{
    if( (arg1->type | arg2->type) == T_NUMBER )
		return arg1->u.number == arg2->u.number;
	else
		return arg1->u.arr == arg2->u.arr;    
}

CMapping::svalue_t * CMapping::find_for_insert(svalue_t * lv, int doTheFree)
{
	int oi = MAP_POINTER_HASH(lv->u.number);
	unsigned short i = oi & table_size;
	mapping_node_t *n, *newnode, **a = table + i;
 	
	if ((n = *a)) 
	{
	    do 
		{
			if (msameval(lv, n->values)) 
			{
				/* normally, the f_assign would free the old value */
				if (doTheFree) 
					free_svalue(n->values + 1);
				return n->values + 1;
			}
	    } while ((n = n->next));
	    
	    n = *a;
	}
	else if (!(--unfilled)) 
	{
	    int size = table_size + 1;

	    if (growmap()) 
		{ 
			if (oi & size) i |= size;
			n = *(a = table + i);
	    } 
		else 
		{
			output_error("Out of memory");
	    }
	}

	count++;
	if (MAP_COUNT > MAX_MAPPING_SIZE) 
	{
	    count--;
	    output_error("mapping to large!");
	}

	newnode = new_map_node();
	(* newnode->values) = (* lv);
	
	(*a = newnode)->next = n;
	lv = newnode->values + 1;
	*lv = const0u;
	
	return lv;
}

CMapping::mapping_node_t * CMapping::node_find_in_mapping(svalue_t * lv)
{
	int i;
	mapping_node_t *elt, **a = table;
 
	i = MAP_POINTER_HASH(lv->u.number) & table_size;
	for (elt = a[i]; elt; elt = elt->next) 
	{
		if (msameval(elt->values, lv))
			return elt;
	}
	return (mapping_node_t *)0;
}

CMapping::svalue_t * CMapping::insert_in_mapping(const char * key) 
{
    svalue_t lv;
    svalue_t *ret;
	
	lv.type = T_STRING;
	lv.subtype = STRING_HASHED;
    lv.u.string = make_shared_string(key);
    ret = find_for_insert(&lv, 1);
	
    /* lv.u.string will have been converted to a shared string */
    //free_string(lv.u.string);
    return ret;
}

void CMapping::set(const char * key, const char * val)
{
	svalue_t *s;
	const char * subkey;
	CMapping * map = this;
	
	if(! key )
	{
		output_error("error: CMapping::set(const char * key, const char * val) key is 0!");
		return;
	}

	if(! key[0])
	{
		output_error("error: CMapping::set(const char * key, const char * val) key is NULL!");
		return;
	}

	do
	{
		map = map->get_master_map(key, &subkey, 1, "set");

	} while(subkey && (key = subkey) );
	
	
    s = map->insert_in_mapping(key);
    s->type = T_STRING;
	s->subtype = STRING_MALLOC;
    s->u.string = make_string(val);	
}

void CMapping::set(const char * key, long val)
{
	svalue_t * s;
	const char * subkey;
	CMapping * map = this;
	
	if(! key)
	{
		output_error("error: CMapping::set(const char * key, long val) key is 0!");
		return;
	}

	if(! key[0])
	{
		output_error("error: CMapping::set(const char * key, long val) key is NULL!");
		return;
	}

	do
	{
		map = map->get_master_map(key, &subkey, 1, "set");

	} while(subkey && (key = subkey) );

    s = map->insert_in_mapping(key);
    s->type = T_NUMBER;
    s->u.number = val;
}

void CMapping::set(const char * key, CMapping & mapping)
{
	svalue_t * s;
	const char * subkey;
	CMapping * map = this;
	
	if(! key)
	{
		output_error("error: CMapping::set(const char * key, CMapping * mapping) key is 0!");
		return;
	}

	if(! key[0])
	{
		output_error("error: CMapping::set(const char * key, CMapping * mapping) key is NULL!");
		return;
	}

	do
	{
		map = map->get_master_map(key, &subkey, 1, "set");

	} while(subkey && (key = subkey) );

    s = map->insert_in_mapping(key);
    s->type = T_MAPPING;

	CMapping * m = new CMapping();
	
	m->copyMapping(&mapping);
    s->u.map = m;
}

void CMapping::set(const char * key, CVector & v)
{
	const char * subkey;
	CMapping * map = this;
	
	if(! key)
	{
		output_error("error: CMapping::set(const char * key, CVector & v) key is 0!");
		return;
	}

	if(! key[0])
	{
		output_error("error: CMapping::set(const char * key, CVector & v) key is NULL!");
		return;
	}

	do
	{
		map = map->get_master_map(key, &subkey, 1, "set");

	} while(subkey && (key = subkey) );

    svalue_t * s = map->insert_in_mapping(key);
    s->type = T_ARRAY;

	CVector * vec = new CVector();
	(* vec) = v;
	s->u.arr = vec;
}

int CMapping::growmap()
{
	int oldsize = table_size + 1;
	int newsize = oldsize << 1;
	int i;

	mapping_node_t **a, **b, **eltp, *elt;

	if (newsize > MAX_TABLE_SIZE) 
		return 0;
	/* resize the hash table to be twice the old size */
	table = a = RESIZE(table, newsize, mapping_node_t *, "growmap");
	
	if (!a) 
	{			
		unfilled = table_size;
		return 0;
	}

//		total_mapping_size += sizeof(mapping_node_t *) * oldsize;
//	output_error("mapping.c: growMap mapping %ld size = %d total = %ld", this, newsize, total_mapping_numbers);

	unfilled = oldsize * (unsigned)FILL_PERCENT / (unsigned)100;
	table_size = newsize - 1;
	/* zero out the new storage area (2nd half of table) */
	memset(a += oldsize, 0, oldsize * sizeof(mapping_node_t *));
	i = oldsize;
	while (a--, i--) 
	{
		if ((elt = *a)) 
		{
			eltp = a, b = a + oldsize;
			do 
			{
				if (node_hash(elt) & oldsize) 
				{
					*eltp = elt->next;
					if (!(elt->next = *b)) unfilled--;
					*b = elt;   
					elt = *eltp;
				}
				else 
					elt = *(eltp = &elt->next);
			}while(elt);
		
			if(!*a) unfilled++;
		}
	}

	return 1;
}

void CMapping::free_node(mapping_node_t * mn) 
{
	free_svalue(mn->values + 1);
	mn->next = free_nodes;
	free_nodes = mn;
}

long CVector::LoadBuffer(const char * buffer)
{
	int state = 0;
	string val;
	long ptr = 0;
	char c;

	this->clear();

	while((c = buffer[ptr++]))
	{
		switch(state)
		{
		case 0:
			if(c == '(') state = 1;
			else return -1;
			break;
		case 1:
			if(c == '{') state = 2;
			else return -1;
			break;
		case 2:
			if(c == '\"')
			{
				val.erase();
				state = 3;
			}
			else if(c == '}') state = 5;
			else return -1;
			break;
		case 3:
			if(c == '\"')
			{
				m_Array.push_back(val);
				state = 4;
			}
			else val.append(1, c);
			break;
		case 4:
			if(c == ',') state = 2;
			else return -1;
			break;
		case 5:
			if(c == ')') return ptr;
			else return -1;
			break;
		}
	}

	return -1;
}


char * CMapping::make_string(const char * value)
{
	int len = strlen(value);
	char * ptr = new char[len + 1];
	memcpy(ptr, value, len + 1);

	return ptr;
}

int CMapping::svalue_to_int(svalue_t *v)
{
	if (v->type == T_STRING && v->subtype != STRING_HASHED) 
	{
		char *p = make_shared_string(v->u.string);
		free_string_svalue(v);
		v->subtype = STRING_HASHED;
		v->u.string = p;
    }
    
    return MAP_POINTER_HASH(v->u.number);
}

void CMapping::free_string_svalue(svalue_t * v)
{
    if (v->subtype == STRING_MALLOC) 
	{		
		FREE(v->u.string, "free_string_svalue");
	}
	
	v->subtype = 0;
	v->type = 0;
	v->u.string = 0;
}

void CMapping::free_svalue(svalue_t *v)
{
	if (v->type == T_STRING) 
	{
		char * str = v->u.string;
		if (v->subtype == STRING_MALLOC) 
		{
		    delete []str;			
		}
		else
		{
			free_string(v->u.string);
		}		
	}
    else if(v->type == T_ARRAY)
	{
		delete v->u.arr;
	}
	else if(v->type == T_MAPPING)
	{
		delete v->u.map;		
	}

	v->u.number = 0;
	v->type = T_UNDEFINED;
}

void CMapping::allocate_mapping(int n)
{
	mapping_node_t **a;

	if (n > MAX_MAPPING_SIZE) n = MAX_MAPPING_SIZE;
	if (n > MAP_HASH_TABLE_SIZE) 
	{
	    n |= n >> 1;
	    n |= n >> 2;
	    n |= n >> 4;
	    if (n & 0xff00) n |= n >> 8;
	    table_size = n++;
	}
	else 
		table_size = (n = MAP_HASH_TABLE_SIZE) - 1;
	
	/* The size is actually 1 higher */
	unfilled = n * (unsigned)FILL_PERCENT /(unsigned)100;
	a = table = (mapping_node_t **)malloc(n *= sizeof(mapping_node_t *));
	if (!a) output_error("Allocate_mapping 2 - out of memory.\n");

	/* zero out the hash table */
	memset(a, 0, n);
	count = 0;
}

long CMapping::query(const char * key)
{
	if(! key)
	{
		output_error("error: CMapping::query(const char * key) key is 0!");
		return 0;
	}

	if(! key[0])
	{
		output_error("error: CMapping::query(const char * key) key is null!");
		return 0;
	}

	const char * subkey;
	CMapping * map = this;
	
	do
	{
		if(! (map = map->get_master_map(key, &subkey, 0, "query")) )
			return 0;

	} while(subkey && (key = subkey) );

	svalue_t * nvalue = map->find_string_in_mapping(key);
	if(nvalue != &const0u && nvalue->type == T_NUMBER)
		return nvalue->u.number;
	
	return 0;
}

const char * CMapping::querystr(const char * key)
{
	if(! key)
	{
		output_error("error: CMapping::querystr(const char * key) key is 0!");
		return "";
	}

	if(! key[0])
	{
		output_error("error: CMapping::querystr(const char * key) key is null!");
		return "";
	}

	const char * subkey;
	CMapping * map = this;
	
	do
	{
		if(! (map = map->get_master_map(key, &subkey, 0, "querystr")) )
			return "";

	} while(subkey && (key = subkey) );
	
	svalue_t * nvalue = map->find_string_in_mapping(key);
	if(nvalue != &const0u && nvalue->type == T_STRING)
		return nvalue->u.string;
	
	return "";
}

CMapping * CMapping::querymap(const char *key)
{
	if(! key)
	{
		output_error("error: CMapping::querymap(const char * key) key is 0!");
		return 0;
	}

	if(! key[0])
	{
		output_error("error: CMapping::querymap(const char * key) key is NULL!");
		return 0;
	}

	const char * subkey;
	CMapping * map = this;
	
	do
	{
		if(! (map = map->get_master_map(key, &subkey, 0, "querymap")) )
			return 0;

	} while(subkey && (key = subkey) );

	svalue_t * nvalue = map->find_string_in_mapping(key);
	if(nvalue != &const0u && nvalue->type == T_MAPPING)
		return nvalue->u.map;
	
	return 0;
}

CVector * CMapping::queryvec(const char * key)
{
	const char * subkey;
	CMapping * map = this;

	if(! key)
	{
		output_error("error: CMapping::queryvec(const char * key) key is 0!");
		return 0;
	}

	if(! key[0])
	{
		output_error("error: CMapping::queryvec(const char * key) key is NULL!");
		return 0;
	}
	
	do
	{
		if(! (map = map->get_master_map(key, &subkey, 0, "queryvec")) )
			return 0;

	} while(subkey && (key = subkey) );

	svalue_t * nvalue = map->find_string_in_mapping(key);
	if(nvalue != &const0u && nvalue->type == T_ARRAY)
		return nvalue->u.arr;
	
	return 0;
}

CMapping::CMapping()
{ 		
	table_size = 0;
	m_Mapping = 0;
	table = 0;

	int x;

	if(! total_mapping_numbers++)
	{
		const0u.type = T_NUMBER;
		const0u.u.number = 0;

		htable_size_minus_one = 0;

		for (htable_size = 1; htable_size < HTABLE_SIZE; htable_size *= 2);
		htable_size_minus_one = htable_size - 1;
		CALLOCATE(base_table, htable_size, block_t *, "CMapping");
	
		for (x = 0; x < htable_size; x++) 
		{
			base_table[x] = 0;
		}	
	}

	allocate_mapping(8);
};

CMapping::~CMapping()
{	
	free_map();

	if(m_Mapping)
		delete []m_Mapping;

	total_mapping_numbers--;
	if(! total_mapping_numbers)
	{
		free_mapping_block();

		for(int x = 0; x < htable_size; x++)
		{
			block_t *prev, *b;
			prev = base_table[x];
			while ((b = prev)) 
			{
				prev = (NEXT(b));
				FREE(b, "~Mapping");
			}
		}

		FREE((char *)base_table, "~Mapping");
    }
};

void CMapping::copyMapping(CMapping * m)
{
	if(! m) return;		//void return;

	int k = m->table_size;
    mapping_node_t *elt, *nelt, **a, **b = m->table, **c;
	svalue_t * va;

    free_map();
    
    table_size = k++;
    unfilled = m->unfilled;
    c = CALLOCATE(table, k, mapping_node_t *, "copyMapping");
    	
    count = m->count;
    memset(c, 0, k * sizeof(mapping_node_t *));

    while (k--) 
	{
		if ((elt = b[k])) 
		{
			a = c + k;
			do {
				nelt = new_map_node();

				va = elt->values;

				//key copy
				(* nelt->values) = (* va);		
				if(va->type == T_STRING)	//string copy
				{					
					(nelt->values + 1)->u.string = make_shared_string(va->u.string);
				}

				//value copy
				va = elt->values + 1;
				( * (nelt->values + 1)) = (* va);

				if(va->type == T_STRING)	//string copy
				{					
					(nelt->values + 1)->u.string = make_string(va->u.string);
				}
				else if(va->type == T_MAPPING)	//mapping copy
				{
					(nelt->values + 1)->u.map = new CMapping();
					((nelt->values + 1)->u.map)->copyMapping(va->u.map);
				}
				else if(va->type == T_ARRAY)	//array copy
				{
					(nelt->values + 1)->u.arr = new CVector();
					* ((nelt->values + 1)->u.arr) = * (va->u.arr);
				}

				nelt->next = *a;
				*a = nelt;
			} while ((elt = elt->next));
		}
    }    
}

void CMapping::free_map()
{
	int j = table_size;
	mapping_node_t *elt, *nelt, **a = table;
	
	do {
		for (elt = a[j]; elt; elt = nelt) 
		{
		    nelt = elt->next;
		    free_svalue(elt->values);
		    free_node(elt);		
		}
	} while (j--);
	
	FREE((char *)a, "free_map");
	table = 0;
}

//需要优化的代码
CMapping * CMapping::get_master_map(const char *key, const char ** subkey, int insertmap, const char * comm)
{
	//分析是否有 形如：mask/tt/u2  ->map:mask -> map:tt ->query("u2")
	register int p = 0, v = 0;
	char val[255];

	(* subkey) = 0;
	if(strlen(key) > 250)
	{
		output_error("key is too large. (comm = %s)", comm);
		output_error("key is %s", key);
		if(insertmap)
			return this;
		else
			return 0;
	}

	while(key[p])
	{
		if(key[p] == '/')
		{
			(* subkey) = &key[v + 1];
			break;
		}
		else
		{
			val[v++] = key[p++];
		}
	}

	val[v] = 0;

	if( * subkey)
	{
		//寻找子mapping
		svalue_t * nvalue = find_string_in_mapping(val);
		if(nvalue != &const0u && nvalue->type == T_MAPPING)
			return nvalue->u.map;			
		
		if(insertmap)
		{
			//按装新的mapping
			svalue_t * s;

			if(nvalue != &const0u)
			{
				s = nvalue;
				free_svalue(s);
			}
			else
				s = insert_in_mapping(val);

			s->type = T_MAPPING;
			CMapping * m = new CMapping();
			s->u.map = m;
			return m;
		}

		return 0;
	}

	return this;
}


void CMapping::save_svalue(svalue_t *v, char **buf)
{
	switch(v->type) 
	{
	case T_STRING:
		{
			register char *cp = *buf, *str = v->u.string;
			char c;

			*cp++ = '"';
			while ((c = *str++)) 
			{
				if (c == '"' || c == '\\') {
				*cp++ = '\\';
				*cp++ = c;
			}
			else *cp++ = (c == '\n') ? '\r' : c;
		}

	    *cp++ = '"';
	    *(*buf = cp) = '\0';
	    return;
	}

    case T_ARRAY:
	{	
		const char * ptr = v->u.arr->GetBuffer();
		while(* ptr)
			*(*buf)++ = *ptr++;
	    
	    *(*buf) = '\0';
	    return;
	}

    case T_NUMBER:
		{
		    int res = v->u.number, fact, len = 1, neg = 0;
			register char *cp;

			if (res < 0) 
			{ 
				len++, neg = 1, res = (-res) & 0x7fffffff; 
			}
			fact = res;
			while (fact > 9) { fact /= 10; len++; }
			*(cp = (*buf += len)) = '\0';
			do 
			{
				*--cp = res % 10 + '0';
				res /= 10;
			} while (res);
			if (neg) *(cp-1) = '-';
			return;
		}

    case T_MAPPING:
		{
			int j = v->u.map->table_size;
			mapping_node_t **a = v->u.map->table, *elt;

			*(*buf)++ = '(';
			*(*buf)++ = '[';
			do {
				for (elt = a[j]; elt; elt = elt = elt->next) 
				{
					save_svalue(elt->values, buf);
					*(*buf)++ = ':';
					save_svalue(elt->values + 1, buf);
					*(*buf)++ = ',';
				}
			} while (j--);

			*(*buf)++ = ']';
			*(*buf)++ = ')';
			*(*buf) = '\0';
			return;
		}    
	}
}

const char * CMapping::GetBuffer()
{
	svalue_t s;
	char * p;

	s.type = T_MAPPING;
	s.u.map = this;

	int theSize = svalue_save_size(&s);

	if(m_Mapping) delete []m_Mapping;

	m_Mapping = new char[theSize];
	p = m_Mapping;
	m_Mapping[0] = 0;

	save_svalue(&s, &p);
	return m_Mapping;
}

int CMapping::svalue_save_size(svalue_t *v)
{
	switch(v->type) 
	{
    case T_STRING:
		{
			register char *cp = v->u.string;
			char c;
			int size = 0;

			while ((c = *cp++)) 
			{
				if (c == '\\' || c == '"') size++;
				size++;
			}
			return 3 + size;
		}

    case T_MAPPING:
		{
			mapping_node_t **a = v->u.map->table, *elt;
			int j = v->u.map->table_size, size = 0;

			do 
			{
				for (elt = a[j]; elt; elt = elt->next) 
				{
					size += svalue_save_size(elt->values) +
					svalue_save_size(elt->values+1);
				}
			} while (j--);
			return size + 5;
		}

	case T_ARRAY:
		{
			return v->u.arr->get_save_size();					
		}

    case T_NUMBER:
		{
			int res = v->u.number, len;
			len = res < 0 ? (res = (-res) & 0x7fffffff,3) : 2;
			while (res>9) { res /= 10; len++; }
			return len;
		}

    default:
		{
			return 1;
		}
	}
}

void CMapping::del(const char * key)
{
	const char * subkey;
	CMapping * map = this;
	
	if(! key)
	{
		output_error("error: CMapping::del(const char * key) key is 0!");
		return;
	}

	if(! key[0])
	{
		output_error("error: CMapping::del(const char * key) key is null!");
		return;
	}

	do
	{
		if(! (map = map->get_master_map(key, &subkey, 0, "del")) )
			return;

	} while(subkey && (key = subkey) );

	svalue_t s;
	s.type = T_STRING;
	s.subtype = STRING_HASHED;
	s.u.string = make_shared_string(key);
    map->mapping_delete(&s);
	free_string(s.u.string);
}

//增加对数组的支持："channel":({"chat","rumor","xyj","sldh",}),
/*
        (         [     10   ]          )
  <0> ----> <1> -----> <2> -----> <3> ------> <success>
						
                        |\   "        "		       :           "           "
						| \-----> <4> ------> <5> ------> <6> ------> <7> ------> <8>
						|		  |_|			20 13 10	|20 13    |_|			|
						|			push key	|____|		|10			push val	|
						|									|						|
						|				,			 -, num |						|
						|<---------------------	<9>	<-------+						|
						|						|_|			|						|
						|						num			|						|
						|									|	(			[ map	|
						|									+-------> <10> -------->|
						|												|			|
						|												| { vector	|
						|												+---------->|
						|															|
						|									,						|
						+<----------------------------------------------------------+
*/																					

long CMapping::LoadBuffer(const char * buffer)
{
	int state = 0, sign = 0;
	char c;
	long number = 0, ptr = 0;
	char key[512], val[1024];
	int  k = 0, v = 0;
	svalue_t * s;

	bool bTrans = false;
		
	free_map();
	allocate_mapping(8);

	//分析字符串(["age":20,"name":"xiao",)]
	while(( c = buffer[ptr++] ))	//只要buffer[ptr] == 0，即结束。
	{
		switch(state)
		{
		case 0:			//开始态：接收一个'('转1态，否则错误。
			if(c == '(') state = 1;
			else 
				return -1;
			break;
		case 1:			//接收一个'['转2态，否则错误。
			if(c == '[') state = 2;
			else 
				return -1;
			break;
		case 2:			//接收一个']'转3态；接收一个'\"'转4态；其他错误。
			if(c == ']') state = 3;
			else if(c == '\"')
			{
				key[0] = 0;
				k = 0;
				state = 4;
			}
			else
				return -1;
			break;
		case 3:			//接收一个')'结束，否则错误。
			if(c == ')') return ptr;
			else
				return -1;
			break;
		case 4:			//接收一个"\""转5态，其他压入字符串。
			if(c == '\"')
			{
				key[k] = 0;
				state = 5;
			}
			else 
			{
				key[k++] = c;
				if(k == 511) return -1;		//越界
			}
			break;
		case 5:			//接收一个":"转6态，否则错误。
			if(c == ':') state = 6;
			else 
				return -1;
			break;
		case 6:			//接收一个'\"'转7态；接收一个数字转9态；接收一个'('转8态。其他错误。
			if(c == '\"')
			{
				val[0] = 0;
				v = 0;
				state = 7;
			}
			else if( c == '-' )
			{
				state = 9;
				number = 0;
				sign = -1;
			}
			else if( c >= '0' && c <= '9')
			{
				state = 9;
				number = c - '0';
				sign = 1;
			}
			else if(c == '(')
				state = 10;
			else 
				return -1;
			break;
		case 7:			//接收一个'\\'记转义为真，收一个"\""转7态。否则压入字符串。
			if(c == '\\' && ! bTrans)
			{				
				bTrans = true;
			}
			else if(c == '\"')
			{
				if(bTrans)
				{
					val[v++] = c;
					if(v == 1023) return -1;	//越界

					bTrans = false;
				}
				else
				{
					state = 8;
					val[v] = 0;
					//送入string
					s = insert_in_mapping(key);
				    s->type = T_STRING;
					s->subtype = STRING_MALLOC;
					s->u.string = make_string(val);						
				}				
			}
			else 
			{
				val[v++] = c;
				if(v == 1023) return -1;		//越界

				bTrans = false;
			}
			break;
		case 8:			//接收一个","转2态，否则错误。
			if(c == ',') state = 2;
			else 
				return -1;
			break;
		case 9:			//接收一个','转2态；接收一个数字压入数字，否则错误。
			if(c == ',')
			{
				state = 2;
				//送入number;
				s = insert_in_mapping(key);
				s->type = T_NUMBER;
				s->u.number = number * sign;

			}
			else if(c >= '0' && c <= '9')
				number = number * 10 + c - '0';
			else 
				return -1;
			break;
		case 10:
			if(c == '[')
			{
				//处理mapping类的loadbuffer
				CMapping * m = new CMapping();
				if( (number = m->LoadBuffer(&buffer[ptr - 2])) == -1) 
				{
					delete m;
					return -1;
				}

				ptr = ptr - 2 + number;
				
				//送入mapping
				s = insert_in_mapping(key);
				s->type = T_MAPPING;
				s->u.map = m;

				state = 8;
			}
			else if(c == '{')
			{
				//处理vector类的loadbuffer
				CVector * v = new CVector();
				if( (number = v->LoadBuffer(&buffer[ptr - 2])) == -1)
					return -1;
				ptr = ptr - 2 + number;
				
				//送入array
				s = insert_in_mapping(key);
				s->type = T_ARRAY;
				s->u.arr = v;

				state = 8;
			}
			break;
		}
	}

	return -1;
}

LONG & CMapping::operator [](const char *key)
{
	svalue_t * nvalue = find_string_in_mapping(key);
	if(nvalue != &const0u && nvalue->type == T_NUMBER)
		return nvalue->u.number;
	
	m_nValue = 0;
	return m_nValue;	
}

void CMapping::clear()
{
	free_map();
	allocate_mapping(8);
}

int CMapping::GetCount()
{
	return count;
}

void CMapping::keys(CVector & v)
{
	int j = table_size;
	mapping_node_t *elt, **a = table;
		
	do {
	    for (elt = a[j]; elt; elt = elt->next)
		{
			if( (elt->values)->type == T_STRING)
				v.append((elt->values)->u.string);
		}
	} while (j--);	
}

void CMapping::values(CVector & v)
{
	int j = table_size;
	mapping_node_t *elt, **a = table;
		
	do {
	    for (elt = a[j]; elt; elt = elt->next)
		{
			if( (elt->values + 1)->type == T_STRING)
				v.append((elt->values + 1)->u.string);
		}
	} while (j--);	
}

int CMapping::undefinedp(const char * key)
{
	const char * subkey;
	CMapping * map = this;

	if(! key)
	{
		output_error("error: CMapping::undefinedp(const char * key) key is 0!");
		return 1;
	}

	if(! key[0])
	{
		output_error("error: CMapping::undefinedp(const char * key) key is ""!");
		return 1;
	}
	
	do
	{
		if(! (map = map->get_master_map(key, &subkey, 0, "undefinedp")) )
			return 1;

	} while(subkey && (key = subkey) );

	svalue_t * nvalue = map->find_string_in_mapping(key);
	return nvalue == &const0u;		
}

long CMapping::add(const char * key, long nValue)
{
	const char * subkey;
	CMapping * map = this;

	if(! key)
	{
		output_error("error: CMapping::add(const char * key, long nValue) key is 0!");
		return 0;
	}

	if(! key[0])
	{
		output_error("error: CMapping::add(const char * key, long nValue) key is null!");
		return 0;
	}
	
	do
	{
		map = map->get_master_map(key, &subkey, 1, "add");			

	} while(subkey && (key = subkey) );

	svalue_t * nvalue = map->find_string_in_mapping(key);
	if(nvalue != &const0u && nvalue->type == T_NUMBER)
	{
		nvalue->u.number+= nValue;
		return nvalue->u.number;
	}
	
	svalue_t * s;
	if(nvalue != &const0u)
	{
		s = nvalue;
		free_svalue(s);
	}
	else
		s = map->insert_in_mapping(key);

    s->type = T_NUMBER;
    s->u.number = nValue;

	return nValue;
}

CVector * CMapping::add(const char * key, CVector & value)
{
	CVector * v = queryvec(key);
	if(! v) 
	{
		set(key, value);
		return queryvec(key);
	}
	else
	{
		for(int i=0; i<value.count(); i++)
			v->append(value[i]);
	}

	return v;
}
