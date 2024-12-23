//tiepipa.h

//Sample for ITEM: 铁琵琶
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CItiepipa);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "铁琵琶");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(50000);		//set item weight

	set("unit", "把");
	set("long", "这是一把奇形铁琵琶，打造的相当精巧坚实。");
	set("value", 3000);
	set("material", "iron");
	set("wield_msg", "$N从背上解下一把$n，然後横在手中。");
	set("unwield_msg", "$N放下手中的$n。");
// 	init_hammer(45);
	set("apply/damage",45 );					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp