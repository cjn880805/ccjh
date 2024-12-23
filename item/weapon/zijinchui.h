//zijinchui.h

//Sample for ITEM: 紫金锤
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIzijinchui);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "紫金锤");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(20000);		//set item weight

	set("unit", "枚");
	set("long", "这是一枚由海底金母铸造而成的大锤，看上去紫光盈盈, 显得极是沉重。");
	set("value", 3000);
	set("material", "steel");
	set("wield_msg", "$N振臂一挥, 抡出一枚沉重的$n。");
	set("unwield_msg", "$N将手中的$n慢慢收回。");
//	init_hammer(40);
	set("apply/damage", 50);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp