CONDITION_BEGIN(CCautosave);

virtual int update_condition(CChar *me, LONG & duration)
{
	if (duration == 1)
	{
		tell_object(me, "�����̡����ĵ����Ѿ��Զ����̡�");
		me->Save();
	}

	duration ++;
	if(duration >12)
		duration = 1;
	
	return CND_CONTINUE;
}

CONDITION_END;