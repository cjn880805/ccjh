//yaodai.h

//Sample for ITEM: Ƥ����
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIyaodai);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ƥ����");	//set item name

	set("wield_position", WIELD_WAIST);		//set the position of wield
 	set_weight(300);		//set item weight

	set("unit", "��");
	set("long", "����һ��Ƥ�ʵĿ��������в�͸�գ����ԷŸ�������С�");
	set("value", 600);
	set("material", "waist");
	set("apply/armor", 5);
	set("shaolin",1);

};
/****************************
	set_max_encumbrance(1000);
*************************/
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp