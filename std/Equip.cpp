// Equip.cpp: implementation of the CEquip class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Equip.h"

/*
	对于又能吃又能装备的物品，我们可以把它先继承吃类，加上wield()私有函数，
	重载Do_Action，并指向其自己的wield()函数。另外还要重载Query(CAN_EQUIP)和
	Query(EQUIPPED)函数。使之可以装备。

	对于又能split，又能装备之物品，也这样处理。
*/
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEquip::CEquip()
{
	
}

CEquip::~CEquip()
{

}

int CEquip::Can_Equip(CChar * me)
{
	if(query("female_only")
		&&   EQUALSTR(me->querystr("gender"), "男性"))
		return 0;

	if(me->query("level") < query("equip_lvl"))		//等级限制
		return 0;

	if(! querymap("apply"))	//只有装备后加属性的才能装备
		return 0;

	return 1;
}

//装备
int CEquip::Do_Wield()
{
	CChar * owner;
	CChar::DTEquipList * list;
	LONG nPos, nPos2 = -1;
//   mapping armor_prop, applied_prop;
  // string *apply, type;

   
	if( ! environment()->Query(CChar::IS_CHAR) ) return 0;
	
	owner = (CChar *)environment();
	// If already worn, just recognize it.
	if( query("equipped") ) return 0;			//已经装备了

	//装备位置
	nPos = query("wield_position");	
	if(nPos == WIELD_NONE) return 0;		//没有装备位置
	
	if( nPos == WIELD_HAND ) { nPos = WIELD_LEFT_HAND; nPos2 = WIELD_RIGHT_HAND;}
	if( nPos == WIELD_ERR) { nPos = WIELD_LEFT_ERR; nPos2 = WIELD_RIGHT_ERR;}
	if( nPos == WIELD_WRIST) { nPos = WIELD_LEFT_WRIST; nPos2 = WIELD_RIGHT_WRIST;}
	
	if( nPos2 != -1 )
	{
		if( ! owner->Query_Equip(nPos2) )	//为空，可以装备
			nPos = nPos2;
	}

	if(nPos == WIELD_BOTH_HAND )	//双手武器，要检查左右手
	{
		if( owner->Query_Equip(WIELD_LEFT_HAND)
			|| owner->Query_Equip(WIELD_RIGHT_HAND))
			return 0;
	}
	else if(nPos == WIELD_LEFT_HAND || nPos == WIELD_RIGHT_HAND)
	{
		if( owner->Query_Equip(WIELD_BOTH_HAND))
			return 0;
	}

	if( owner->Query_Equip(nPos) ) return 0;
		
	//可以装备到nPos上
    list = owner->Get_EquipList();
    (* list)[nPos] = object_id();

	CMapping * m;
	char key[80];
	m = querymap("apply");
	
	if(m)		
	{
		//修正数值属性
		CVector v;

		m->keys(v);

		for(int i=0; i<v.count(); i++)
		{
			CMapping::svalue_t * sv;
			sv = m->find_string_in_mapping(v[i]);

			if(sv->type == T_NUMBER)
				owner->add_temp(snprintf(key, 80, "apply/%s", v[i]), sv->u.number);
			else
				owner->set_temp(snprintf(key, 80, "apply/%s", v[i]), sv->u.string);
		}
	}
	
	set("equipped", nPos);	//装备位置

 	return 1;
}

//卸下装备
int CEquip::Do_UnWield()
{
	CChar *	owner;
	CChar::DTEquipList * list;

	if( ! environment()->Query(CChar::IS_CHAR) ) return 0;
	if( ! query("equipped") )  return 0;		//并未装备

	owner = (CChar *)environment();

	//去掉角色装备
	list = owner->Get_EquipList();
	for(CChar::iterator_equip p = list->begin(); p != list->end(); p++)
	{
		if(p->second == object_id())
		{
			list->erase(p);
			break;
		}
	}

	//去掉修正
	CMapping * m = querymap("apply");
	char key[80];
	
	if(m)		
	{
		//修正数值属性
		CVector v;

		m->keys(v);

		for(int i=0; i<v.count(); i++)
		{
			CMapping::svalue_t * sv;
			sv = m->find_string_in_mapping(v[i]);

			if(sv->type == T_NUMBER)
				owner->add_temp(snprintf(key, 80, "apply/%s", v[i]), - sv->u.number);
			else if(sv->type == T_STRING)
				owner->delete_temp(snprintf(key, 80, "apply/%s", v[i]) );
		}
	}

	del("equipped");
      
	return 1;
}

LONG CEquip::Query(int nAttr)
{
	switch(nAttr)
	{
	case CAN_EQUIPPED:
		{
			CContainer * me;

			if(! (me = environment()) || ! me->Query(IS_CHAR))
				return 0;	//非角色不能装备
			return Can_Equip((CChar *)me);
		}
	case IS_EQUIP:
		return 1;
	}

	return CItem::Query(nAttr);
}

//设置装备修正值
int CEquip::Do_Action(int nAct, CChar * me)
{
	//判断有否主人
	if(! environment())
	{
		char tmp[255];
		snprintf(tmp, 255, "%s执行装备失败。重量：%ld，无环境。\n", name(), Query_Weight());
		output_error(tmp);
		return 0;
	}

	if(nAct == DO_WIELD && Query(CAN_EQUIPPED)) 
		return Do_Wield();
	
	if(nAct == DO_UNWIELD) return Do_UnWield();

	return CItem::Do_Action(nAct, me);
}




