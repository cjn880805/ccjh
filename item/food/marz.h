//marz.h

//Sample for ITEM 火星人
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CImarz);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "火星人");	//set item name

	set_weight(70);
              
	set("long", "火星人可以作为地球人的食品。");
	set("unit", "只");
	set("food_remaining", 19);
	set("food_supply",10 ); 

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp