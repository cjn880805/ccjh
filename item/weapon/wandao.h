//wandao.h

//Sample for ITEM: 阿拉伯弯刀
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIwandao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "阿拉伯弯刀");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(6000);		//set item weight
	
	set("unit", "柄");
	set("long", "这是一柄亮晃晃的阿拉伯弯刀，刀身呈新月状，是中东地区最常见的兵刃。");
	set("value", 1500);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回刀鞘。");
	set("apply/damage", 35);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp