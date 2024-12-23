CONDITION_BEGIN(CCbonze_jail);

virtual int update_condition(CChar *me, LONG & duration)
{
	if (duration < 1) 
	{
		me->move(load_room("少林"));
		tell_room(me->environment(), "只听乒地一声，你吓了一跳，定睛一看，原来是一个昏昏沉沉的家伙从大门里被扔了出来！", me);
		tell_object(me, "只觉一阵腾云驾雾般，你昏昏沉沉地被扔出了少林寺！");
		me->set("start_city", START_ROOM);
		return 0;
	}

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;