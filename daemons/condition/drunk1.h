CONDITION_BEGIN(CCdrunk1);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if(! me->Query(IS_LIVING) ) 
	{
		message_vision("$N打了个隔，不过依然烂醉如泥。", me);
	} 
	else if( me->query("yuandna/jiou/sos_level")>2 && me->Query(IS_LIVING)) 
	{
		tell_object(me, "你就地一躺，大醉而眠。");
		tell_room(me->environment(), snprintf(msg, 255, "%s打了个隔，就地一躺，大醉而眠。", me->name()), me);
		me->unconcious();
		me->set("yuandna/jiou/sos_level",2);
	}
	else if( me->query("yuandna/jiou/sos_level")==2) 
	{
		tell_object(me, "你觉得头昏昏沉沉的，可能要醉了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s摇头晃脑地站都站不稳，显然是喝醉了。", me->name()), me);
		me->receive_damage("hp", 10);
	} 
	else if( me->query("yuandna/jiou/sos_level")==1) 
	{
		tell_object(me, "你觉得头昏昏沉沉的！");
		tell_room(me->environment(), snprintf(msg, 255, "%s脸上已经略显酒意了。", me->name()), me);
		me->receive_healing("hp", 10);
	}

	if( ! duration ) return 0;

	duration --;

	time_t t;
	time(&t);
	me->set("yuandna/jiou/time",t);

	return CND_CONTINUE;
}

CONDITION_END;