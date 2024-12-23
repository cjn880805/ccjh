//tiezhitao.h

//Sample for ITEM: ��ָ��
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CItiezhitao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ָ��");	//set item name

	set("wield_position", WIELD_ARMOR_HANDS);		//set the position of wield
 	set_weight(500);		//set item weight
	
	set("unit", "��");
	set("long", "�������������������ָ�ף�ǰ�˷������У��ȿɰ����������ˣ��ֿɱ���ָ�ؽڡ�");
	set("value", 60);
	set("material", "finger");
	set("apply/armor", 5);
	set("shaolin",1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp