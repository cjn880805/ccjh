//soup.h

//Sample for ITEM Ò°²ËÌÀÍë
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIsoup);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ò°²ËÌÀÍë");	//set item name

	set_weight(50);

	set("long", "Ò»ÍëĞÂÏÊÒ°²Ë×öµÄÌÀ¡£");
	set("unit", "Íë");
	set("value", 80);
	set("max_liquid", 4);
    set("liquid/type", "water" );
    set("liquid/name", "Ò°²ËÌÀ" );
    set("liquid/remaining", 6 );
    set("liquid/drunk_supply",  20);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp