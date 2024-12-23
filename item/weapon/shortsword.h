//shortsword.h

//Sample for ITEM: 短剑
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIshortsword);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "短剑");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(5000);		//set item weight

	set("unit", "柄");
	set("long", "这是一柄的短剑，据说剑里藏着一个极大秘密，几百年来辗转相传，始终无人参详得出。");
	set("value", 1000);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回剑鞘。");
// 	init_sword(75);
	set("apply/damage", 75);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp