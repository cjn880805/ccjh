CONDITION_BEGIN(CCbonze_jail);

virtual int update_condition(CChar *me, LONG & duration)
{
	if (duration < 1) 
	{
		me->move(load_room("����"));
		tell_room(me->environment(), "ֻ��ƹ��һ����������һ��������һ����ԭ����һ���������ļһ�Ӵ����ﱻ���˳�����", me);
		tell_object(me, "ֻ��һ�����Ƽ���㣬��������ر��ӳ��������£�");
		me->set("start_city", START_ROOM);
		return 0;
	}

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;