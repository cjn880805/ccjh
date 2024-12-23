AUTOCOMBINE_BEGIN(CImofa_shoukao)

void create(int nFlag = 0)		
{
	set_name("ħ������", "mofa shoukao");
    set("base_weight", 500);
	set("base_value", 100);
 
	set_amount(1);
};

int do_use(CChar * me, CContainer * target)
{
	char msg[255];

	if(! me->is_fighting())
		return notify_fail("������ս����ʹ�á�");

	if(me->query("mp") < 50)
		return notify_fail("��ķ������㡣");

	me->add("mp", -50);

	message_vision("$HIR$N����$n��ȵ�����������ȥ�ɣ�", me, this);
	
	CContainer * env = me->environment();
	int lock = env->query("room_locked");
	env->set("room_locked", lock | FIGHT_NO_FLEE);

	tell_room(env, snprintf(msg, 255, "$HIWֻ��һ���׹�������%s��ħ����ס�ˣ�", env->name()));
	message_vision("$HIWֻ��һ���׹�������$N��ħ����ס�ˣ�", env);
		
	destruct(this);
	return 1;
};

int Can_Use()
{
	return 1;
};


AUTOCOMBINE_END;
