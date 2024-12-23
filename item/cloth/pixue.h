//pixue.h

//Sample for ITEM: 皮靴
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIpixue);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "皮靴");	//set item name

	set("wield_position", WIELD_BOOT);		//set the position of wield
 	set_weight(800);		//set item weight
		
	set("material", "leather");
	set("unit", "双");
	set("long", "这是一双用上好牛皮作的皮靴，据说由上海进口。用以保护足部。");
	set("value", 1000);
	set("apply/dodge", 8);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp