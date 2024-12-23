//furong_huagu.h

//Sample for ITEM ‹Ω»ÿª®πΩ
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIfurong_huagu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "‹Ω»ÿª®πΩ");	//set item name

	set_weight(200);

	set("long", "“ª≈ËÃ¿≥Ì÷≠≈®£¨Œ∂ª¨À¨ø⁄µƒ‹Ω»ÿª®πΩÃ¿°£");
	set("unit", "≈Ë");
	set("value", 150);
	set("food_remaining", 4);
	set("food_supply", 40);
	

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp