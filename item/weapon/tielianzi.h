//tielianzi.h

//Sample for ITEM 铁莲子
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

AUTOCOMBINE_BEGIN(CITieLianZi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "铁莲子");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied

	set("unit", "些");
	set("value", 1000);
	set("base_unit", "颗");
	set("base_weight", 300);
	set("base_value", 1);
	set("material", "iron");
	set("long", "铁莲子是一种以量取胜的暗器，沉颠颠的。");
	set("wield_msg", "$N迅速地从暗器袋中掏出一些铁莲子，捏在手中就待发出!");
	set("unwield_msg","$N将手里剩下的铁莲子尽数放回暗器袋中。");
    set_amount(80);
// 	init_throwing(5);
 	set("apply/damage",5 );					//set the modifiers of attribute

};



AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp



