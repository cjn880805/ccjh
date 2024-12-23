CONDITION_BEGIN(CCss_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
   
	if(me->Query(IS_LIVING)) 
	{
		message_vision("$N凄惨地哼了一声。", me);
	}
	else 
	{
		tell_object(me, "$HIR忽然一股寒流夹着一阵灼热涌上心来，你中的生死符发作了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s突然倒在地上，双手在身上一阵乱抓。", me->name()), me);
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