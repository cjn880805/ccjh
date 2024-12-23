//color_dress.h

//Sample for ITEM: ����廨ȹ
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIcolor_dress);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����廨ȹ");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(700);		//set item weight

	set("unit", "��");
	set("value", 2000);
	set("material", "cloth");	

	set("apply/per", 2);
	set("apply/armor", 3);
	set("female_only", 1);
	set("wear_msg","$N����һ��$n��");
	set("remove_msg","$��$n����������");
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp