//shrimp.h

//Sample for ITEM ����Ϻ��
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIshrimp);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����Ϻ��");	//set item name

	set_weight(1300);
	
	set("long", "����ŨŨ��һ������Ϻ�ʡ�");
	set("unit", "��");
	set("value", 50);
	set("food_remaining", 5);
	set("food_supply", 20);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp