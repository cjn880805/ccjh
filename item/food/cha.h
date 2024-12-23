//cha.h

//Sample for ITEM 醉仙茶
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIcha);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "醉仙茶");	//set item name

	set_weight(1000);

	set("long","这是一杯颜色碧绿、香味浓郁上等好茶。是招待桃花岛来客的!");
	set("unit", "杯");
	set("value", 20);
	set("max_liquid", 10);
	set("liquid/name","醉仙茶" );
	set("liquid/remaining",8 );
	set("liquid/type", "water");
  
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp