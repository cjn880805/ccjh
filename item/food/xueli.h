//xueli.h

//Sample for ITEM ����ѩ��
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxueli);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����ѩ��");	//set item name

	set_weight(40);

	set("long", "һ�����ʵĴ���ѩ�档");
	set("unit", "��");
	set("value", 80);
	set("food_remaining", 4);
	set("food_supply", 40);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp