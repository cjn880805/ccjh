//green_sword.h

//Sample for ITEM: 凝碧剑
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIgreen_sword);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "凝碧剑");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(7000);		//set item weight
	
	set("unit", "把");
	set("long", "这是一把通体晶莹剔透的剑，是武当镇派之宝！");
	set("value", 4000);
	set("material", "crimsonsteel");
	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。");
	set("apply/damage", 100);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp