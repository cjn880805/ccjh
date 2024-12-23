CONDITION_BEGIN(CCprostitute);

virtual int update_condition(CChar *me, LONG & duration)
{
	if (duration < 1)
	{
		tell_object(me, "你获得自由了！");
		me->del("value");		
		return 0;
	}

	CContainer * env = me->environment();

	if ( DIFFERSTR(env->querystr("base_name"), "扬州丽春院二楼"))
	{
		tell_object(me, "丽春院龟公出现在你身边：你能跑哪里去！快回去接客！");
		message_vision("丽春院龟公突然出现，不由分说，拉了$N就走。", me);
		me->move(load_room("扬州丽春院二楼"));
	}
	
	duration --;
	return CND_CONTINUE;
}

CONDITION_END;