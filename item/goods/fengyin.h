//上古封印
//fengyin.h
//2001-02-09

AUTOCOMBINE_BEGIN(CIfengyin);

virtual void create(int nFlag = 0)		
{
	set_name("封印魔法", "fengyin");

	set("base_value", 150);
	set("base_weight", 1500);

	set_amount(1);
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	char str[255];
	string msg;

	if(! target || ! target->Query(IS_BOX))
		return notify_fail("封印魔法只能对箱子使用！");

	if(me->query("mp") < 100)
		return notify_fail("你的法力不足。");

	me->add("mp", -100);

	if(EQUALSTR(target->querystr("status"), "locked"))
	{
		msg = snprintf(str, 255, "$N捻了个响指，口中断喝一声：%s回来了！", query_self_rude(me));

		//解锁
		if(EQUALSTR(target->querystr("owner"), me->querystr("id")))
		{
			//是自己上的锁，一下子就能解开。
			msg += "只听碰的一声$n开了。";
			((CBox *)target)->UnLocked();
		}
		else
		{
			//不是自己上的锁，开起来要费些力气。
			if( ! ((CBox *)target)->UnLocked(6 * me->query("level")) )
			{
				msg += "只听碰的一声$n开了。";
			}
			else
			{
				msg += "结果$n纹丝不动！";
			}
		}
	}
	else
	{
		//上锁
		msg = "$N捻了个响指，口中喃喃念道：搬若菠萝蜜！！！只听啪的一声，飘下张封条封死了$n。";
		snprintf(str, 60, "%s的封印", me->name());
		
		((CBox *)target)->Locked(str, 30 + 30 * me->query("level"), me);		//锁死 每级增加60点耐久度
	}

	message_vision(msg.c_str(), me, target);
	destruct(this);

	return 1; 
}

AUTOCOMBINE_END;
