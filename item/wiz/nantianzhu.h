// nantianzhu.h
// ������
// Lanwood 2001-03-22

ITEM_BEGIN(CInantianzhu);

virtual void create(int nFlag = 0)
{
        set_name("������", "nantianzhu");
        set_weight(1000);
    
        set("unit", "��");
		set("long", "һ�в�֪��ʲô��ҩ�ġ���˵�������ý��ڵġ�");
        set("value", 5000);
		
		set("no_sell", 1);		
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me == target)
		message_vision("$N����һ��$n���������̱�����ȡ�", me, this);
	else
	{
		if(! target->is_character())
			return notify_fail("��Ҫ��˭���ã�");
		if(living(target))
			return notify_fail("����ͼ��%s����%s���У�����û�гɹ���", name(), target->name());

		message_vision("$N���ĵ���$n��������һ�������á�", me, target);
	}

	
	((CChar *)target)->apply_condition("wc_poison", 30 + random(30));

	destruct(this);
	return 1;
}

virtual int Can_Use()
{
	return 1;
}

ITEM_END;