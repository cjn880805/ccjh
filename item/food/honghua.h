//honghua.h

//Sample for ITEM 无忧红花
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIhonghua);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "无忧红花");	//set item name

	set_weight(5);
	
	set("unit", "朵");
	set("prep", "on");
	set("long", "一朵鲜红的花。");
	set("value", 1);
	set("max_encumbrance", 80);
};
/**********************
      
**********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp