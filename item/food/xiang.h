//xiang.h

//Sample for ITEM ����ү
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����ү");	//set item name

	set_weight(50);

	set("unit", "��");
	set("long", "����һ��������������ҩ������֮����Ҫ����������������ү�Ƶġ�");

};

virtual int do_use(CChar * me, CContainer * target)
{
	if ( me->query("mp") >= me->query("max_mp")*2 )
        return notify_fail("������û��Ҫ������ү��");
	
	me->add("mp", 1);
	message_vision( "$N����һ������ү��ֻ������������Ҫ���裡" , me);
	
	destruct(this);
 	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp