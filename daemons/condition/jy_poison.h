CONDITION_BEGIN(CCjy_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;

	if( me->Query(IS_LIVING) ) 
	{
		message_vision("$N痛苦地哼了一声。", me);
	}
	else 
	{
		tell_object(me, "忽然一阵刺骨的奇寒袭来，你中的九阴白骨爪毒发作了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s的身子突然晃了两晃，牙关格格地响了起来。", me->name()), me);
	}
    
	me->receive_wound("hp",10 + random(40));
    duration --;
      
	if ( me->querymap_temp("powerup") )		//消除POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}

	return CND_CONTINUE;
}

CONDITION_END;