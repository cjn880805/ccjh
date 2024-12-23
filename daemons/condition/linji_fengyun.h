CONDITION_BEGIN(CClinji_fengyun);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration == 0 )
	{
		tell_object(me, "忽然你觉得一股浊气自腰间猛向下沉去，顿时双足如灌铅般沉重，原来你的风云庄收功了！");
		me->add("dex", - me->query("linji/dex"));
		me->del("linji/dex");
		return 0;
	}

	duration --;

	return CND_CONTINUE;
}

CONDITION_END;