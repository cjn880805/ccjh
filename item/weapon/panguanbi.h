//panguanbi.h

//Sample for ITEM: 镔铁判官笔
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIpanguanbi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "镔铁判官笔");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "dagger");			//set the skill applied
	set_weight(12000);		//set item weight

	set("unit", "对");
	set("long", "这是一对用镔铁打造的判官笔。");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声从怀中掏出一对$n握在手中。");
	set("unwield_msg", "$N将手中的$n揣回怀里。");
//	init_dagger(25);
	set("apply/damage",25 );					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp