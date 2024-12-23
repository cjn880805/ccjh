//gouroutang.h

//Sample for ITEM ������
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIgouroutang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set_weight(700);
	
	set("long", "һ������һ�빷�����Ĵ��룬����һ�����ˡ�");
	set("unit", "��");
	set("value", 200);
	set("max_liquid", 15);
	set("food_remaining", 25);
	set("food_supply", 5);

	set("liquid/type","water"); 
	set("liquid/name","������"); 
	set("liquid/remaining",25); 
	set("liquid/drunk_apply",5); 
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp