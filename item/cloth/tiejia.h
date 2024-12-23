//tiejia.h

//Sample for ITEM Ìú¼×
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CITieJia);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ìú¼×");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
	set_weight(20000);		//set item weight

	set("apply/damage", 10);					//set the modifiers of attribute

	set("unit", "¼þ");
	set("material", "steel");
	set("value", 800);
	set("apply/armor", 50);
	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp