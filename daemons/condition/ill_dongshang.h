CONDITION_BEGIN(CCill_dongshang);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if( ! me->Query(IS_LIVING) ) 
	{
		message_vision("$N肢体僵直，看来被冻伤了。", me);
	}
	else 
	{
		tell_object(me, "你觉得肢体末端一阵僵直，看来是被冻伤了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s的肢体僵直青肿，看来被冻伤了。", me->name()), me);
	}
	
	me->receive_wound("hp", 1);
	me->receive_damage("hp", 1);
	duration --;

	return CND_CONTINUE;
}

CONDITION_END;