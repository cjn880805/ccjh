AUTOCOMBINE_BEGIN(CImofa_shoukao)

void create(int nFlag = 0)		
{
	set_name("魔法手铐", "mofa shoukao");
    set("base_weight", 500);
	set("base_value", 100);
 
	set_amount(1);
};

int do_use(CChar * me, CContainer * target)
{
	char msg[255];

	if(! me->is_fighting())
		return notify_fail("必须在战斗中使用。");

	if(me->query("mp") < 50)
		return notify_fail("你的法力不足。");

	me->add("mp", -50);

	message_vision("$HIR$N举起$n大喝道：都给我死去吧！", me, this);
	
	CContainer * env = me->environment();
	int lock = env->query("room_locked");
	env->set("room_locked", lock | FIGHT_NO_FLEE);

	tell_room(env, snprintf(msg, 255, "$HIW只间一道白光闪过，%s被魔法锁住了！", env->name()));
	message_vision("$HIW只间一道白光闪过，$N被魔法锁住了！", env);
		
	destruct(this);
	return 1;
};

int Can_Use()
{
	return 1;
};


AUTOCOMBINE_END;
