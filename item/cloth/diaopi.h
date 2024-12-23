//diaopi.h

//Sample for ITEM ıı∆§
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIdiaopi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ıı∆§");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(2000);		//set item weight

	set("unit", "øÓ");
	set("material", "fur");
	set("value", 5000);
	set("apply/armor", 3);
	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp