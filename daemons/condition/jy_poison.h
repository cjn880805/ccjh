CONDITION_BEGIN(CCjy_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;

	if( me->Query(IS_LIVING) ) 
	{
		message_vision("$Nʹ��غ���һ����", me);
	}
	else 
	{
		tell_object(me, "��Ȼһ��̹ǵ��溮Ϯ�������еľ����׹�צ�������ˣ�");
		tell_room(me->environment(), snprintf(msg, 255, "%s������ͻȻ�������Σ����ظ�������������", me->name()), me);
	}
    
	me->receive_wound("hp",10 + random(40));
    duration --;
      
	if ( me->querymap_temp("powerup") )		//����POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}

	return CND_CONTINUE;
}

CONDITION_END;