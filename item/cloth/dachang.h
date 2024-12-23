//dachang.h

//Sample for ITEM: 鸟羽大氅
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIdachang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "鸟羽大氅");	//set item name

	set("wield_position", WIELD_MANTLE);		//set the position of wield
 	set_weight(3000);		//set item weight
        set("value", 500);
	set("unit", "领");
	set("long", "一领用秃鹰长羽织就的大氅. ");
	set("material", "cloth");
	set("apply/armor", 15);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp