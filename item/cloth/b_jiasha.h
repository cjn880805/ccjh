//b_jiasha.h

//Sample for ITEM: ºÚÉ«ôÂôÄ
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIb_jiasha);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ºÚÉ«ôÂôÄ", "jia sha");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(5000);		//set item weight
        set("value", 50);
	set("unit", "¼þ");
	set("material", "cloth");
	set("apply/armor", 20);
	set("value",100);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp