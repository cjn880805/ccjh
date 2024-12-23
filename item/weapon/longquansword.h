//longquansword.h

//Sample for ITEM: 龙泉剑
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIlongquansword);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "龙泉剑");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(4000);		//set item weight

	set("unit", "柄");
	set("long","这是柄一看就知道是宝剑的利器。");
	set("value", 2400);
	set("material", "blacksteel");
	set("wield_msg", "只听见「飕」地一声，$N的手中已经多了一把寒光四射的宝剑——$n。");
	set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。");
//	init_sword(60);
	set("apply/damage", 60);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp