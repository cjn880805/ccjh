//chaidao.h

//Sample for ITEM: 柴刀
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIchaidao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "柴刀");	//set item name
	
	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(1000);		//set item weight
	
	set("unit", "把");
	set("value", 0l);
	set("material", "iron");
	set("long", "这是一柄半新不旧的柴刀。");
	set("wield_msg", "$N抽出一把$n握在手中。");
	set("unequip_msg", "$N将手中的$n插回腰间。");
	set("apply/damage", 5);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp