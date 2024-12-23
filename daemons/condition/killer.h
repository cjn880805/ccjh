CONDITION_BEGIN(CCkiller);

virtual int update_condition(CChar *me, LONG & duration)
{
	if (duration < 1) 
	{
		tell_object(me, "官府不再通缉你了！");
		return 0;
	}

	duration --;
	
	return CND_CONTINUE;
}

CONDITION_END;