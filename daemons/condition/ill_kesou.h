CONDITION_BEGIN(CCill_kesou);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if( ! me->Query(IS_LIVING))
	{
		message_vision("$N˻����ɤ�ӿ��������������ǲ��ˡ�", me);
	}
	else 
	{
		tell_object(me, "��˻����ɤ�ӿ���������Ȼ�����������˺�һ�󣬿����ǲ��˲��ᣡ");
		tell_room(me->environment(), snprintf(msg, 255, "%s�����ӹ������ӻ������Σ�˻����ɤ�ӿ��������������ǲ��ˡ�", me->name()), me);
	}
	
	me->receive_wound("hp", 1);
	me->receive_damage("hp", 1);
	duration --;

	return CND_CONTINUE;
}

CONDITION_END;