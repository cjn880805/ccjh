//muyuchui.h

//Sample for ITEM: 木鱼槌
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CImuyuchui);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "木鱼槌");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(500);		//set item weight

	set("unit", "把");
	set("value", 50);
	set("material", "wood");
	set("long", "这是一把和尚念经俏木鱼用的小木槌。");
	set("wield_msg", "$N从衣袋里掏出一根$n，握在手中当武器。");
	set("unequip_msg", "$N将手中的$n放回衣袋。");
	set("shaolin",1);
//	init_hammer(1);
	set("apply/damage", 1);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp