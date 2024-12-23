//beixin.h

//Sample for ITEM: Æ¤±³ÐÄ
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIbeixin);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Æ¤±³ÐÄ");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(1000);		//set item weight

	set("unit", "¼þ");
	set("value", 4000);
	set("material", "leather");
	set("apply/armor", 6);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp