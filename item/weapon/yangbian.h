//yangbian.h

//Sample for ITEM: 羊鞭
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIyangbian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "羊鞭");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "whip");			//set the skill applied
	set_weight(300);		//set item weight
	
	set("unit", "柄");
	set("long", "这是一柄普通的羊鞭，做工粗糙。");
	set("value", 30);
	set("material", "leather");
	set("wield_msg", "$N「唰」的一声从腰后抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n别回腰后。");
	set("apply/damage", 5);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp