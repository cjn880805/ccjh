//futou.h

//Sample for ITEM: 大斧头
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIfutou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "大斧头");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "axe");			//set the skill applied
	set_weight(7000);		//set item weight
	
	set("unit", "柄");
	set("long", "这是一把砍柴的大斧头。");
	set("value", 500);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回后腰。");
	set("apply/damage", 15);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp