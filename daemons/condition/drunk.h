CONDITION_BEGIN(CCdrunk);

virtual int update_condition(CChar *me, LONG & duration)
{
	int limit;
	char msg[255];

	limit = (me->query("con") + me->query("max_mp") / 50) * 2;

	if( duration > limit &&	me->Query(IS_LIVING))
	{
		me->unconcious();
		return 0;
	} 
	else if(! me->Query(IS_LIVING) ) 
	{
		message_vision("$N打了个隔，不过依然烂醉如泥。", me);
	} 
	else if( duration > limit/2 ) 
	{
		tell_object(me, "你觉得脑中昏昏沉沉，身子轻飘飘地，大概是醉了。");
		tell_room(me->environment(), snprintf(msg, 255, "%s摇头晃脑地站都站不稳，显然是喝醉了。", me->name()), me);
		me->receive_damage("hp", 10);
	} 
	else if( duration > limit/4 ) 
	{
		tell_object(me, "你觉得一阵酒意上冲，眼皮有些沉重了。");
		tell_room(me->environment(), snprintf(msg, 255, "%s脸上已经略显酒意了。", me->name()), me);
		me->receive_healing("hp", 10);
	}

	if( ! duration ) return 0;

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;