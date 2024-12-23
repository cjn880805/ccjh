//tiedan.h

//Sample for ITEM: 铁胆
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

AUTOCOMBINE_BEGIN(CItiedan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "铁胆");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
//	set_weight(1500);		//set item weight

	set("unit", "些");
	set("value", 0l);
	set("base_unit", "枚");
	set("base_weight", 4000);
	set("base_value", 1);
	set("no_sell", 1);

	set("material", "iron");
	set("long", "一些溜圆的铁胆，是一种凶猛的暗器。");
	set("wield_msg", "$N迅速地从身上摸出一些铁胆，捏在手中就待发出！");
	set("unwield_msg","$N将手里剩下的铁胆一抖就不见了。");
	set_amount(80);
//	init_throwing(50);
	set("apply/damage",50);					//set the modifiers of attribute

};


AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp



