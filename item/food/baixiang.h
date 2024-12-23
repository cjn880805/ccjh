//baixiang.h

//Sample for ITEM ���㻨
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIbaixiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���㻨");	//set item name

	set("unit", "��");
	set("long", "����һ�����޵Ļ�������Ũ���쳣��");
};

virtual int do_use(CChar * me, CContainer * target)
{
	me->add("max_mp", 5);
	destruct(this);
	return 1;
}

virtual int Can_Use()
{
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp