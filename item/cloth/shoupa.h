//shoupa.h

//Sample for ITEM: ����
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIshoupa);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����");	//set item name

//	set("wield_position", WIELD_WRIST);		//set the position of wield
 	set_weight(300);		//set item weight

	set("unit", "��");
	set("long","����һ��Ư����������");
	set("value", 50);
	set("material", "cloth");
	set("female_only", 1);
	set("apply/armor", 3);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp