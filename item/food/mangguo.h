//mangguo.h

//Sample for ITEM â��
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CImangguo);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "â��");	//set item name

	set_weight(40);

	set("long", "һ�����ʵ�â�����������˴������Ρ�");
	set("unit", "��");
	set("value", 80);
	set("food_remaining", 4);
	set("food_supply", 30);
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp