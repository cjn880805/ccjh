//qingshui_hulu.h

//Sample for ITEM ��ˮ��«
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIqingshui_hulu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ˮ��«");	//set item name

	set_weight(700);

	set("long", "һ���ú�«�Ƴɵ�ˮ����");
	set("unit", "��");
	set("value", 100);
	set("max_liquid", 10);
	set("liquid/type", "water" );
	set("liquid/name", "��ˮ" );
	set("liquid/remaining", 10 );
	set("liquid/drunk_supply",  10);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp