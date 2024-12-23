//taomujian.h

//Sample for ITEM: 桃木剑
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CItaomujian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "桃木剑");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "基本");			//set the skill applied
	set_weight(1000);		//set item weight

	set("unit", "把");
	set("value", 100);
	set("material", "bamboo");
	set("long", "这是一把练习剑法用的桃木剑。");
	set("wield_msg", "$N拿出一把练剑用的$n，握在手中。");
	set("unequip_msg", "$N放下手中的$n。");
//	init_sword(10);
 	set("apply/damage", 10);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp