CONDITION_BEGIN(CClinji_zhixin);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration == 0 )
	{
		tell_object(me, "忽然你头脑里感到一阵空白，原来你的之心庄收功了，你顿时觉得自己还是个大笨木瓜！");
		me->add("int", - me->query("linji/int"));
		me->del("linji/int");
		return 0;
	}

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;