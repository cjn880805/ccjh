AUTOCOMBINE_BEGIN(CIhuicheng_juanzhou)

virtual void create(int nFlag = 0)		
{
	set_name("�سǾ���", "huicheng juanzhou");
    set("base_weight", 1500);
	set("base_value", 100);
 
	set("material", "paper");

	set_amount(1);
};

virtual int do_use(CChar * me, CContainer * target)
{
	char msg[255];
	if(me->is_fighting())
		return notify_fail("������ս����");

	if(me->query_temp("no_fei"))
		return notify_fail("����Ŀǰ�����Σ��޷�ʹ�á��سǾ��ᡱ��");

	if(me->query_temp("no_fei_1"))
		return notify_fail("����Ŀǰ�����Σ��޷�ʹ�á��سǾ��ᡱ��");

	CRoom * r = load_room(me->querystr("start_city"));
//	if(r->query("corp"))
//		return notify_fail("�޷�ʹ�á��سǾ��ᡱ�ذ���ܶ档");
	message_vision("$HIY$N�ڿ��л���һ���ţ�̧�ȿ��˽�ȥ��", me);
	me->move(r);
	tell_room(r, snprintf(msg, 255, "$BLU�����ֳ�һ���ţ�%s��������������", me->name()), me);

	destruct(this);
	return 1;
};

virtual int Can_Use()
{
	return 1;
};


AUTOCOMBINE_END;
