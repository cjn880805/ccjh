//soup2.h

//Sample for ITEM ºÉÒ¶¶¬ËñÌÀ
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIsoup2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ºÉÒ¶¶¬ËñÌÀ");	//set item name

	set_weight(50);

	set("long", "Ò»ÍëÏãÆøÆË±ÇµÄºÉÒ¶¶¬ËñÌÀ¡£");
	set("unit", "Íë");
	set("value", 150);
	set("max_liquid", 4);
	set("liquid/type", "water" );
    set("liquid/name", "ºÉÒ¶¶¬ËñÌÀ" );
    set("liquid/remaining", 12 );
    set("liquid/drunk_supply",  20);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp