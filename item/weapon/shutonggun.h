//shutonggun.h

//Sample for ITEM: 熟铜棍
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIshutonggun);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "熟铜棍");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "club");			//set the skill applied
	set_weight(2000);		//set item weight

	set("unit", "杆");
	set("long", "一杆十分灵便的熟铜棍。");
	set("value", 1000);
	set("material", "bamboo");
	set("wield_msg", "$N回手从身后抽出一杆熟铜棍。");
	set("unwield_msg", "$N手往后一扣，把熟铜棍放在身后。");
//	init_club(30);
	set("apply/damage", 30);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp