CONDITION_BEGIN(CCzm_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if( ! me->Query(IS_LIVING)) 
	{
		message_vision("$N痛苦地哼了一声。",me);
	}
	else 
	{
		tell_object(me, "$HIR忽然一阵刺骨的奇痛袭来，你中的子母飞针之毒发作了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s的身子突然晃了两晃，脸上一阵扭曲,好像万分痛苦。", me->name()), me);
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