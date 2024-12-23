CONDITION_BEGIN(CCdsy_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration < 1 ) return 0;
	if( ! me->Query(IS_LIVING) ) 
	{
		message_vision("$HIG$N眉眼歪斜，舌头不由自主地吐了出来，一串串黑泡沫顺着舌尖往下淌。\n", me);
	}
	else if(me->query("eff_hp") > me->query("max_hp")/2) 
	{
		tell_object(me, "$CYN你感觉中掌之处犹如火灼，全身乏力，犹如散架。\n" );
	}
	else if(me->query("eff_hp") > me->query("max_hp")/4) 
	{
		tell_object(me, "$CYN你中掌之处开始溃烂发臭，招来了几只苍蝇，四肢渐渐肿了起来。\n");
	}
	else
	{
		tell_object(me, "$CYN掌毒已经侵入五脏六腑，你神智逐渐迷失，感到对这个世界无限地留恋。。。\n" );
		message_vision("$HIG$N突然象烂泥似地瘫倒在地，全身流脓，发出一阵阵的恶臭，头发一束束地脱落，随风飘散。\n", me);
	}
	
	me->receive_wound("hp", 25 + random(30));
	duration --;
	
	if ( me->querymap_temp("powerup") )		//消除POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}
	
	if( duration < 1) return 0;
	return CND_CONTINUE;
}

CONDITION_END;