CONDITION_BEGIN(CCbingpo_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;

	if( ! me->Query(IS_LIVING) )
	{
		tell_room(me->environment(), snprintf(msg, 255, "%sʹ��غ���һ����", me->name()), me);
	}
	else 
	{
		tell_object(me, "$HIRͻȻһ���溮Ϯ�������еı������붾�����ˣ�" );
		tell_room(me->environment(), snprintf(msg, 255, "%s������ɫ����,ȫ����,�����ж��Ѿ������ˡ�", me->name()), me);
    }
   
	me->receive_wound("hp", 25 + random(50));
	if ( me->querymap_temp("powerup") )		//����POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}

	duration -- ;
	return CND_CONTINUE;
}

CONDITION_END;