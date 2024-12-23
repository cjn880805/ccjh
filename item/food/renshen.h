//renshen.h

//Sample for ITEM 人参
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIrenshen);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "人参");	//set item name

	set_weight(700);

	set("unit", "棵");
	set("long", "这是一棵初具人形的老山参。");
	set("value", 10000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	me->add("max_mp", 3);
	message_vision("$N吃下一棵老山参，顿时间觉得全身充满了活力 !", me);
	destruct(this);
	return 1;

}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp