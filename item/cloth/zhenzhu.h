//zhenzhu.h

//Sample for ITEM: 大珍珠
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIzhenzhu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "大珍珠");	//set item name

	set("wield_position", WIELD_HEAD);		//set the position of wield
 	set_weight(8000);		//set item weight
                
	set("material", "cloth");
	set("unit", "个");
	set("long", "这是一个大珍珠，很值钱。");
	set("value", 30000);
	set("apply/dodge", 5);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp