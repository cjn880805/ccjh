//giftbox.h

//Sample for ITEM ��Ʒ��
//coded by Fisho
//data: 2000-11-25

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIgiftbox);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��Ʒ��");	//set item name
	
	set_weight(500);
	set("unit", "��");
	set("long", "һ����Ʒ�С�����װ����ʦ���������������֣���");
	set("value", 0l);
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp
/****************************
// giftbox.c ��Ʒ��

inherit ITEM;
#include <ansi.h>;
virtual void create()
{
        set_name(HIR"��Ʒ��"NOR, ({ "giftbox", "box" }));
        set_weight(500);
        set_max_encumbrance(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����Ʒ�С�����װ����ʦ���������\n\n    "HIR"������֣���\n\n"NOR);
                set("value", 0l);
        }
}

int is_container() { return 1; }
***************************/
