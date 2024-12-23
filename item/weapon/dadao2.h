//dadao2.h

//Sample for ITEM: 大刀
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIdadao2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "大刀");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(5000);		//set item weight
	
	set("unit", "把");
	set("value", 1500);
	set("material", "iron");
	set("long", "这是一柄铁打的大刀。");
	set("wield_msg", "$N抽出一把$n握在手中。");
	set("unequip_msg", "$N将手中的$n插回腰间。");
	set("apply/damage", 10);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp