CONDITION_BEGIN(CCrainbow_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
		message_vision("$n心头一软，吐出一口兰色的血。", me);
		tell_object(me, "$CYN你中的$HIW五毒铃兰瘴$CYN发作了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s心头一软，吐出一口兰色的鲜血。$GRN", me->name()), me);
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