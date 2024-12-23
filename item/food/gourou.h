//gourou.h

//Sample for ITEM π∑»‚
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIgourou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "π∑»‚");	//set item name

	set_weight(90);
	
	set("long", "“ªøÈœ„≈Á≈Áµƒπ∑»‚°£");
	set("unit", "øÈ");
	set("value", 100);
	set("food_remaining", 5);
	set("food_supply", 40);
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp