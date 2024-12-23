//qing_cloth.h

//Sample for ITEM: °×²¼ºÚ±ßôÂôÄ
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIqing_cloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "°×²¼ºÚ±ßôÂôÄ");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(5000);		//set item weight
        
	set("unit", "¼þ");
	set("material", "cloth");
	set("apply/armor", 4);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp