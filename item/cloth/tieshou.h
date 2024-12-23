//tieshou.h

//Sample for ITEM 铁手掌
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CItieshou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "铁手掌");	//set item name

	set("wield_position", WIELD_ARMOR_HANDS);		//set the position of wield
	set_weight(2000);		//set item weight

	set("material", "steel");
	set("unit", "块");
	set("long", "这是一块铁质的手掌形护具，用以保护手掌。");
	set("value", 900);
	set("apply/armor", 5 );
	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp