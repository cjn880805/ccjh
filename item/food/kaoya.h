//kaoya.h

//Sample for ITEM 烤鸭
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIkaoya);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "烤鸭");	//set item name

	set_weight(200);

	set("long", "一只肥得流油的北京烤鸭。");
	set("unit", "只");
	set("value", 150);
	set("food_remaining", 3);
	set("food_supply", 60);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp