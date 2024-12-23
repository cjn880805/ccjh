CONDITION_BEGIN(CCill_fashao);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration < 1 ) return 0;
	
	message_vision("$N的脸蛋烧得通红，看来是发高烧了。", me);
	
	me->receive_wound("hp", 1);
	me->receive_damage("hp", 1);
	duration --;

	return CND_CONTINUE;
}

CONDITION_END;