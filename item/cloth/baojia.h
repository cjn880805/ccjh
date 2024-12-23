//baojia.h

//Sample for ITEM: 真丝宝甲
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIbaojia);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "真丝宝甲");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(5000);		//set item weight

	set("unit", "件");
	set("no_drop","宝物是扔/卖不了的，也不能给别人。");
	set("value", 50000);
	set("material", "gold");
	set("apply/per", 5);
	set("apply/armor", 500);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp