//gunny_shoes.h

//Sample for ITEM: 麻鞋
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIgunny_shoes);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "麻鞋");	//set item name

	set("wield_position", WIELD_BOOT);		//set the position of wield
 	set_weight(500);		//set item weight
	
	set("unit", "双");
	set("long", "这是一双麻布鞋，不易大滑，供游人登山使用。");
	set("value", 150);
	set("material", "cloth");
	set("armor_type", "boots");
	set("apply/armor", 1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp