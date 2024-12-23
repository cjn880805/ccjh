//mixian.h

//Sample for ITEM 过桥米线
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CImixian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "过桥米线");	//set item name

	set_weight(2000);

	set("long", "这是一碗热气腾腾的油浸的米粉，正是大理名菜过桥米线。");
	set("unit", "碗");
	set("value", 80);
	set("food_remaining", 10);
	set("food_supply", 20);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



