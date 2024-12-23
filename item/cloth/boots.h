//boots.h

//Sample for ITEM: ��Ƥѥ
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIboots);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��Ƥѥ");	//set item name

	set("wield_position", WIELD_BOOT);		//set the position of wield
 	set_weight(1000);		//set item weight

	set("unit", "˫");
	set("value", 800);
	set("material", "leather");

	set("apply/per", 1);
	set("apply/armor", 2);
	set("apply/dodge", 2);
	set("wear_msg","$N����һ˫$n��");
	set("remove_msg","$N��$n����������");
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp