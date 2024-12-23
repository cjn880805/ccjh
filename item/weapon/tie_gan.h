//tie_gan.h

//Sample for ITEM: 细铁杆
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CItie_gan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "细铁杆");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(8000);		//set item weight
	
	set("unit", "根");
	set("long", "这是一根又细又张的铁杆。");
	set("value", 1000);
	set("material", "steel");
	set("wield_msg", "$N拿出一根$n握在手中。");
	set("unwield_msg", "$N将手中的$n放下。");
	set("apply/damage", 30);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp