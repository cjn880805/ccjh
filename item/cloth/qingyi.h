//qingyi.h

//Sample for ITEM: 青布袍
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIqingyi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "青布袍");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(1000);		//set item weight
         
	set("unit", "件");
	set("armor_type", "cloth");
	set("value", 250);
	set("apply/dodge", 6);
	set("apply/armor", 1);
	set("long","这是一件质地上佳的青衣。");
 
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp