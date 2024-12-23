//jiaohuaji.h

//Sample for ITEM 叫化鸡
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIjiaohuaji);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "叫化鸡");	//set item name

	set_weight(300);
	
	set("long", "一只烤得香喷喷的叫化鸡.");
	set("unit", "只");
	set("value", 2000);
	set("food_remaining", 3);
	set("food_supply", 70);
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp