//dafu.h

//Sample for ITEM: 大斧
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIdafu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "大斧");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "axe");			//set the skill applied
	set_weight(5000);		//set item weight
	
	set("unit", "柄");
	set("long", "一柄十分锋利的大斧。");
	set("value", 100);
	set("material", "bamboo");
	set("wield_msg", "$N回手从身后抽出一柄大斧。");
	set("unwield_msg", "$N手往后一别，把大斧插在后腰上。");
	set("apply/damage", 50);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp