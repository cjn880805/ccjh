CONDITION_BEGIN(CCpoison_sandu);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration < 1 ) return 0;

	me->receive_wound("hp", 10);
    me->receive_damage("hp", 10);
	tell_object(me, "������ڶ����ڷ��������ˣ�");
	
	duration--;

	return CND_CONTINUE;
}

CONDITION_END;