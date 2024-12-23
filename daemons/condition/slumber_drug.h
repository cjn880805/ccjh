CONDITION_BEGIN(CCslumber_drug);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	tell_object(me, "你觉得脑中昏昏沉沉，心中空荡荡的，直想躺下来睡一觉。");
	tell_room(me->environment(), snprintf(msg, 255, "%s摇头晃脑地站都站不稳，显然是蒙汗药的药力发作了。", me->name()), me);

	duration --;
	me->add_temp("apply/armor",-3);
	me->add_temp("apply/damage",-3);
	me->add_temp("slumber",3);

	if( !duration )
	{
		tell_object(me, "你终于清醒起来。。" );
		me->add_temp("apply/armor",me->query_temp("slumber"));
		me->add_temp("apply/damage",me->query_temp("slumber"));
		me->delete_temp("slumber");
		me->UpdateMe();
		return 0;
	}
	me->UpdateMe();

	return CND_CONTINUE;
}

CONDITION_END;