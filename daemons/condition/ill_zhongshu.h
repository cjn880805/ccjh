CONDITION_BEGIN(CCill_zhongshu);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration < 1 ) return 0;
	
    message_vision("$N头重脚轻，脑门发热，看来是中暑了。", me);
    me->receive_wound("hp", 1);
	me->receive_damage("hp", 1);
	duration --;

	return CND_CONTINUE;
}

CONDITION_END;