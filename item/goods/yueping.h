//����ħ��
//yueping.h
//2001-03-26

AUTOCOMBINE_BEGIN(CIyueping);

virtual void create(int nFlag = 0)		
{
	set_name("����ħ��", "yueping");

	set("base_value", 1);
	set("base_weight", 1500);

	set_amount(1);
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(! me->is_fighting())
		return notify_fail("����ħ��ֻ����ս����ʹ�ã�");

	if(me->query("mp") < 50)
		return notify_fail("��ķ������㡣");

	me->add("mp", -50);
	CContainer * env = load_room("pk");
	if(!env->query("mj/start"))
	{
		message_vision("$YEL$N�ͳ�һ������ħ�䣬���������дʣ�ɲʱ����ػ谵����ս����Χ����������һ���¹����ϡ�", me);
		CContainer * env = me->environment();
		
		int lock = env->query("room_locked");
		env->set("room_locked", lock | FIGHT_NO_JOIN);
		
		env->set("no_guard", "����ͼ�ۿ�ս�������һ������ѣ��������۾���");
		env->set("lock_msg", "����ͼ����ս�������һ���������㵯�˻�����");
	}
	else
	{
		message_vision("$YEL$N�ͳ�һ������ħ�䣬���������дʣ���Ȼ����Ѫһ�������е�����ħ���ʱ������Ƭ�Ĵ�ɢȥ��", me);
	}
	destruct(this);
	return 1; 
}

AUTOCOMBINE_END;




