//jinlun.h

//Sample for ITEM: 金轮
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIjinlun);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "金轮");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(5000);		//set item weight

	set("unit", "把");
	set("long","这是一柄金光闪闪的法轮。" );
	set("value", 1000);
	set("material", "gold");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg","$N将手中的$n放回腰间。");
//	init_hammer(200);
	set("apply/damage",200 );					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp