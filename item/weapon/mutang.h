//mutang.h

//Sample for ITEM: 木镗
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CImutang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "木镗");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(1500);		//set item weight

	set("unit", "把");
	set("value", 50);
	set("material", "wood");
	set("long", "这是一把作神道用的木镗。");
	set("wield_msg","$N高高举起$n。");
	set("unwield_msg", "$N放下$n，有些气喘吁吁。");
//	init_blade(20);
	set("apply/damage",20 );					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp