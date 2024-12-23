CONDITION_BEGIN(CClinji_longhe);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration == 0 )
	{
		tell_object(me, "忽然你觉得全身懒洋洋的，连个小指头也不想动了，原来你的龙鹤庄收功了！");
		me->add("con", - me->query("linji/con"));
		me->del("linji/con");
		return 0;
	}

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;