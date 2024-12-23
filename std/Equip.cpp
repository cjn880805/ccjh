// Equip.cpp: implementation of the CEquip class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Equip.h"

/*
	�������ܳ�����װ������Ʒ�����ǿ��԰����ȼ̳г��࣬����wield()˽�к�����
	����Do_Action����ָ�����Լ���wield()���������⻹Ҫ����Query(CAN_EQUIP)��
	Query(EQUIPPED)������ʹ֮����װ����

	��������split������װ��֮��Ʒ��Ҳ��������
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
		&&   EQUALSTR(me->querystr("gender"), "����"))
		return 0;

	if(me->query("level") < query("equip_lvl"))		//�ȼ�����
		return 0;

	if(! querymap("apply"))	//ֻ��װ��������ԵĲ���װ��
		return 0;

	return 1;
}

//װ��
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
	if( query("equipped") ) return 0;			//�Ѿ�װ����

	//װ��λ��
	nPos = query("wield_position");	
	if(nPos == WIELD_NONE) return 0;		//û��װ��λ��
	
	if( nPos == WIELD_HAND ) { nPos = WIELD_LEFT_HAND; nPos2 = WIELD_RIGHT_HAND;}
	if( nPos == WIELD_ERR) { nPos = WIELD_LEFT_ERR; nPos2 = WIELD_RIGHT_ERR;}
	if( nPos == WIELD_WRIST) { nPos = WIELD_LEFT_WRIST; nPos2 = WIELD_RIGHT_WRIST;}
	
	if( nPos2 != -1 )
	{
		if( ! owner->Query_Equip(nPos2) )	//Ϊ�գ�����װ��
			nPos = nPos2;
	}

	if(nPos == WIELD_BOTH_HAND )	//˫��������Ҫ���������
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
		
	//����װ����nPos��
    list = owner->Get_EquipList();
    (* list)[nPos] = object_id();

	CMapping * m;
	char key[80];
	m = querymap("apply");
	
	if(m)		
	{
		//������ֵ����
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
	
	set("equipped", nPos);	//װ��λ��

 	return 1;
}

//ж��װ��
int CEquip::Do_UnWield()
{
	CChar *	owner;
	CChar::DTEquipList * list;

	if( ! environment()->Query(CChar::IS_CHAR) ) return 0;
	if( ! query("equipped") )  return 0;		//��δװ��

	owner = (CChar *)environment();

	//ȥ����ɫװ��
	list = owner->Get_EquipList();
	for(CChar::iterator_equip p = list->begin(); p != list->end(); p++)
	{
		if(p->second == object_id())
		{
			list->erase(p);
			break;
		}
	}

	//ȥ������
	CMapping * m = querymap("apply");
	char key[80];
	
	if(m)		
	{
		//������ֵ����
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
				return 0;	//�ǽ�ɫ����װ��
			return Can_Equip((CChar *)me);
		}
	case IS_EQUIP:
		return 1;
	}

	return CItem::Query(nAttr);
}

//����װ������ֵ
int CEquip::Do_Action(int nAct, CChar * me)
{
	//�ж��з�����
	if(! environment())
	{
		char tmp[255];
		snprintf(tmp, 255, "%sִ��װ��ʧ�ܡ�������%ld���޻�����\n", name(), Query_Weight());
		output_error(tmp);
		return 0;
	}

	if(nAct == DO_WIELD && Query(CAN_EQUIPPED)) 
		return Do_Wield();
	
	if(nAct == DO_UNWIELD) return Do_UnWield();

	return CItem::Do_Action(nAct, me);
}




