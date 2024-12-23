//bu_shoes.h

//Sample for ITEM: ��Ь
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIbu_shoes);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��Ь");	//set item name

	set("wield_position", WIELD_BOOT);		//set the position of wield
 	set_weight(1000);		//set item weight

	set("unit", "˫");
	set("value", 50);
	set("material", "cloth");

	set("apply/armor", 2);
	set("apply/dodge", 2);
	set("wear_msg","$N����һ˫$n��");
	set("remove_msg","$N��$n����������");
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp