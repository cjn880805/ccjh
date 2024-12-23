//zhitao.h

//Sample for ITEM 指套
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIzhitao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "指套");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "finger");			//set the skill applied
	set_weight(500);		//set item weight
	
	set("unit", "副");
	set("long", "这是五个环环相链的铁指套，前端锋利如刃，既可暗藏掌中伤人，又可保护指关节。");
	set("value", 600);
	set("material", "steel");
	set("apply/armor", 5);
	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp