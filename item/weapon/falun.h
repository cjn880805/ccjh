//falun.h

//Sample for ITEM: 法轮
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIfalun);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "法轮");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(1000);		//set item weight
	
	set("unit", "把");
	set("long","这是一柄法轮，僧人们用他来作法事。");
	set("value", 50);
	set("material", "wood");
	set("wield_msg", "$N抽出一柄$n握在手中。");
	set("unwield_msg","$N将手中的$n放回腰间。");
	set("apply/damage", 5);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp