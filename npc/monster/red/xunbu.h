//任务用标准NPC 可生成强度为玩家N倍的怪物。
//lanwood 2001-04-12
//巡捕 玩家杀手

MIRROR_BEGIN(CNmonster_xunbu);

void create()
{
	set_name("巡捕", "xun bu");
	
	set("icon", young_man1);
	set("shen_type", -1);
	
	set("chat_chance", 5);
	set("chat_chance_combat", 25);
	set("monster_lvl", 1000);	
	set("no_chan", 1);
	set("no_千环套狗", 1);
};

/*
void reward_killer(CChar * me)
{
//	me->set_temp("pending/PK_city", 1);
	//给杀死巡捕的人记过
	g_Combatd.PK_reward(me, this);	
}
*/

//杀死玩家
void finish_kill(CChar *me)
{
	char msg[255];

	int guilt = me->query("kill/guilt");
	
	guilt = guilt - query("xunbu_level") * 50;
	if(guilt < 0) guilt = 0;

	me->set("kill/guilt", guilt);
		
	tell_object(me, snprintf(msg, 255, "$HIY你被%s杀死，罪行减至%ld点。", name(1), guilt));
	g_Channel.do_channel(&g_Channel, NULL, "sys", 
		snprintf(msg, 255, "%s被%s杀死，罪行减到%ld点！", me->name(1), name(1), guilt));

	destruct(this);
}

char * chat_msg()
{
	CChar * me = (CChar *)environment()->present(querystr("finding"));
	if(me) catch_ob(me);
	else if(random(20))
		random_move();
	else
	{
		message_vision("$N匆匆离开了。", this);
		destruct(this);
	}

	return 0;
}

void init(CChar * me)
{
	if(! is_fighting() && userp(me))
	{
		remove_call_out(do_kill);
		call_out(do_kill, 3, me->object_id());
	}
}

static void do_kill(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who || ! who->query_condition("xunbu_catching")) return;
	if(me->is_fighting()) return;
	
	message_vision("$N一把扭住$n怒喝道：犯了案子也敢到处闲逛？", me, who);
	
	((CNmonster_xunbu *)me)->catch_ob(who);
}

void catch_ob(CChar * me)
{
	//根据等级派巡捕追杀玩家
		static struct 
		{
			char name[20];
			int diff;
		}lvl[6] = {
			{"巡捕房捕快", 12,},
			{"御用巡捕", 15,},
			{"金牌巡捕", 18,},
			{"赏金猎人", 20,},
			{"神秘客", 25,},
			{"玩家杀手", 30,}
		};

	int level = me->query_condition("xunbu_catching");
	if(level < 1) return;
	if(level > 6) level = 6;
/*	char msg[255];
	CContainer * env = me;
	while(env->environment())	env = env->environment();*/

	make_mirror(me, lvl[level - 1].diff);

	set_name( lvl[level - 1].name);
	set("xunbu_level", level);
	set_leader(me);
	set("finding", me->querystr("id"));
	if(random(2))
	{
		//杀死玩家
		CFightRoom * obj;
		CContainer * env = environment();
		obj = (CFightRoom *)load_item("fight_room");		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "巡捕办案现场", "fight_room_xunbu");		
		obj->move(env);

		move(obj);
		obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);	
		me->move(obj);
		obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
		obj->Begin_Fight(0);
	}
	else
	{
		//送到监狱
		int guilt = me->query("kill/guilt");
		if(random(guilt) > 100)
		{
			message_vision("$N扔出一条套锁，栓住了$n的脖子，向远方离去。", this, me);
			me->move(load_room("jy"));
			me->set("kill/guilt", 150);
			me->apply_condition("xunbu_catching", 0l);
			destruct(this);
		}
		else
		{
			message_vision("$N扔出一条套锁，企图栓住了$n的脖子，结果被$n逃脱了。", this, me);
		}
	}
}


/*	if(env->query("no_fight"))
	{
		env->set("no_fight", 0l);	//强迫此地可以战斗
		env->remove_call_out(do_nofight);
		env->call_out(do_nofight, 30);	//30秒后不可睡
	}

	me->kill_ob(this);

//作恶太多，强制死亡一次	
	int guilt = me->query("kill/guilt");
	if(guilt>200)
	{
		message_vision("$N一脚将$n踢的跪在地下，反手从背后抽出一柄御赐尚方宝剑，喝道：恶贼，你作恶多端，我今天要为民除害了！。", this, me);
		me->add("kill/guilt", -150);
		me->die();
		snprintf(msg, 255, "%s(%s)由于作恶多端，被巡捕在%s当场正法。", me->name(),me->id(), env->name());
		g_Channel.do_channel(&g_Channel, 0, "rumor", msg);
		destruct(this);
	}
//送到监狱
	else if(random(guilt) > 100)
	{
	
		message_vision("$N扔出一条套锁，栓住了$n的脖子，向远方离去。", this, me);
		me->move(load_room("jy"));
		me->set("kill/guilt", 50);
		me->apply_condition("xunbu_catching", 0l);
		destruct(this);
	}
	else
	{
		message_vision("$N扔出一条套锁，企图栓住了$n的脖子，结果被$n逃脱了。", this, me);
	}
}
*/
MIRROR_END;





