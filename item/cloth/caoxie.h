//caoxie.h

//Sample for ITEM: 草鞋
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIcaoxie);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "草鞋");	//set item name

	set("wield_position", WIELD_BOOT);		//set the position of wield
 	set_weight(200);		//set item weight

	set("material", "wood");
	set("unit", "双");
	set("long", "这是一双草编的草鞋，用以保护足部。");
	set("value", 100);
	set("apply/dodge", 2);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp