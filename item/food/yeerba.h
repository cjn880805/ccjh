//yeerba.h

//Sample for ITEM Ҷ����
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIyeerba);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ҷ����");	//set item name

	set_weight(80);
	set("long", "����һ��Ʈ�������Ҷ���Ρ�");
	set("unit", "��");
	set("value", 100);
	set("food_remaining", 15);
	set("food_supply", 20);
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp