//ring_whip.h

//Sample for ITEM: 金铃索
//coded by Cat
//data: 2001-4-3

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIring_whip);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "金铃索");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "whip");			//set the skill applied
	set_weight(500);		//set item weight
	
	set("unit", "条");
	set("long", "这是一条银光闪闪的长索，其中一头还系了一颗金铃铛。");
	set("value", 100);
	set("wield_msg", "$N「唰」的一声抖出一条$n握在手中。");
	set("unwield_msg", "$N将手中的$n卷回腰间。");
	set("apply/damage", 80);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp