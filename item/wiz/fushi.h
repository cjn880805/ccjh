//������ʯ

ITEM_BEGIN(CIfushi);

virtual void create(int nFlag = 0)		
{
	set_name("��ʯ","stone");

	set_weight(5000);
	set("value", 1);
	set("long", "���ǲ��Ե�����һ�ֵ�ʯͷ�����ĵ����Ű���ɫ�Ĺ�â����˵����ӵ���Ŵ����������������֮Ч��");  

};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting())
		return notify_fail("������ս����");

	CContainer * env = me->environment();
	
	if(DIFFERSTR(env->querystr("area"),"�߲�") && DIFFERSTR(env->querystr("area"),"Ұ��"))
		return notify_fail("����ʯ��ֻ���ڵ�����ʹ�ã�");

	message_vision("ֻ��$N�ó���ʯ�������洵��һ��������ʯ����һ�Ź����Χ��$N��", me);
	me->set("start_obj",env->querystr("base_name"));
	me->set_temp("start_obj",env->querystr("base_name"));
	destruct(this);
    return 1; 
}

ITEM_END;
