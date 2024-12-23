//yancao.h

//Sample for ITEM 上等烟草
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIyancao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "上等烟草");	//set item name

	set_weight(800);
 
	set("unit", "包");
	set("value", 1000);
	set("material", "leather");           
 };

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp