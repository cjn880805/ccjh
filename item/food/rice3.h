//rice3.h

//Sample for ITEM �����׷�
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIrice3);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�����׷�");	//set item name

	set("long", "һ��������ĸ����׷���");
	set("unit", "��");
	set("value", 80);
	set("food_remaining", 4);
	set("food_supply", 10);
	set("material", "rice");
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp