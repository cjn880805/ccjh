//caomei.h

//Sample for ITEM ��ݮ
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIcaomei);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ݮ");	//set item name
	
	set_weight(100);
	
	set("long", "һ���ʺ�˶��Ĳ�ݮ��");
	set("unit", "��");
	set("value", 10);
	set("food_remaining", 2);
	set("food_supply", 20);
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp