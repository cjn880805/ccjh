//shoupa.h

//Sample for ITEM: 手帕
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIshoupa);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "手帕");	//set item name

//	set("wield_position", WIELD_WRIST);		//set the position of wield
 	set_weight(300);		//set item weight

	set("unit", "个");
	set("long","这是一个漂亮的手帕。");
	set("value", 50);
	set("material", "cloth");
	set("female_only", 1);
	set("apply/armor", 3);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp