CONDITION_BEGIN(CCcongtu);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration < 1 ) return 0;

	me->receive_wound("hp", 10);
    me->receive_damage("hp", 10);
	tell_object(me, "������ڼ��������������ݣ��·������ѵ����ڸ����ҽʣ�");
	
	duration--;

	return CND_CONTINUE;
}

CONDITION_END;