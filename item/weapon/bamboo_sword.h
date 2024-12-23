//bamboo_sword.h

//Sample for ITEM 竹剑
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIBambooSword);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "竹剑");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(1000);		//set item weight

	set("unit", "把");
	set("value", 100);
	set("material", "bamboo");
	set("long", "这是一把练习剑法用的竹剑。");
	set("wield_msg", "$N拿出一把$n，握在手中。");
	set("unequip_msg", "$N放下手中的$n。");
//	init_sword(5);
	set("apply/damage", 5);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp