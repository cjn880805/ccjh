//peanut.h

//Sample for ITEM ���㻨��
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIpeanut);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���㻨��");	//set item name

	set_weight(60);
	
	set("long", "һ��������Ļ����ס�");
	set("unit", "��");
	set("value", 30);
	set("food_remaining", 1);
	set("food_supply", 30);
 	
};


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp