//junzijian.h

//Sample for ITEM: 君子剑
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIjunzijian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "君子剑");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(7000);		//set item weight
	
	set("unit", "柄");
	set("long", "这是一口遍体通黑的剑，剑身上用金丝锩着几个字：谦谦君子，温润如玉");
	set("value", 1200);
	set("material", "steel");
	set("apply/per", 24);
	set("wield_msg", "$N低叹一声，将$n缓缓抽出剑鞘。");
	set("unwield_msg", "$N右手一晃，$n已然回鞘。");
	set("apply/damage", 35);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp