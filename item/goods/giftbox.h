//giftbox.h

//Sample for ITEM 礼品盒
//coded by Fisho
//data: 2000-11-25

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIgiftbox);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "礼品盒");	//set item name
	
	set_weight(500);
	set("unit", "盒");
	set("long", "一盒礼品盒。盒里装着巫师的新年贺礼。新年快乐！！");
	set("value", 0l);
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp
/****************************
// giftbox.c 礼品盒

inherit ITEM;
#include <ansi.h>;
virtual void create()
{
        set_name(HIR"礼品盒"NOR, ({ "giftbox", "box" }));
        set_weight(500);
        set_max_encumbrance(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "盒");
                set("long", "一盒礼品盒。盒里装着巫师的新年贺礼。\n\n    "HIR"新年快乐！！\n\n"NOR);
                set("value", 0l);
        }
}

int is_container() { return 1; }
***************************/
