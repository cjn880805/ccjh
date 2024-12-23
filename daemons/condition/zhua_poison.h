CONDITION_BEGIN(CCzhua_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if(! me->Query(IS_LIVING) ) 
	{
		message_vision("$nʹ���������.", me);
	}
	else 
	{
		tell_object(me, "$HIR��Ȼһ˿��������������,�����Ľ�������֫�ٺ�.ԭ�����е���Ѫ��ץ�����ˣ�");
		tell_room(me->environment(), snprintf(msg, 255, "%s������ͻȻһ�����,����ҧ�ÿ������졣\n��Ȼ����һ������,����¶��ʹ��������Ц�ݡ�", me->name()), me);
	}
    
	me->receive_wound("hp", 25 + random(20));
    duration -= random(3);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;