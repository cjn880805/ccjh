CONDITION_BEGIN(CCrose_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	me->receive_damage("hp", 10);
	duration --;
	tell_object(me, "$HIR���еĻ�õ�嶾�����ˣ�");

	if( duration < 1 ) return 0;

	return CND_CONTINUE;
}

CONDITION_END;