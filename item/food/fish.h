//fish.h

//Sample for ITEM ��������
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIfish);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��������");	//set item name

	set_weight(1300);
	
	set("long", "һ��������˵��������㣬�������еĽ�ɫ�������ƶ��ɣ���������һ���ˡ�");
	set("unit", "��");
	set("value", 120);
	set("food_remaining", 20);
	set("food_supply", 20);

};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp