//birddie.h

//Sample for ITEM ÄñÈâ
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIbirddie);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ÄñÈâ");	//set item name
	
	set_weight(40);
	
	set("long", "Ò»¿éÅçÏãµÄÄñÈâ£¬ÕæÈÃÈË×ì²ö¡£");
	set("unit", "¿é");
	set("value", 180);
	set("food_remaining", 5);
	set("food_supply", 50);
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp