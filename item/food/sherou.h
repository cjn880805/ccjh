//sherou.h

//Sample for ITEM …ﬂ»‚
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIsherou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "…ﬂ»‚");	//set item name

	set_weight(350);

	set("long", "“ªÃı…’øæµ√œ„≈Á≈Áµƒ…ﬂ»‚°£");
	set("unit", "Ãı");
	set("value", 50);
	set("food_remaining", 3);
	set("food_supply", 20);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp