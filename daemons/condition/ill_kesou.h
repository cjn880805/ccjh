CONDITION_BEGIN(CCill_kesou);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if( ! me->Query(IS_LIVING))
	{
		message_vision("$N嘶哑着嗓子咳了两声，看来是病了。", me);
	}
	else 
	{
		tell_object(me, "你嘶哑着嗓子咳了两声，然后又连续咳了好一阵，看来是病了不轻！");
		tell_room(me->environment(), snprintf(msg, 255, "%s的身子弓着身子晃了两晃，嘶哑着嗓子咳了两声，看来是病了。", me->name()), me);
	}
	
	me->receive_wound("hp", 1);
	me->receive_damage("hp", 1);
	duration --;

	return CND_CONTINUE;
}

CONDITION_END;