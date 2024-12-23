//lace.h

//Sample for ITEM: ±¥ø«œÓ¡¥
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIlace);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "±¥ø«œÓ¡¥");	//set item name

	set("wield_position", WIELD_NECK);		//set the position of wield
 	set_weight(500);		//set item weight
          
	set("unit", "¥Æ");
	set("value", 2500);
	set("apply/armor", 5);
    set("apply/per", 2);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp