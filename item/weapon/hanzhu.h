//hanzhu.h

//Sample for ITEM: 寒丝羽竹
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIhanzhu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "寒丝羽竹");	//set item name

//	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
//	set("skill_type", "base_sword");			//set the skill applied
	set_weight(3000);		//set item weight

	set("unit", "根");
	set("long","这是一根寒丝羽竹，通体晶莹微微泛着绿光晶莹剔透竟似用水晶\n雕成的，拿在手中轻若无物，似乎是制造兵器的绝好材料。");
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
        set_name(HIG"寒丝羽竹"NOR, ({ "han zhu","zhu"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long","这是一根寒丝羽竹，通体晶莹微微泛着绿光晶莹剔透竟似用水晶\n雕成的，拿在手中轻若无物，似乎是制造兵器的绝好材料。\n");
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