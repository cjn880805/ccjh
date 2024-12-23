//tea_leaf.h

//Sample for ITEM 茶叶
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

AUTOCOMBINE_BEGIN(CITeaLeaf);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "茶叶");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied

	set("long", "才采的新茶，发出一股淡淡的香气。");
	set("unit", "把");
	set("value", 400);
	set("base_unit", "片");
	set("base_weight", 1);
	set("base_value", 1);
	set("damage", 1);	//Here the damage=int_throwing, added by King
	set("material", "wood");
	set("wield_msg", "$N迅速地从暗器袋中掏出一些茶叶，捏在手中就待发出！");
	set("unwield_msg","$N将手里剩下的茶叶尽数放回暗器袋中。");

	set_amount(80);
	set("apply/damage", 1);					//set the modifiers of attribute
	
};


AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp



