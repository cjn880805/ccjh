//zongzi.h

//Sample for ITEM 粽子
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIzongzi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "粽子");	//set item name

	set_weight(1000);

	set("long", "一个香喷喷的肉粽子，包它的粽子叶泛出一股清香。");
	set("unit", "个");
	set("value", 100);
	set("food_remaining", 3);
	set("food_supply", 50);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



