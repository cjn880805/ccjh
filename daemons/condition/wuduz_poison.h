CONDITION_BEGIN(CCwuduz_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if( ! me->Query(IS_LIVING) ) 
	{
		message_vision("$Nʹ���������һ����", me);
	}
	else 
	{
		tell_object(me, "$HIR��Ȼ��˫�շ��죬ȫ���̣������е��嶾���Ʒ����ˣ�");
		tell_room(me->environment(), snprintf(msg, 255, "%s����ͨ�죬˫Ŀ��ֱ����ͨһ��ˤ���ڵء�", me->name()), me);
   }
 
	me->receive_wound("hp", 25 + random(30));
    duration --;

    if ( me->querymap_temp("powerup") )		//����POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;