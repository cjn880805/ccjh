// Item.cpp: implementation of the CItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Globle.h"
#include "Item.h"
#include "Container.h"
#include "Room.h"
#include "Channel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CItem::CItem()
{
	m_lAmount = 1;
}

CItem::~CItem()
{
	
}

//�ֿ�������
CItem * CItem::Split(LONG nAmount)
{
	CItem * t;
	LONG nLeft = m_lAmount - nAmount;
	
	if(nAmount <=0 || nLeft <0 ) return 0;	//�ֲ�����
	if(nLeft == 0) return this;

	set_amount(nLeft);
	t = (CItem *)load_item(querystr("base_name"));
	if(t) 
	{
		if(query("index"))
			t->create(query("index"));
		t->set_amount(nAmount);
	}

	return t;
}

//������Ʒ�ϲ�
int CItem::Combine(CItem *obj)
{
	if(DIFFERSTR(obj->querystr("base_name"), querystr("base_name")) ) return 0;	//����ͬ����Ʒ���ܺϲ���
	
	m_lAmount += obj->Query_Amount();
	DESTRUCT_OB(obj, "CItem::Combine");

	return 1;
}

int CItem::Can_Use()
{
	return 0;
}

LONG CItem::Query(int nAttr)
{
	switch(nAttr)
	{
	case IS_ITEM: return 1;
	case CAN_GET: 
		{
			if(_M.undefinedp("no_get"))
				return 1;
			return 0;
		}
	case CAN_USE: return Can_Use();
	}

	return CContainer::Query(nAttr);
}

int CItem::do_use(CChar * me, CContainer * target)
{
	return 0;
}

//��Ϊ
int CItem::Do_Action(int nAct, CChar *me)
{
	if(! me)
	{
		if(! environment() || ! environment()->Query(IS_CHAR))
			return 0;
		me = (CChar *)environment();
	}
	
	return CContainer::Do_Action(nAct, me);
}

LONG CItem::Query_Amount()
{
	return m_lAmount;
}

void CItem::set_amount(LONG nAmount)
{
	if( nAmount < 0 )
	{
		m_lAmount = 0;	//������Ϣ
	}

	if( nAmount == 0 ) 
	{
		m_lAmount = 0;
		//��������
		DESTRUCT_OB(this, "CItem::set_amount");
		return;
	}
	else
	{
		m_lAmount = nAmount;
		if(query("base_weight"))
			set_weight( nAmount * query("base_weight") );
		if(query("base_value"))
			set("value", nAmount * query("base_value") );
	}

	UpdateMe();
}

LONG CItem::add_amount(LONG val)
{
	set_amount(m_lAmount + val);
	return m_lAmount + val;
}

int CItem::do_look(CChar *me)
{
	char msg[255];
	DTItemList * list;
	POSITION p;
	CContainer * item;

	//1,�ȴ�����
	say(snprintf(msg, 255, "%s %s", Short(), Long()), me);

    list = Get_ItemList();
	p = list->GetHeadPosition();
	if(list->GetCount() && ( DIFFERSTR(querystr("status"), "locked") || wizardp(me) ))
	{
		AddMenuItem("�����У�", "", me);
		while(p)
		{
			item = list->GetNext(p);
			AddMenuItem(item->name(), 
			snprintf(msg, 80, "$0get %ld from $1", item->object_id()), me);
		}			
    }			

    return 0;
}

LONG CItem::receive_damage(const char * szType, LONG nDamage)
{
	int val;

	if( nDamage <= 0 ) return 0;
	if( DIFFERSTR(szType, "dp")) return 0;
	
	val = query(szType) - nDamage;

	if( val > 0 ) 
		set(szType, val);
	else
	{
		set(szType, 0l);
		call_out(destruct_me, 1);
	}	

	return nDamage;
}

LONG CItem::receive_wound(const char * type, LONG damage)
{
	LONG val;
	char eff_key[40];
	
	if( damage <= 0 ) return 0;
	if( DIFFERSTR(type, "dp") ) return 0;

	snprintf(eff_key, 40, "eff_%s", type);
	
	val = query(eff_key) - damage;

	if( val > 0 ) set(eff_key, val);
	else 
	{
		set(eff_key, 0l);
		call_out(destruct_me, 1);
	}
    
	if( query(type) > val ) set(type, val);
	return damage;	
}

void CItem::destruct_me(CContainer * ob, LONG param1, LONG param2)
{
	const char * msg = ob->querystr("destruct_msg");
	if(msg[0] && ob->environment()) 
		tell_object(ob->environment(), msg);

	DESTRUCT_OB(ob, "CItem::destruct_me");
}

//���ƶ���������ʱ����
void CItem::init()
{
//	char msg[255] ;
//	if( environment()) 
//		tell_object(environment(), snprintf(msg, 255, "$HIC%s(%s)��%d��$COM",  querystr("base_name"),id(1),Query_Amount()));
	if(Query_Amount()>1)
		{
			if(EQUALSTR(querystr("base_name"),"coin" )||EQUALSTR(querystr("base_name"),"baiyupi" )
				||EQUALSTR(querystr("base_name"),"yupian" )||EQUALSTR(querystr("base_name"),"tiedan" )
				||EQUALSTR(querystr("base_name"),"tea_leaf" )||EQUALSTR(querystr("base_name"),"tielianzi" )
				||EQUALSTR(querystr("base_name"),"zhuyebiao" )||EQUALSTR(querystr("base_name"),"zimuzhen" )
				||EQUALSTR(querystr("base_name"),"gangbiao" )||EQUALSTR(querystr("base_name"),"flower_leaf" )
				||EQUALSTR(querystr("base_name"),"feihuangshi" )||EQUALSTR(querystr("base_name"),"arrow" )
				||EQUALSTR(querystr("base_name"),"huicheng_juanzhou" )||EQUALSTR(querystr("base_name"),"fengyin" )
				||EQUALSTR(querystr("base_name"),"jili" )||EQUALSTR(querystr("base_name"),"mofa_shoukao" )
				||EQUALSTR(querystr("base_name"),"yueping" )||EQUALSTR(querystr("base_name"),"tradepro_item" )
				||EQUALSTR(querystr("base_name"),"kuihuazhen" ))
			{
				set("weight",Query_Weight()); 
				if(Query_Weight()<1000) 
					set_weight(1000);
			}
			else
			{
				if(userp(environment()))
					{
						char msg[255] ;
						environment()->move(load_room("jy"));
						g_Channel.do_channel(this, NULL, "news", snprintf(msg, 255,"$HIR%s(%s)�����Ӹ��ƶ������������д����һ�ܡ�",environment()->name(1),environment()->id(1)));
						output_error("%s(%s)ӵ�и��Ƶ���%s%d��.", environment()->name(1),environment()->id(1),this->name(1),Query_Weight());

					}
//					tell_object(environment(), snprintf(msg, 255, "%s����$HIC%s(%s)��%d��$COM",  environment()->name(1),querystr("base_name"),id(1),Query_Amount()));
					set("��Ŀ",Query_Weight());
					set("������",environment()->id(1));
					set_amount(1);
					move(load_room("pk"));
//					move(environment());
			}
		}
		else
			{
				set("weight",Query_Weight()); 
				if(Query_Weight()<1000) 
					set_weight(1000);
			}
}
