//jiaohuaji.h

//Sample for ITEM �л���
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIjiaohuaji);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�л���");	//set item name

	set_weight(300);
	
	set("long", "һֻ����������Ľл���.");
	set("unit", "ֻ");
	set("value", 2000);
	set("food_remaining", 3);
	set("food_supply", 70);
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp