//tofu.h

//Sample for ITEM ��䶹��
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CItofu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��䶹��");	//set item name

	set_weight(1000);
	
	set("long", "һ��ˮ����Ĵ󶹸����۵����˲����뵽����ɩ����������");
	set("unit", "��");
	set("value", 40);
	set("food_remaining", 1);
	set("food_supply", 50);
 	
};


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



