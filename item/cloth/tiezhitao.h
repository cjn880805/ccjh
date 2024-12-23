//tiezhitao.h

//Sample for ITEM: 铁指套
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CItiezhitao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "铁指套");	//set item name

	set("wield_position", WIELD_ARMOR_HANDS);		//set the position of wield
 	set_weight(500);		//set item weight
	
	set("unit", "副");
	set("long", "这是五个环环相链的铁指套，前端锋利如刃，既可暗藏掌中伤人，又可保护指关节。");
	set("value", 60);
	set("material", "finger");
	set("apply/armor", 5);
	set("shaolin",1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp