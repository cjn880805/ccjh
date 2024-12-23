//niupidai.h

//Sample for ITEM ţƤ��
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIniupidai);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ţƤ��");	//set item name

	set_weight(200);

	set("long", "��������װ���Ͳ��ţƤ����ɢ�������������㡣");
	set("unit", "��");
	set("value", 150);
	set("max_liquid", 10);
    set("liquid/type", "suyou cha" ); 
    set("liquid/name", "���Ͳ�" ); 
    set("liquid/remaining",  10); 
    set("liquid/drunk_supply", 20 ); 
			
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp