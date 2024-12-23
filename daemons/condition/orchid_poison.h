CONDITION_BEGIN(CCrainbow_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
		message_vision("$n��ͷһ���³�һ����ɫ��Ѫ��", me);
		tell_object(me, "$CYN���е�$HIW�嶾������$CYN�����ˣ�");
		tell_room(me->environment(), snprintf(msg, 255, "%s��ͷһ���³�һ����ɫ����Ѫ��$GRN", me->name()), me);
    int m;
	m=50*(20-duration);
	if (m<1)
		m=1;
	me->receive_wound("hp", m );
    duration -= random(3);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;