//tanghulu.h

//Sample for ITEM ���Ǻ�«
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CItanghulu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���Ǻ�«");	//set item name

	set_weight(100);

	set("long", "һ�����ı��Ǻ�« ");
	set("unit", "��");
	set("value", 50);
	set("food_remaining", 2);
	set("food_supply", 10);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp