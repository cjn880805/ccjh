//guijia.h

//Sample for ITEM �ڹ��
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIguijia);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("�ڹ��", "guijia");	//set item name

	set_weight(800);
	
	set("unit", "��");
	set("long", "����һ���ڹ�ף������и��ֻ��ƣ�����������ҩ��");
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp