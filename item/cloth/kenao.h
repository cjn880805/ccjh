//kenao.h

//Sample for ITEM: 窄裉袄
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIkenao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "窄裉袄");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(2000);		//set item weight
          
	set("long", "这是一件少数民族常用的窄裉袄。");
	set("material", "cloth");
	set("unit", "件");
	set("value", 400);
	set("apply/per", 2);
	set("apply/armor", 5);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp