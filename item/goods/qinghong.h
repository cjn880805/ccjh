//xin.h 

ITEM_BEGIN(CIqinghong)

virtual void create(int nFlag = 0)		
{
	 set_name("���׷����", "rainbow needle");
     set_weight(10000);
        
     set("unit", "��");
     set("material", "steel");
	 set("no_give",1);
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || target == me)
		return notify_fail("��Ҫ��˭ʹ�ã�");

	if (query("used"))
		return notify_fail("%sֻ��ʹ��һ�Ρ�", name());

	if (me->is_fighting())
		return notify_fail("�����޷�ʹ�����׷���룡");

    if( (me->environment())->query("no_fight"))
		return notify_fail("���ⲻ��͵Ϯ��");

	message_vision("$N��Цһ�����ӻ�������һ��������׼$n���Ӻ��ӱ����һ����⣡������", me, target);
	
	int i;
	i=target->query_skill("dodge");	
	i=1000 - i;	
	i=i*3;	
	if (i<1) i=1;

	message_vision("ֻ��$N����һ���Ƴ��ĲҽУ���������������", me);   

	target->apply_condition("rainbow_poison", 20 + random(20));

	set("used",1);
	target->kill_ob(me);
	target->receive_wound("hp",i);	
	me->start_busy(4);

	return 1;
}

ITEM_END;
