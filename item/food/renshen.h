//renshen.h

//Sample for ITEM �˲�
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIrenshen);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�˲�");	//set item name

	set_weight(700);

	set("unit", "��");
	set("long", "����һ�ó������ε���ɽ�Ρ�");
	set("value", 10000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	me->add("max_mp", 3);
	message_vision("$N����һ����ɽ�Σ���ʱ�����ȫ������˻��� !", me);
	destruct(this);
	return 1;

}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp