CONDITION_BEGIN(CCfugu_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if( me->query("����/thd/fugu") < 1 )
	{
		duration--;
		return 0;
	}

	if(! me->Query(IS_LIVING) ) 
	{
		message_vision("$n��ҵ������š�", me);
	}
	else 
	{
		tell_object(me, "$HIR��Ȼһ˿��������������,�����Ľ�������֫�ٺ���ԭ�����еġ����Ƕ���֮�������ˣ�");
		tell_room(me->environment(), snprintf(msg, 255, "%s������ͻȻһ�����,����ҧ�ÿ������졣\n��Ȼ����һ������,����һ��Ť��,�������ʹ�ࡣ", me->name()), me);
	}
    
	me->receive_wound("hp", 25 + random(20));
	me->add("mp", -(10 + random(20)));
	if(me->query("mp")<0)
		me->set("mp",0l);

	if ( me->querymap_temp("powerup") )		//����POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}
    
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;