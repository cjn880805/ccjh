//jade_belt.h

//Sample for ITEM: ����ʯ����
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIjade_belt);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����ʯ����");	//set item name

	set("wield_position", WIELD_WAIST);		//set the position of wield
 	set_weight(1000);		//set item weight

	set("unit", "��");
	set("value", 3000);
	set("material", "cloth");
	set("apply/per", 2);
	set("apply/armor", 4);
	set("apply/dodge", -1);
	set("wear_msg","$NΧ��һ��$n��");
	set("remove_msg","$N��$n����������");

};

 
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp