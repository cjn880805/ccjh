//surcoat.h

//Sample for ITEM: 肚带
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIsurcoat);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "肚带");	//set item name

	//inherit SURCOAT;

	set("wield_position", WIELD_WAIST);		//set the position of wield
 	set_weight(500);		//set item weight

	set("material", "leather");
	set("unit", "条");
	set("long", "这是一件皮质的肚带，用以保护腹部。");
	set("value", 800);
	set("apply/dodge", -3);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp