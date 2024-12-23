//xiaren2.h

//Sample for ITEM Áâ°×ÏºÈÊ
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxiaren2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Áâ°×ÏºÈÊ");	//set item name

	set("long", "Ò»ÅèÏãÅçÅçÈÈÆøÌÚÌÚµÄÁâ°×ÏºÈÊ¡£");
	set("unit", "Åè");
	set("value", 180);
	set("food_remaining", 8);
	set("food_supply", 20);
	set("material", "meat");
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp