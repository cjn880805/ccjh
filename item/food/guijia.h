//guijia.h

//Sample for ITEM 乌龟甲
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIguijia);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("乌龟甲", "guijia");	//set item name

	set_weight(800);
	
	set("unit", "块");
	set("long", "这是一块乌龟甲，上面有各种花纹，看来可以入药。");
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp