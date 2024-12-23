CONDITION_BEGIN(CCwudu_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if( ! me->Query(IS_LIVING)) 
	{
		message_vision("$N痛苦地呻吟了一声。", me);
	}
	else 
	{
		tell_object(me, "$HIR忽然你感到一阵颤抖，你所中的五毒之气发作了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s的脸色突然一明一暗，连变五次。", me->name()), me);
	}
    
	me->receive_wound("hp",15 + random(10));
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