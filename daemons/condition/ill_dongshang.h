CONDITION_BEGIN(CCill_dongshang);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if( ! me->Query(IS_LIVING) ) 
	{
		message_vision("$N֫�彩ֱ�������������ˡ�", me);
	}
	else 
	{
		tell_object(me, "�����֫��ĩ��һ��ֱ�������Ǳ������ˣ�");
		tell_room(me->environment(), snprintf(msg, 255, "%s��֫�彩ֱ���ף������������ˡ�", me->name()), me);
	}
	
	me->receive_wound("hp", 1);
	me->receive_damage("hp", 1);
	duration --;

	return CND_CONTINUE;
}

CONDITION_END;