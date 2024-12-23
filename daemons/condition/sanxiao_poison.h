CONDITION_BEGIN(CCsanxiao_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	me->receive_wound("hp", 500);
	me->receive_damage("hp", 500);
	duration --;
	
	message_vision("$N脸上忽然露出诡异的一笑，看来是三笑逍遥散发作了！", me);
	
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;