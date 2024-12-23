//mitao.h

//Sample for ITEM 水蜜桃
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CImitao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "水蜜桃");	//set item name

	set_weight(40);

	set("long", "一碟水灵新鲜的水蜜桃，跟小翠的脸蛋儿一样红艳可人。");
	set("unit", "碟");
	set("value", 80);
	set("food_remaining", 4);
	set("food_supply", 300);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp