//bandage.h

//Sample for ITEM: 下訳
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIbandage);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "下訳");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "訳");
	set("material", "cloth");
	set("armor_type", "bandage");
	set("apply/attack", -10);
	set("apply/defense", -10);
	set("apply/unarmed", -10);
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp