CONDITION_BEGIN(CClinji_tiandi);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration == 0 )
	{
		tell_object(me, "忽然你心里头感到一阵失落，原来你的天地庄收功了，你顿时倍感红颜老去之叹！");
		me->add("per", - me->query("linji/per"));
		me->del("linji/per");
		return 0;
	}

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;