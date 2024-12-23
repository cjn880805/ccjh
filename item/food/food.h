//food.h

//Sample for ITEM 食物
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIfood);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "食物");	//set item name

	set_weight(40);
	
	set("long", "还没定义，给下层调用。");
	set("unit", "盘");
	set("value", 40);
	set("no_get", "1");
	set("food_remaining", 5);
	set("food_supply", 15);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp