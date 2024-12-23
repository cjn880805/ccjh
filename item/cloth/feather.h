//feather.h

//Sample for ITEM ��ȸ����
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIfeather);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ȸ����");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(600);		//set item weight

	set("long", "�����ȸ�������ÿ�ȸ��ë֯�ɵġ�");
	set("unit", "��");
	set("value", 5000);
	set("material", "feather");
	set("apply/per", 10);
	set("apply/armor", 10);
	set("apply/armor_vs_force", 10);
	set("apply/attack", -2);
	
	set("no_get", "1");
	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp