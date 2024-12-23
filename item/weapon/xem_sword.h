//xem_sword.h

//Sample for ITEM: 回风剑
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIxem_sword);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "回风剑");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(6000);		//set item weight
	
	set("unit", "柄");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N掐诀念咒, 一口$n破空而至, 落入$N的手中。\n");
	set("unwield_msg", "$n从$N手中一跃而起, 啸声中破空而去。\n");
	set("apply/damage", 30);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp