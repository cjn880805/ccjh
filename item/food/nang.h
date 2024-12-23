//nang.h

//Sample for ITEM 馕
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CInang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "馕");	//set item name

	set_weight(80);

	set("long", "这是维吾尔族人日常吃的一种面饼.");
	set("unit", "个");
	set("value", 50);
	set("food_remaining", 3);
	set("food_supply", 50);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp