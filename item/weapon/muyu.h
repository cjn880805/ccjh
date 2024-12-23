//muyu.h

//Sample for ITEM: 木鱼锤
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CImuyu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "木鱼锤");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(8000);		//set item weight
	
	set("unit", "把");
	set("long", "这是一把很沉的铁木鱼锤");
	set("value", 10000);
	set("material", "steel");
	set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。");
	set("unwield_msg", "$N放下手中的$n。");
	set("apply/damage", 15);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp