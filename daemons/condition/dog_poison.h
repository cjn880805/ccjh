CONDITION_BEGIN(CCdog_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;

	if(! living(me)) 
	{
		message_vision("$N忽然汪汪地叫了两声，看来是疯狗病发作了。", me);
	}
	else 
	{
		tell_object(me, "忽然一阵头昏眼花，你中的疯狗毒发作了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s的嘴角流下口水，汪汪地叫了两声，看来是疯狗病发作了。", me->name()), me);
	}
    
	me->receive_wound("hp",1 + random(4));
    duration --;
      
	if ( me->querymap_temp("powerup") )		//消除POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}

	return CND_CONTINUE;
}

CONDITION_END;