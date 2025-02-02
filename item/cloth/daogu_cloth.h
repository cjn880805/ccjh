//daogu_cloth.h

//Sample for ITEM 花格道袍
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIdaogu_cloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "花格道袍");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(3000);		//set item weight

	set("unit", "件");
	set("value", 300);
	set("long", "一件普普通通的花格道袍。");
	set("material", "cloth");
	set("apply/armor", 2);
	set("female_only", 1);
	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp