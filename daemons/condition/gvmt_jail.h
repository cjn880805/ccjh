CONDITION_BEGIN(CCgvmt_jail);

virtual int update_condition(CChar *me, LONG & duration)
{
	if (duration < 1) 
	{
		me->move(load_room("/wizhome/sharkhome/jyguan/guangchang"));	//
		tell_room(me->environment(), "ֻ��ƹ��һ����������һ��������һ����\nԭ����һ���������ļһ�Ӵ����ﱻ���˳�����", me);
		tell_object(me, "ֻ��һ�����Ƽ���㣬��������ر��ӳ����γ�Ӫ��");
		me->set("start_city", START_ROOM);
		return 0;
	}

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;