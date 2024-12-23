//mujian.h

//Sample for ITEM 木剑
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CImujian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "木剑");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(500);		//set item weight

	set("unit", "柄");
	set("long", "这是一柄木匠做的木剑，手工相当精细。");
	set("value", 50);
	set("material", "steel");
	set("wield_msg", "$N从腰带里抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回腰带上。");
//	init_sword(3);
	set("apply/damage",3 );					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp