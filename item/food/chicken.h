//chicken.h

//Sample for ITEM �л�ͯ��
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIchicken);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�л�ͯ��");	//set item name

	set_weight(200);
	
	set("long", "һֻ���������ͣ���ζ�˱ǵĽл�����");
	set("unit", "ֻ");
	set("value", 120);
	set("food_remaining", 1);
	set("food_supply", 100);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp