//yezi.h

//Sample for ITEM Ҭ��
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIyezi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ҭ��");	//set item name

	set_weight(40);
	
	set("long", "һ�����ʵ�Ҭ�ӣ��������˴������Ρ�");
	set("unit", "��");
	set("value", 80);
	set("food_remaining", 4);
	set("food_supply", 30);
 
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp