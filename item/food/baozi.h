//baozi.h

//Sample for ITEM 包子
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIbaozi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "包子");	//set item name

	set_weight(2000);
	
	set("long", "一个香喷喷的肉包子。");
	set("unit", "个");
	set("value", 50);
	set("food_remaining", 3);
	set("food_supply", 20);
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



