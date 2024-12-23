//shoutao.h

//Sample for ITEM: 皮手套
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIshoutao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "皮手套");	//set item name

	set("wield_position", WIELD_ARMOR_HANDS);		//set the position of wield
 	set_weight(500);		//set item weight

	set("unit", "双");
	set("long", "这是一双皮手套，上面有硬物刻勒的痕迹。");
	set("value", 600);
	set("material", "hands");
	set("apply/armor", 3);
	set("shaolin",1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp