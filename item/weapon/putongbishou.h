//putongbishou.h

//Sample for ITEM: 普通匕首
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIputongbishou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "普通匕首");	//set item name
	
	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(6000);		//set item weight
	
	set("unit", "把");
	set("long", "这是一把普通的小匕首。用来暗算别人比较合适。");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N从兜里掏出一把$n握在手中。");
	set("unwield_msg", "$N将手中的$n放会兜里。");
	set("apply/damage", 30);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp