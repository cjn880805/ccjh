CONDITION_BEGIN(CCsanxiao_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	me->receive_wound("hp", 500);
	me->receive_damage("hp", 500);
	duration --;
	
	message_vision("$N���Ϻ�Ȼ¶�������һЦ����������Ц��ңɢ�����ˣ�", me);
	
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;