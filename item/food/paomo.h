//paomo.h

//Sample for ITEM ��������
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIpaomo);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��������");	//set item name

	set_weight(300);
	
	set("long", "һ����������������ɡ�");
	set("unit", "��");
	set("value", 150);
	set("food_remaining", 5);
	set("food_supply", 40);
	
};


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp