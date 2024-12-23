//gao4.h

//Sample for ITEM 四色点心
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIgao4);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "四色点心");	//set item name

	set_weight(1500);
	
	set("long", "四色点心形状精雅,似乎是用来玩赏一般。");
	set("unit", "块");
	set("value", 50);
	set("food_remaining", 4);
	set("food_supply", 20);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp