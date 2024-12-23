//toukui.h

//Sample for ITEM: ͷ��
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CItoukui);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ͷ��");	//set item name

	set("wield_position", WIELD_HEAD);		//set the position of wield
 	set_weight(500);		//set item weight

	set("unit", "��");
	set("long", "����һ������ͷ�������Ա���ͷ����");
	set("value", 100);
	set("material", "head");
	set("apply/armor", 10);
	set("shaolin",1);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp