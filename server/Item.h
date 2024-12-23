// Item.h: interface for the CItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ITEM_H__DB7CBEE2_64B9_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_ITEM_H__DB7CBEE2_64B9_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Char.h"

#define ITEM_BEGIN(item_name)	class item_name : public CItem	{	public:		item_name(){};	virtual ~item_name(){};	
#define ITEM_END		};	

//物品基类

class CItem : public CContainer
{
public:
	virtual void init();
	static void destruct_me(CContainer * ob, LONG param1, LONG param2);

	LONG receive_wound(const char * type, LONG damage);
	LONG receive_damage(const char * szType, LONG nDamage);
	virtual int do_look(CChar * me);
	LONG add_amount(LONG val);
	virtual void set_amount(LONG nAmount);
	virtual LONG Query_Amount();
	int Combine(CItem *obj);
	CItem * Split(LONG nAmount);
	virtual int Do_Action(int nAct, CChar * me = NULL);
	virtual  LONG Query(int nAttr);

	virtual int do_use(CChar * me, CContainer * target);
	virtual int Can_Use();

	CItem();
	virtual ~CItem();

	enum{
		picture_default = 0,
		common_object,
		corpse_object,
		fight_object,
	};

protected:
	LONG	m_lAmount;

};

#endif // !defined(AFX_ITEM_H__DB7CBEE2_64B9_11D4_98AB_0050BABC5212__INCLUDED_)
