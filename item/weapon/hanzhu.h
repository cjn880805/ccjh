//hanzhu.h

//Sample for ITEM: ��˿����
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIhanzhu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��˿����");	//set item name

//	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
//	set("skill_type", "base_sword");			//set the skill applied
	set_weight(3000);		//set item weight

	set("unit", "��");
	set("long","����һ����˿����ͨ�徧Ө΢΢�����̹⾧Ө��͸������ˮ��\n��ɵģ�����������������ƺ�����������ľ��ò��ϡ�");
	set("value", 0l);
	set("material", "bamboo");

};

virtual void owner_is_killed(CChar * killer)
{
	destruct(this);
}
/*************************
//yuzhu.c
inherit ITEM;
#include <ansi.h>
virtual void create()
{
        set_name(HIG"��˿����"NOR, ({ "han zhu","zhu"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����˿����ͨ�徧Ө΢΢�����̹⾧Ө��͸������ˮ��\n��ɵģ�����������������ƺ�����������ľ��ò��ϡ�\n");
                set("value", 0l);
                set("material", "bamboo");
              }
}
void owner_is_killed()
{
        destruct(this_object());
}
*************************************/
  
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp