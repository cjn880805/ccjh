//hothammer.h

//Sample for ITEM: 烧红的铁锤
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIhothammer);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "烧红的铁锤");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(8000);		//set item weight

	set("unit", "把");
	set("long", "这是一把沈重的铁锤，打造的相当坚实。");
	set("value", 300);
	set("material", "iron");
	set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。");
	set("unwield_msg", "$N放下手中的$n。");
//	init_hammer(25);
	set("apply/damage",35 );					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp