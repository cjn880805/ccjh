//fengmi.h

//Sample for ITEM ”Ò∑‰√€
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIfengmi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "”Ò∑‰√€");	//set item name

	set_weight(30000);
	
	set("long", "“ªπﬁ”Ò∑‰ƒ≥…µƒ√€°£");
	set("unit", "πﬁ");
	set("value", 20);
	set("max_liquid", 12);
	set("liquid/type", "fengmi");
	set("liquid/name", "∑‰√€");
	set("liquid/remaining",12 );
	set("liquid/drunk_supply", 9);
 
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp