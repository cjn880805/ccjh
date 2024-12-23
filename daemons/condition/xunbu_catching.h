//接受巡捕追杀
//lanwood 2001-04-14

CONDITION_BEGIN(CCxunbu_catching);

int update_condition(CChar *me, LONG & duration)
{
	//判断是否过期，消除罪恶记录
	/*
	if(current_time > me->query("kill/free"))	
	{
		me->del("kill/guilt");
		return 0;
	}
	*/
	if( me->query("kill/guilt") < 150 ) return 0;	

	if(random(5)) return CND_CONTINUE;

		//1，判断是否在城市。
		CContainer * env = me->environment();
		
		if(! env) return CND_CONTINUE;
		if(! env->query("city") && duration < 5) return CND_CONTINUE;
		
		//2，判断场景里是否已经有巡捕。
		CNnpcmirror * xunbu;

		xunbu = (CNnpcmirror *)env->PresentName("monster_xunbu", CChar::IS_NPC);

		if(! xunbu )
		{
			xunbu = (CNnpcmirror *)load_npc("monster_xunbu");
			xunbu->move(env);			
		}	
		
		message_vision("突然一道人影闪过，$N拦在$n身前，喝道：快些跟我回去受审！", xunbu, me);
		message_vision("$N眉头一皱，冷哼一声道，你算是什么东西！", me);
		((CNnpcmirror *)xunbu)->catch_ob(me);		
		
	return CND_CONTINUE;
}



CONDITION_END;