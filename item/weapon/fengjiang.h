//fengjiang.h

//Sample for ITEM: ��佬
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIfengjiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��佬");	//set item name
	
	set_weight(100);		//set item weight
	
	set("long", "һƿ����䳲���ɵĽ���");
	set("unit", "ƿ");
	set("value", 30);
	set("food_remaining", 3);
	set("food_supply", 40);
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp