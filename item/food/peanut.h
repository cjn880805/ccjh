//peanut.h

//Sample for ITEM 五香花生
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIpeanut);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "五香花生");	//set item name

	set_weight(60);
	
	set("long", "一碟香喷喷的花生米。");
	set("unit", "碟");
	set("value", 30);
	set("food_remaining", 1);
	set("food_supply", 30);
 	
};


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp