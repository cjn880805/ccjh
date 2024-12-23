//geng.h

//Sample for ITEM ¹ğ»¨ÏÊÀõ¸ş
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIgeng);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "¹ğ»¨ÏÊÀõ¸ş");	//set item name

	set_weight(80);
	
	set("long", "Ò»ÍëÏãÆøğ¥ÓôµÄ¹ğ»¨ÏÊÀõ¸ş¡£");
	set("unit", "Íë");
	set("value", 120);
	set("food_remaining", 3);
	set("food_supply", 50);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp