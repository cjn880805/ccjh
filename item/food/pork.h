//pork.h

//Sample for ITEM 东坡肉
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIpork);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "东坡肉");	//set item name

	set_weight(1000);
	
	set("long", "一碗香喷喷的东坡肉，用文火煨肥猪肉而成，苏东坡在牧守杭州时看到民间吃肉而烧制不得法，遗惠此法至千年以下。");
	set("unit", "碗");
	set("value", 120);
	set("food_remaining", 10);
	set("food_supply", 100);
 	
};


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp