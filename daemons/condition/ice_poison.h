CONDITION_BEGIN(CCice_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;

	if( ! me->Query(IS_LIVING) ) 
	{
		message_vision("$N���������ʹ��غ���һ����", me);
	}
	else 
	{
		tell_object(me, "$HIR��Ȼһ���溮�ӵ�������������֫�ٺ������еĺ������Ʒ����ˣ�");
		tell_room(me->environment(), snprintf(msg, 255, "%s������ͻȻ�������Σ����ظ�������������", me->name()), me);
	}
    
	me->receive_wound("hp",15 + random(10));
    duration --;
      
	if ( me->querymap_temp("powerup") )		//����POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}

   	return CND_CONTINUE;
}

CONDITION_END;