//huotui2.h

//Sample for ITEM Ó£ÌÒ»ğÍÈ
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIhuotui2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ó£ÌÒ»ğÍÈ");	//set item name

	set("long", "Ò»ÅèÏãÅçÅçÈÈÆøÌÚÌÚµÄÓ£ÌÒ»ğÍÈ¡£");
	set("unit", "Åè");
	set("value", 200);
	set("food_remaining", 10);
	set("food_supply", 20);
	set("material", "meat");
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp