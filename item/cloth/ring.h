//ring.h

//Sample for ITEM: �����ָ
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIring);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�����ָ");	//set item name

	set("wield_position", WIELD_ARMOR_HANDS);		//set the position of wield
 	set_weight(200);		//set item weight
	
	set("unit", "ö");
	set("value", 100000);
	set("material", "��ʯ");
	set("apply/armor", 2);
	set("apply/per", 3);
	set("female_only", 1);
	set("long", "���������͸�Ӻ�ݵĶ����ָ���������������裬�淢������ˡ�");

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp