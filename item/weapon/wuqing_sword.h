//wuqing_sword.h

//Sample for ITEM: 多情剑
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIwuqing_sword);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "多情剑");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(6000);		//set item weight
	
	set("unit", "柄");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	set("apply/damage", 30);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp