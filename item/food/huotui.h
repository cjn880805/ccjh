//huotui.h

//Sample for ITEM ĞûÍş»ğÍÈ
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIhuotui);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ĞûÍş»ğÍÈ");	//set item name

	set_weight(280);
	
	set("long", "ÕâÊÇÒ»¿éÓÃÃÛ½¤Á«×ÓÖó¹ı£¬Á÷×ÅºìÓÍµÄÏãÅçÅçµÄĞûÍş»ğÍÈ¡£");
	set("unit", "¿é");
	set("value", 200);
	set("food_remaining", 10);
	set("food_supply", 30);
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp