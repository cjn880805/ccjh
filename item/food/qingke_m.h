//qingke_m.h

//Sample for ITEM ������
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIqingke_m);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set_weight(1000);
	set("long", "һ����з�ζ�������档"); 
	set("unit", "��"); 
	set("value", 200); 
	set("food_remaining", 4); 
	set("food_supply", 60); 
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



