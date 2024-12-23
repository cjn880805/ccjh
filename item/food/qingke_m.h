//qingke_m.h

//Sample for ITEM 青稞面
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIqingke_m);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "青稞面");	//set item name

	set_weight(1000);
	set("long", "一盆别有风味的青稞面。"); 
	set("unit", "盆"); 
	set("value", 200); 
	set("food_remaining", 4); 
	set("food_supply", 60); 
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



