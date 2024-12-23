CONDITION_BEGIN(CCwuduz_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if( ! me->Query(IS_LIVING) ) 
	{
		message_vision("$N痛苦地呻吟了一声。", me);
	}
	else 
	{
		tell_object(me, "$HIR忽然你双颊发红，全身发烫，你所中的五毒神掌发作了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s满脸通红，双目发直，扑通一声摔倒在地。", me->name()), me);
   }
 
	me->receive_wound("hp", 25 + random(30));
    duration --;

    if ( me->querymap_temp("powerup") )		//消除POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;