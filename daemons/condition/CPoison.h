CONDITION_BEGIN(CCPoison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( ! me->Query(IS_LIVING) )
	{
		snprintf(msg, 255, "%sʹ��غ���һ����", me->name());
		MessageVision(me, "chat", msg);
	}
	else 
	{
		snprintf(msg, 255, "%s������ͻȻ�������Σ����ظ�������������", me->name());
		MessageVision(me, "tell", "��Ȼһ��̹ǵ��溮Ϯ�������еĺ��������ˣ�");
		MessageVision(me, "chat", msg);
	}
    
	me->receive_damage("hp", 25);
    duration --;
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;