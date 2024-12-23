//fish.h

//Sample for ITEM 西湖醋鱼
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIfish);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "西湖醋鱼");	//set item name

	set_weight(1300);
	
	set("long", "一盘清甜可人的西湖醋鱼，用西湖中的金色鲤鱼烧制而成，是西湖第一名菜。");
	set("unit", "碗");
	set("value", 120);
	set("food_remaining", 20);
	set("food_supply", 20);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp