CONDITION_BEGIN(CCvote_suspension);

virtual int update_condition(CChar *me, LONG & duration)
{
	if (duration < 1) 
	{
		tell_object(me, "�۲������������ֿ���ͶƱ�ˣ�");
		me->del("vote/deprived");
		return 0;
	}

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;