//hamigua.h

//Sample for ITEM ¹şÃÜ¹Ï
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIhamigua);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "¹şÃÜ¹Ï");	//set item name

	set_weight(40);
   
	set("long", "Ò»¿ÅÏãÌğµÄ¹şÃÜ¹Ï¡£²»³Ô¹şÃÜ¹ÏµÈÓÚ°×À´Î÷Óò¡£");
	set("unit", "¿Å");
	set("value", 40);
	set("food_remaining", 1);
	set("food_supply", 50);
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp