//kaoyangtui.h

//Sample for ITEM ������
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIkaoyangtui);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set_weight(500);

	set("long", "һ��������Ŀ����ȡ�");
	set("unit", "��");
	set("value", 100);
	set("food_remaining", 8);
	set("food_supply", 30);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp