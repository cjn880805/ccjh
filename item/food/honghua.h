//honghua.h

//Sample for ITEM ���Ǻ컨
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIhonghua);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���Ǻ컨");	//set item name

	set_weight(5);
	
	set("unit", "��");
	set("prep", "on");
	set("long", "һ���ʺ�Ļ���");
	set("value", 1);
	set("max_encumbrance", 80);
};
/**********************
      
**********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp