CONDITION_BEGIN(CCwuwen_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;

	if(! living(me)) 
	{
		message_vision("$N痛苦地哼了一声。", me);
	}
	else 
	{
		tell_object(me, "忽然一阵刺骨的巨痛袭来，你中的五文爪伤发作了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s痛苦不堪的大叫，五文派的武功天下无敌。", me->name()), me);
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