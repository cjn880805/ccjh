CONDITION_BEGIN(CCvote_clear);

virtual int update_condition(CChar *me, LONG & duration)
{
	if (duration < 1) 
	{
		if (duration > -5)
			tell_object(me, "因为响应的人不多，对你的投票取消了。");
	    
		me->del("vote/reason");
        me->del("vote/juror");
        me->del("vote/count");
		            
		return 0;
	}
	
	duration --;
	return CND_CONTINUE;
}

CONDITION_END;