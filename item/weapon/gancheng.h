//gancheng.h

//Sample for ITEM: 杆秤
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIgancheng);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "杆秤");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "club");			//set the skill applied
	set_weight(5000);		//set item weight
	
	set("unit", "杆");
	set("long", "一杆闹市货物常用的杆秤。");
	set("value", 500);
	set("rigidity",100);
	set("material", "steel");
	set("wield_msg", "$N抽出一杆$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回腰间。");
	set("apply/damage", 5);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp