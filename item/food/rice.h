//rice.h

//Sample for ITEM »ÆÃ×·¹
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIrice);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "»ÆÃ×·¹");	//set item name

	set_weight(80);

	set("long", "Ò»¸öÍëÏãÅçÅç»ÆÃ×·¹¡£");
	set("unit", "Íë");
	set("value", 80);
	set("food_remaining", 4);
	set("food_supply", 50);
	set("material", "rice");
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp