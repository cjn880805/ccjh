//fotiaoqiang.h

//Sample for ITEM ����ǽ
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIfotiaoqiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����ǽ");	//set item name

	set_weight(1000);
	
	set("long", "һ��������ķ���ǽ���Ǹ�����һ���ˡ�");
	set("unit", "��");
	set("value", 500);
	set("food_remaining", 10);
	set("food_supply", 100);
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp