// Object.h: interface for the CObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJECT_H__728B95E0_63E8_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_OBJECT_H__728B95E0_63E8_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//Base Object Model
#define FALSE		0
#define TRUE		1

#include "../combat/MudConfig.h"

#ifdef _NTOS_
#include "afxtempl.h"
#else
#include "../list/list.h"
#endif

#include "Mapping2.h"

class CMudObject  
{
public:
	const char * id(int flag = 0 )
	{
		const char * mid = _T.querystr("apply/id");
		if(flag || ! mid[0])
		{
			return querystr("id");
		}
		
		return mid;	
	}

	const char * name(int flag = 0)
	{
		const char * mname = _T.querystr("apply/name");
		if(flag || ! mname[0])
		{
			return querystr("name");
		}
		
		return mname;	
	}
	
	void set_name(const char * name, const char * id = 0)
	{
		if(name)
		{
			//strncpy(m_szName, name, 40)[39] = 0;
			_M.set("name", name);	//不能 用name 因为 name不稳定

		}

		if(id)
		{
			//strncpy(m_szID, id, 40)[39] = 0;
			_M.set("id", id);
		}
		else
		{
			if(_M.undefinedp("id"))
			{
				_M.set("id", _M.querystr("base_name"));
			}
		}
	}

	void set(const char * key, LONG nValue)
	{			
		_M.set(key, nValue); 
	}

	void set(const char * key, const char * value)
	{  _M.set(key, value); }

	void set(const char * key, CMapping & value)
	{ _M.set(key, value); }

	void set(const char * key, CVector & value)
	{ _M.set(key, value); }

	LONG query(const char * key)
	{ return _M.query(key); }

	const char * querystr(const char * key)
	{ return _M.querystr(key);	}

	CMapping * querymap(const char * key)
	{ return _M.querymap(key); }

	CVector * queryvec(const char * key)
	{ return _M.queryvec(key); }

	LONG add(const char * key, LONG nValue)
	{ return _M.add(key, nValue); }

	void del(const char * key)
	{ _M.del(key); }

	void set_temp(const char * key, const char * value)
	{ _T.set(key, value); }

	void set_temp(const char * key, LONG value)
	{ _T.set(key, value); }

	void set_temp(const char * key, CMapping & value)
	{ _T.set(key, value); }

	void set_temp(const char * key, CVector & value)
	{ _T.set(key, value); }

	const char * querystr_temp(const char * key)
	{ return _T.querystr(key); }

	LONG query_temp(const char * key)
	{ return _T.query(key); }

	CMapping * querymap_temp(const char * key)
	{ return _T.querymap(key); }

	CVector * queryvec_temp(const char * key)
	{ return _T.queryvec(key); }

	LONG add_temp(const char * key, LONG nValue)
	{ return _T.add(key, nValue); }

	void delete_temp(const char * key)
	{ _T.del(key); }

	virtual  LONG Query(int nAttr)
	{ return 0; }

	CMudObject()
	{ 
	};

	virtual ~CMudObject()
	{};

	//Attribute
	enum {
		IS_SKILL,
		CAN_CAST_IN_COMBAT,
		CAN_CAST_IN_COMMON,
				
		//Item		
		IS_ITEM,
		IS_FIGHTROOM,
		IS_CORPSE,
		CAN_USE,
		CAN_GET,
		CAN_EQUIPPED,
		CAN_SAVE,
		UPDATE,				//版本更新标记
					
		//Equip
		IS_EQUIP,
						
		//Combined
		IS_COMBINED,
		IS_MONEY,		//是否钱
		
		//NPC
		IS_NPC,
		IS_VENDOR,
		IS_SPRITE,
		
		//Container
		IS_CONTAINER,
		INFINITY,				//不受容量限制
			
		//Room
		IS_ROOM,
		//User
		IS_USER,
		
		//Char
		IS_CHAR, 
		IS_LIVING,
		IS_BUSY,
		IS_BANKER,
			
		//-----Info
		
		//Query--------------------------------------------------------
		
		//EXIT & DOOR
		IS_BOX,
		IS_RESIDENT,
		PERFORM,
		IS_MONSTER,
		
	};

/*
	//Race
	enum{
		HUMAN,				//人类
		ELF,				//精灵
		DWARF,				//矮人
		DWELLER,			//穴居人
		WRAITH,				//死灵
		DARKELF,			//黑暗精灵
	};
*/

	//GRANT
	enum{
		GRANT_NPC = 10,
		GRANT_PLAYER = 30,
		GRANT_WIZARD = 50,
		GRANT_ADMIN = 100
	};

protected:
	CMapping _M;
	CMapping _T;
};

#endif // !defined(AFX_OBJECT_H__728B95E0_63E8_11D4_98AB_0050BABC5212__INCLUDED_)


