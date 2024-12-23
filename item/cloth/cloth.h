//cloth.h

//Sample for ITEM: ²¼ÒÂ
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CICloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "²¼ÒÂ");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(3000);		//set item weight

	set("value", 1);
	set("unit", "¼þ");
	set("material", "cloth");
	set("apply/armor", 1);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp