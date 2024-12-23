//baichou.h

//Sample for ITEM: °×³ñÈ¹
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIbaichou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "°×³ñÈ¹");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(500);		//set item weight
	
	set("unit", "¼þ");
	set("armor_type", "cloth");
	set("value", 5000);
	set("apply/dodge", 5);
	set("apply/armor", 2);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp