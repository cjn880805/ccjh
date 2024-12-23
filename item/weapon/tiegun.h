//tiegun.h

//Sample for ITEM 铁棍
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CITieGun);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "铁棍");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(1500);		//set item weight


	set("unit", "根");
	set("long", "这是一根浑铁棍，似乎威力不大。");
	set("value", 100);
	set("material", "iron");
	set("wield_msg", "$N拿出一根$n，握在手中。");
	set("unwield_msg", "$N放下手中的$n。");

	set("apply/damage", 20);					//set the modifiers of attribute

};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp