//goupi.h

//Sample for ITEM: ¹·Æ¤
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIgoupi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "¹·Æ¤");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(5000);		//set item weight

	set("unit", "¿é");
	set("material", "fur");
	set("apply/per", 5);
	set("value", 300);
	set("apply/armor", 1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp