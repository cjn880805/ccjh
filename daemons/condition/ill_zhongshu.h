CONDITION_BEGIN(CCill_zhongshu);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration < 1 ) return 0;
	
    message_vision("$Nͷ�ؽ��ᣬ���ŷ��ȣ������������ˡ�", me);
    me->receive_wound("hp", 1);
	me->receive_damage("hp", 1);
	duration --;

	return CND_CONTINUE;
}

CONDITION_END;