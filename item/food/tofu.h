//tofu.h

//Sample for ITEM 翡翠豆腐
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CItofu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "翡翠豆腐");	//set item name

	set_weight(1000);
	
	set("long", "一块水灵灵的大豆腐，嫩的令人不禁想到阿庆嫂的脸蛋儿。");
	set("unit", "块");
	set("value", 40);
	set("food_remaining", 1);
	set("food_supply", 50);
 	
};


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



