CONDITION_BEGIN(CCrainbow_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
		message_vision("$n只觉得一缕生气源源不断的自心脉流出。", me);
		tell_object(me, "$HIR你只觉得一缕生气源源不断的自心脉流出。");
		tell_room(me->environment(), snprintf(msg, 255, "%s突然愣住，整个人虚脱了一样。", me->name()), me);
    
	me->receive_wound("hp", (random(me->query("level"))+1)*(50-duration) );
    duration -= random(3);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;