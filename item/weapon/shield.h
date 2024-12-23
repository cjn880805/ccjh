//shield.h

//Sample for ITEM: Å£Æ¤¶Ü
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIshield);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Å£Æ¤¶Ü", "shield");	//set item name

	set("wield_position", WIELD_LEFT_HAND);		//set the position of wield
//	set("skill_type", "»ù±¾");			//set the skill applied
	set_weight(7000);		//set item weight

	set("material", "leather");
	set("unit", "Ãæ");
	set("value", 1200);
	set("apply/armor", 10);
	set("apply/defense", 3);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp