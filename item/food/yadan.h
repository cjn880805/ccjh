//yadan.h

//Sample for ITEM ≥Ù—ºµ∞
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIyadan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "≥Ù—ºµ∞");	//set item name

	set_weight(70);

	set("long", "≥Ù—ºµ∞Œ≈◊≈≥Ù£¨≥‘◊≈œ„°£");
	set("unit", "ø≈");
	set("value", 80);
	set("food_remaining", 1);
	set("food_supply", 80);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp