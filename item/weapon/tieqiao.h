//tieqiao.h

//Sample for ITEM: 铁锹
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CItieqiao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "铁锹");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "club");			//set the skill applied
	set_weight(7000);		//set item weight

	set("unit", "柄");
	set("long", "这是一把挖矿的铁锹。");
	set("value", 1000);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回后腰。");
//	init_club(2);
	set("apply/damage", 2);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp