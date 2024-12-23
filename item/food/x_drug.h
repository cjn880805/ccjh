//x_drug.h

//Sample for ITEM 阴阳合和散
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIx_drug);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "阴阳合和散");	//set item name

	set_weight(80);

	set("long", "一种强烈的春药。");
	set("unit", "包");
	set("value", 0l);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp