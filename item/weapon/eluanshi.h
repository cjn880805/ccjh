//eluanshi.h

//Sample for ITEM: 鹅卵石
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIeluanshi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "鹅卵石");	//set item name
	
	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set_weight(1000);		//set item weight
	
	set("unit", "些");
	set("long", "这是一粒平平常常的鹅卵石。");
	set("base_unit", "粒");
	set("base_weight", 300);
	set("value", 0l);
	set("material", "stone");
	set("wield_msg", "$N掏出一粒$n准备战斗。");
	set("unwield_msg", "$N放下手中的$n。");
	set_amount(20);
	set("apply/damage", 1);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp