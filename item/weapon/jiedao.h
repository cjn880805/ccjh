//jiedao.h

//Sample for ITEM: 戒刀
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIjiedao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "戒刀");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(4000);		//set item weight

	set("unit", "把");
	set("value", 500);
	set("material", "iron");
	set("long", "这是一柄尺半长的戒刀，刀光闪闪，入手沉重，似是精铁打成。");
	set("wield_msg", "$N抽出一把明晃晃的$n握在手中。");
	set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。");
	set("shaolin",1);
//	init_blade(25);
	set("apply/damage",25 );					//set the modifiers of attribute


};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp