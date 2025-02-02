//rover.h

//Sample for ITEM: 飘缈魔君
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIrover);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "飘缈魔君");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(100);		//set item weight
        set("value", 400);   
	set("long", "一件有魔力的衣服，闻起来还有一股淡香，穿上去感觉很飘缈。");
	set("unit", "件");
	set("material", "cloth");
	set("apply/armor", 1);
	set("apply/per", 3);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp