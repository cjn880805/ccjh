//mizhitianou.h

//Sample for ITEM ÃÜÖ­ÌğÅº
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CImizhitianou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ÃÜÖ­ÌğÅº");	//set item name

	set_weight(2000);

	set("long", "Ò»ÅèÏãÌğÈíÅ´£¬É«Ôó·ÛºìµÄÃÛÖ­ÌğÅº¡£");
	set("unit", "Åè");
	set("value", 150);
	set("food_remaining", 4);
	set("food_supply", 40);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



