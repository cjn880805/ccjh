//guazi.h

//Sample for ITEM: ���ƹ���
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIguazi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���ƹ���");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(2000);		//set item weight

	set("long", "����һ���������峣�õĶ��ƹ��ӡ�");
	set("material", "cloth");
	set("unit", "��");
	set("value", 350);
	set("apply/armor", 5);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp