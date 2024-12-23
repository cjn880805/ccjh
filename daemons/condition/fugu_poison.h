CONDITION_BEGIN(CCfugu_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;
	if( me->query("门派/thd/fugu") < 1 )
	{
		duration--;
		return 0;
	}

	if(! me->Query(IS_LIVING) ) 
	{
		message_vision("$n凄惨地呻吟着。", me);
	}
	else 
	{
		tell_object(me, "$HIR忽然一丝热流自体内升起,缓缓的浸入你四肢百骸。原来你中的「附骨钉」之毒发作了！");
		tell_room(me->environment(), snprintf(msg, 255, "%s的身子突然一阵颤抖,牙关咬得咯咯作响。\n忽然打了一个哆嗦,脸上一阵扭曲,好像万分痛苦。", me->name()), me);
	}
    
	me->receive_wound("hp", 25 + random(20));
	me->add("mp", -(10 + random(20)));
	if(me->query("mp")<0)
		me->set("mp",0l);

	if ( me->querymap_temp("powerup") )		//消除POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}
    
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;