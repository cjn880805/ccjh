CONDITION_BEGIN(CCrainbow_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
		message_vision("$nֻ����һ������ԴԴ���ϵ�������������", me);
		tell_object(me, "$HIR��ֻ����һ������ԴԴ���ϵ�������������");
		tell_room(me->environment(), snprintf(msg, 255, "%sͻȻ�ס��������������һ����", me->name()), me);
    
	me->receive_wound("hp", (random(me->query("level"))+1)*(50-duration) );
    duration -= random(3);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;