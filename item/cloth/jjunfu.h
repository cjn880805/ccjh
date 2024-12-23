//jjunfu.h

//Sample for ITEM: ���¾���
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIjjunfu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���¾���");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(2000);		//set item weight
          
	set("long", "����һ����ɫ�����Ľ��¾�����");
	set("material", "cloth");
	set("unit", "��");
	set("value", 1200);
	set("apply/per", 4);
	set("apply/armor", 15);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp