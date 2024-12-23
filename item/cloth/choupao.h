//choupao.h

//Sample for ITEM: 绸袍
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIchoupao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "绸袍");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(3000);		//set item weight

	set("long","一件丝绸长袍，质的和裁剪都不错．");
	set("material",  "cloth");
	set("unit",  "件");
	set("value",  600);
	set("apply/armor",  4);
	set("apply/per",  1);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp