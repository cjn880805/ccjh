//gao.h

//Sample for ITEM ��ѩ����
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIgao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ѩ����");	//set item name

	set_weight(1000);
	
	set("long", "����һ���㣬����ʳ��������");
	set("unit", "��");
	set("value", 50);
	set("food_remaining", 6);
	set("food_supply", 100);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp