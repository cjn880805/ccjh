//cycle.h

//Sample for ITEM: 武者项圈
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIcycle);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "武者项圈");	//set item name

	set("wield_position", WIELD_NECK);		//set the position of wield
 	set_weight(1000);		//set item weight

	set("material", "steel");
	set("unit", "串");
	set("long", "这是一串铁质的项链，用以保护颈部。");
	set("value", 1800);
	set("apply/dodge", 5);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp