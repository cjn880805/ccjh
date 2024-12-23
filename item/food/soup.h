//soup.h

//Sample for ITEM Ұ������
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIsoup);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ұ������");	//set item name

	set_weight(50);

	set("long", "һ������Ұ����������");
	set("unit", "��");
	set("value", 80);
	set("max_liquid", 4);
    set("liquid/type", "water" );
    set("liquid/name", "Ұ����" );
    set("liquid/remaining", 6 );
    set("liquid/drunk_supply",  20);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp