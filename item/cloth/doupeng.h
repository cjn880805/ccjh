//doupeng.h

//Sample for ITEM 斗篷
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIdoupeng);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "斗篷");	//set item name

	set("wield_position", WIELD_MANTLE);		//set the position of wield
 	set_weight(2000);		//set item weight

	set("long", "这是一件绿色宽大的斗篷。");
	set("material", "cloth");
	set("unit", "件");
	set("value", 200);
	set("apply/armor", 3);
	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp