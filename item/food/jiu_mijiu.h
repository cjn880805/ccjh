//jiu_mijiu.h �׾�

FOOD_BEGIN(CIjiu_mijiu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�׾�");	//set item name

	set_weight(700);

	set("long", "һƿ�Ϻõ��׾ơ�");
	set("unit", "̳");
	set("value", 200000);
};


virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if (target != me)
		return notify_fail("��ֻ���Լ��ȡ�");
	
	message_vision( "$N��ཹ�ཱུİѾƺ��¡�\n$N����ɫһ���һ��ף������Ǻ����ˣ�",me);
	me->apply_condition("drunk", 10 + random(10));
	me->FlushMyInfo();
	
	destruct(this);
	
	return 1;
}


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp