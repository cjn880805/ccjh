//jinchuang.h

FOOD_BEGIN(CIjinchuang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("��ҩ", "jinchuang yao");
	set("unit", "��");
	set("long", "����һ��������ʿ�ر��Ľ�ҩ��");
	set("value", 2000);	
};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�");

	if (me->query("eff_hp") == me->query("max_hp"))
		return notify_fail("�����ڲ���Ҫ�ý�ҩ��");
	
	me->receive_curing("hp", 50);
	message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�", me);
	me->start_busy(2);
	destruct(this);
	
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp