//magcloth.h

//Sample for ITEM: воеш
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CImagcloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "воеш");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(500);		//set item weight
          
	set("unit", "╪Ч");
	set("material", "cloth");
	set("value", 300);
	set("apply/armor", 5);
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp