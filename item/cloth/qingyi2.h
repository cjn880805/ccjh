//qingyi2.h

//Sample for ITEM: 青衣
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIqingyi2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "青衣");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(2000);		//set item weight
         
	set("unit", "件");
	set("long", "这是件质量上佳青衣，是由[针神]亲手缝制的。");
	set("material", "cloth");
	set("apply/armor", 10);
	set("value",100);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp