//jindan.h

//Sample for ITEM ���ߵ�
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIjindan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���ߵ�");	//set item name
  
	set("unit", "ֻ");
	set("long", "����һֻ�ƲӲӵĽ��ߵ������Ʊ����ߵ��ࡻ��ԭ�ϡ�");
	set("value", 200);


};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp