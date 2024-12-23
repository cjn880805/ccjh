//shebian.h

//Sample for ITEM: 蛇鞭
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIshebian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "蛇鞭");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "whip");			//set the skill applied
	set_weight(700);		//set item weight

	set("unit", "柄");
	set("long", "这是一柄蛇皮长鞭。");
	set("value", 300);
	set("material", "leather");
	set("wield_msg", "$N「唰」的一声抖出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n卷回腰间。");
//	init_whip(30);
	set("apply/damage", 30);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp