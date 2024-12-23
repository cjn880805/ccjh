//cha2.h

//Sample for ITEM ���ݴ�
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIcha2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���ݴ�");	//set item name

	set_weight(1000);
	
	set("long","����һ����ɫ���̡���ζŨ���ϵȺò衣�����˳�����ɷ����!");
	set("unit", "��");
	set("value", 20);
	set("max_liquid", 10);
	set("liquid/name", "���ݴ�");
	set("liquid/remaining", 8);
	set("liquid/type", "water");
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp