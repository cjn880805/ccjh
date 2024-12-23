//goldring.h

//Sample for ITEM: 金戒指
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIgoldring);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "金戒指");	//set item name

	set("wield_position", WIELD_ARMOR_HANDS);		//set the position of wield
 	set_weight(400);		//set item weight
	
	set("unit", "个");
	set("value", 2000);
	set("material", "gold");
	set("apply/per", 1);
	set("apply/armor", 1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp