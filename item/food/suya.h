//suya.h

//Sample for ITEM ��Ѽ
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIsuya);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��Ѽ");	//set item name

	set_weight(200);
	
	set("long", "һֻ����������Ѽ�� ");
	set("unit", "ֻ");
	set("value", 150);
	set("food_remaining", 4);
	set("food_supply", 50);


};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp