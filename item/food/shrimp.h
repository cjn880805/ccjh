//shrimp.h

//Sample for ITEM Áú¾®ÏºÈÊ
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIshrimp);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Áú¾®ÏºÈÊ");	//set item name

	set_weight(1300);
	
	set("long", "õ¦õ¦Å¨Å¨µÄÒ»ÅÌÁú¾®ÏºÈÊ¡£");
	set("unit", "Íë");
	set("value", 50);
	set("food_remaining", 5);
	set("food_supply", 20);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp