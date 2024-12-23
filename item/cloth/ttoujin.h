//ttoujin.h

//Sample for ITEM: 台夷头巾
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIttoujin);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "台夷头巾");	//set item name

	set("wield_position", WIELD_HEAD);		//set the position of wield
 	set_weight(2000);		//set item weight

	set("material", "steel");
	set("unit", "条");
	set("long", "这是一条台夷头巾，用以缠绕头部。");
	set("value", 1500);
	set("apply/dodge", -5);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp