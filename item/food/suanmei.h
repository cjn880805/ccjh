//suanmei.h

//Sample for ITEM ��÷��
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIsuanmei);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��÷��");	//set item name

	set_weight(1000);

	set("long","����һ����������");
	set("unit", "��");
	set("value", 20);
	set("max_liquid", 10);
	set("liquid/name", "��÷��" );
	set("liquid/type",  "water");
	set("liquid/remaining", 8 );

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp