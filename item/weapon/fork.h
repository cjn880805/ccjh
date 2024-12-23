//fork.h

//Sample for ITEM: 三股叉
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIfork);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "三股叉");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "club");			//set the skill applied
	set_weight(5000);		//set item weight

	set("unit", "杆");
	set("long", "这是一杆三尖开刃的三股叉。");
	set("value", 1500);
	set("rigidity",100);
	set("material", "steel");
	set("wield_msg", "$N掣出一杆$n握在手中。");
	set("unwield_msg", "$N将手中的$n反别身后。");
	set("apply/damage", 25);					//set the modifiers of attribute

};
 
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp