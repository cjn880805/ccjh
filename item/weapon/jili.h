//jili.h

//Sample for ITEM 毒蒺藜
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

AUTOCOMBINE_BEGIN(CIJiLi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "毒蒺藜");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied

	set("unit", "些");
	set("value", 3500);
	set("base_unit", "枚");
	set("base_weight", 300);
	set("base_value", 1);
	set("material", "iron");
	set("long", "毒蒺藜是淬毒暗器，寸许大小，发出诡异的光。");
	set("wield_msg", "$N迅速地从身上摸出一些毒蒺藜，捏在手中就待发出!");
	set("unwield_msg","$N将手里剩下的毒蒺藜一抖就不见了。");	

    set_amount(80);
	set("apply/damage", 50);					//set the modifiers of attribute

};


AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp




