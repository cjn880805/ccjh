//baozi2.h

//Sample for ITEM �ٹ��Ͱ�
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIbaozi2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�ٹ��Ͱ�");	//set item name
	
	set_weight(80);
	
	set("long", "һ������ͳγΡ�������İٹ��Ͱ���");
	set("unit", "��");
	set("value", 70);
	set("food_remaining", 3);
	set("food_supply", 20);
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp