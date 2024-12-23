//puercha.h

//Sample for ITEM ���
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIpuercha);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���");	//set item name

	set_weight(700);
	
	set("long", "һ������װ��Ĵ��������װ�ðˡ��ű��Ĳ衣\n");
	set("unit", "��");
	set("value", 150);
	set("max_liquid", 15);
	set("liquid/type", "water");
	set("liquid/name","�����ն���" );
	set("liquid/remaining", 15);
	set("liquid/drunk_apply", 5);
 	
};


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp