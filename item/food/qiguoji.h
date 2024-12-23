//qiguoji.h

//Sample for ITEM Æû¹ø¼¦
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIqiguoji);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Æû¹ø¼¦");	//set item name

	set_weight(280); 

	set("long", "ÕâÊÇÒ»¹øÈÈÆøÌÚÌÚµÄÆû¹ø¼¦¡£");
	set("unit", "¹ø");
	set("value", 200);
	set("food_remaining", 10);
	set("food_supply", 40);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp