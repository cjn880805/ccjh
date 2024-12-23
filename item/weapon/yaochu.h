//yaochu.h

//Sample for ITEM: 药锄
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIyaochu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "药锄");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(1000);		//set item weight
	
	set("unit", "把");
	set("long", "这是一把采药用的药锄，已经有些生锈了。");
	set("value", 100);
	set("material", "iron");
	set("wield_msg", "$N拿出一把$n，握在手中。");
	set("unwield_msg", "$N放下手中的$n。");
	set("apply/damage", 5);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp