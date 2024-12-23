//jingang_zhao.h

//Sample for ITEM: �����
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIjingang_zhao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�����");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(2000);		//set item weight
	
	set("material", "cloth");
	set("unit", "��");
	set("value", 2000000);
	set("wear_msg",  "ֻ����������һ����$Nչ��һ����������������������ϡ�˲ʱ������Ϊ֮ʧɫ������ǧ�������ƶ�䣬һ��ׯ������" );
	set("remove_msg",  "$N������ִ����������������۵���СС��һ�š�" );
	set("apply/armor", 1000);
	set("long", "����һ��������������ģ�ͨ������ɽѩ��˿֯�ɣ������ޱȵ��������ˡ�������������ǰ�ɴ�Ħ����Я����ԭ��аħ��֮���ף����Ƿ�����Ͻ�ħ������");

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp