//egg.h

//Sample for ITEM �����Ҷ��
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIegg);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�����Ҷ��");	//set item name

	set_weight(2000);
	
	set("long", "һ���������������Ƴ����Ĳ�Ҷ����");
	set("unit", "��");
	set("value", 50);
	set("food_remaining", 1);
	set("food_supply", 50);
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



