CONDITION_BEGIN(CCzhua_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if(! me->Query(IS_LIVING) ) 
	{
		message_vision("$n痛苦地呻吟着.", me);
	}
	else 
	{
		tell_object(me, "$HIR忽然一丝热流自体内升起,缓缓的浸入你四肢百骸.原来你中的凝血神抓发作了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s的身子突然一阵颤抖,牙关咬得咯咯作响。\n忽然打了一个哆嗦,脸上露出痛苦而诡异的笑容。", me->name()), me);
	}
    
	me->receive_wound("hp", 25 + random(20));
    duration -= random(3);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;