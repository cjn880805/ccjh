//yuchi.h

//Sample for ITEM ���
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIyuchi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���");	//set item name

	set_weight(80);

	set("long", "�ϵ����,ζ������.��ʵҲ����ô����.");
	set("unit", "��");
	set("value", 100);
	set("food_remaining", 1);
	set("food_supply", 1);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp