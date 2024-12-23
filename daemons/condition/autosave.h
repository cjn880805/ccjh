CONDITION_BEGIN(CCautosave);

virtual int update_condition(CChar *me, LONG & duration)
{
	if (duration == 1)
	{
		tell_object(me, "【存盘】您的档案已经自动存盘。");
		me->Save();
	}

	duration ++;
	if(duration >12)
		duration = 1;
	
	return CND_CONTINUE;
}

CONDITION_END;