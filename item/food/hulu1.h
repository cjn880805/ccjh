//hulu1.h

//Sample for ITEM ��«
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIhulu1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��«");	//set item name

	set_weight(700);

	set("long", "һ����ɫ�ĺ�«��");
	set("unit", "��");
	set("value", 100);
	set("max_liquid", 3);
	set("liquid/type", "alcohol" );
	set("liquid/name",  "ҩ��");
	set("liquid/remaining", 3 );
	set("liquid/drunk_supply", 10 );

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp