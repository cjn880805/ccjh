//yangrou.h

//Sample for ITEM ���⴮
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIyangrou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���⴮");	//set item name
	
	set_weight(300);
	set("long", "һ������������⴮������մ������Ȼ�������档");
	set("unit", "��");
	set("value", 200);
	set("food_remaining", 3);
	set("food_supply", 50);
  
};
 
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp