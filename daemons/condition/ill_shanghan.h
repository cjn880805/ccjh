CONDITION_BEGIN(CCill_shanghan);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration < 1 ) return 0;
	
	message_vision("$N冷不丁打了个冷战，头昏沉沉的，好象是得伤寒病了。", me);
	
	me->receive_wound("hp", 1);
	me->receive_damage("hp", 1);
	duration --;

	return CND_CONTINUE;
}

CONDITION_END;