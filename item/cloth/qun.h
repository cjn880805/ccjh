//qun.h

//Sample for ITEM: 白纱挑线镶边裙
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIqun);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "白纱挑线镶边裙");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(2000);		//set item weight
         
	set("long", "这是一件当地土著常用的白纱挑线镶边裙。");
	set("material", "cloth");
	set("unit", "件");
	set("value", 250);
	set("apply/armor", 1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp