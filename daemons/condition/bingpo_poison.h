CONDITION_BEGIN(CCbingpo_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;

	if( ! me->Query(IS_LIVING) )
	{
		tell_room(me->environment(), snprintf(msg, 255, "%s痛苦地哼了一声。", me->name()), me);
	}
	else 
	{
		tell_object(me, "$HIR突然一阵奇寒袭来，你中的冰魄银针毒发作了！" );
		tell_room(me->environment(), snprintf(msg, 255, "%s渐渐脸色铁青,全身发紫,看来中毒已经很深了。", me->name()), me);
    }
   
	me->receive_wound("hp", 25 + random(50));
	if ( me->querymap_temp("powerup") )		//消除POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}

	duration -- ;
	return CND_CONTINUE;
}

CONDITION_END;