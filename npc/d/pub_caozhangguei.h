//曹掌柜(新手送菜任务NPC)
//秦波 2003、5、23

CNpc * random_npc();

NPC_BEGIN(CNpub_caozhangguei);

void create()
{
	set_name("曹掌柜","cao zhangguei");

	set("icon", pub_boss);
	set("gender", "男性" );
	set("title", "酒楼老板" );
	set("age", 42);
	set("long","他就是这楼外楼的大掌柜，看起来和蔼可亲。");
	set("combat_exp", 100);
	set("nkgain", 30);

	set("attitude", "friendly");
	set("no_get", "1");

	set("task_open", 1);	//任务开放
	set("no_kill",1);
	set("no_huan",1);
	
};

void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 3, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	char msg[255];
	if(! who) return;
    if(who->query("combat_exp")>50000 || me->query("level")>30) return;
	if(who->query_temp("cao/overtime")) return;

	tell_object(who,"\n曹掌柜满面焦虑，叹气道：“新来的伙计手脚太慢，这么多的客官订的饭菜，可怎么来得及送呀！”");
	tell_object(who, snprintf(msg, 255,"曹掌柜一见你来不禁大喜，连声说道：“这位%s,不知是否有兴趣来帮我跑堂送些客官订的饭菜？”\n", query_respect(me)));
		

	return;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task_open"))
	{
		if(me->query("combat_exp")<50000 && me->query("level")<30)
		{
			me->set_temp("cao/任务", 1);
			if(!me->query_temp("cao/overtime"))
				AddMenuItem("向曹掌柜索要任务", "$0getquest $1", me);
			else
			{
				AddMenuItem("向曹掌柜询问任务", "$0askquest $1", me);
				AddMenuItem("向曹掌柜要求清除任务", "$0cleanquest $1", me);
			}
			SendMenu(me);	
		}
		else
			return CNpc::do_talk(me,ask);
	}
	else
		return CNpc::do_talk(me,ask);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("cao/任务"))
	{
		me->delete_temp("cao/任务");
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);
		if(strcmp(comm, "getquest") == 0)
			return do_gq(me);
		if(strcmp(comm, "cleanquest") == 0)
			return do_cq(me);
	}
	return CNpc::handle_action(comm, me, arg);
}


int do_aq(CChar * me)
{
	char msg[255];
	if(!me->query_temp("cao/overtime"))
	{
	    say("曹掌柜满面焦虑，叹气道：“新来的伙计手脚太慢，这么多的客官订的饭菜，可怎么来得及送呀！”", me);
		say(snprintf(msg, 255,"曹掌柜一见你来不禁大喜，连声说道：“这位%s,不知是否有兴趣来帮我跑堂送些外卖？”",query_respect(me)), me);
		SendMenu(me);
		return 1;
	}
	long i;
	long e;
	
	i=current_time;
	e=me->query_temp("cao/overtime");
	if (i>e)
	{
	    tell_object(me,"曹掌柜拉着一张长脸，看着你“哼”了一声。");
		say("对不起……时间已经过了，你没有完成任务。", me);
		SendMenu(me);
		return 1;
	}
	i=e-i;
	e=i/60;
	i=i-e*60;

    say("曹掌柜微微有些不快，皱着眉头说道：“你这个年轻人，怎么记性如此不好。”", me);
	say(snprintf(msg, 255, "曹掌柜说道：“%s(%s)已经在%s等了很久了，你还不快快送去，要是再过%d分%d秒还是没到的话，客官一定会发怒的。”", 
		me->querystr_temp("cao/name"),me->querystr_temp("cao/id"), me->querystr_temp("cao/map"),e,i), me);
	SendMenu(me);
	return 1;
}


int do_cq(CChar * me)
{
	char msg[255];
	if(!me->query_temp("cao/overtime"))
	{
		say(snprintf(msg, 255,"曹掌柜满面惊讶的说道：“这位%s,此话从和说起？”",query_respect(me)), me);
		SendMenu(me);
		return 1;
	}
	say("曹掌柜满脸不快，说道：“慢手慢脚的，怎么做事的。先别说别的，刚才那位客官订的饭菜总共500文，你先掏了再说。”", me);
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")==500)
	{
		who->delete_temp("cao/id");
		who->delete_temp("cao/name");
		who->delete_temp("cao/map");
		who->delete_temp("cao/overtime");
		who->delete_temp("cao/count");	// Clear Finish 	
		destruct(ob);
		return 1;
	}
	return 0;
}

//返回npc的方位
const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//失败
	if(env->query("no_fight")) return 0;	//非战斗区。
	if(env->query("wiz_room")) return 0;	//巫师房间。
	if(env->query("renwu")) return 0;		//特殊任务房间。
	if(env->query("sleep_room")) return 0;	//休息区。
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//玩家住宅
	if(EQUALSTR(env->querystr("area"), "野外")) return 0;	//野外场景
	if(EQUALSTR(env->querystr("id"), "fight_room")) return 0;	//战斗场景
	if(atoi(env->querystr("owner"))) return 0;	//玩家住宅

	while(env->environment())
		env = env->environment();

	return env->name(1);
}

int do_gq(CChar * me)
{
	char msg[255];
	long i;
	long e;
	i=current_time;
	e=me->query_temp("cao/overtime");
	if(me->query_temp("cao/overtime"))
	{
		say("你上一个任务没有完成……", me);
		SendMenu(me);
	}
	
	if (me->query("combat_exp") > 10000)
		return notify_fail("曹掌柜满面堆笑道：这位客官，你这不是在消遣我嘛，我怎敢请您来做这些杂事呀！");
	
	if (me->is_busy())
		return notify_fail("你现在很忙。。。");

	//随机取一个NPC的场景	
	CNpc * npc = random_npc();

	if(! npc) return notify_fail("曹掌柜叹气道：唉，不知为何，最近生意一直不好，没什么客官愿意上门了！");
	if(npc == this) return notify_fail("曹掌柜叹气道：唉，不知为何，最近生意一直不好，没什么客官愿意上门了！");	//自己竟然就是妖怪。呵呵。
	if(! living(npc)) return notify_fail("曹掌柜叹气道：唉，不知为何，最近生意一直不好，没什么客官愿意上门了！");	//这个NPC快不行了。
	if(DIFFERSTR(npc->querystr("race"), "人类") ) return notify_fail("曹掌柜叹气道：唉，不知为何，最近生意一直不好，没什么客官愿意上门了！");	//非人类NPC
	if(npc->query("no_kill")) return notify_fail("曹掌柜叹气道：唉，不知为何，最近生意一直不好，没什么客官愿意上门了！");	//是一般玩家不可能找到的随机怪物
	if(npc->query("mfnpc_lvl")) return notify_fail("曹掌柜叹气道：唉，不知为何，最近生意一直不好，没什么客官愿意上门了！");	//是梦泽山的随机怪物
	
	CContainer * env = npc->environment();

	//现在判断NPC大致的方位
	const char * area = position_npc(npc);
	if(! area ) return notify_fail("曹掌柜叹气道：唉，不知为何，最近生意一直不好，没什么客官愿意上门了！");	//这个NPC没有环境
	if(! area[0]) return notify_fail("曹掌柜叹气道：唉，不知为何，最近生意一直不好，没什么客官愿意上门了！");	//这个NPC在玩家房间或者战斗中。
	if(EQUALSTR(env->querystr("area"), "fight") ) return notify_fail("曹掌柜叹气道：唉，不知为何，最近生意一直不好，没什么客官愿意上门了！");	//这个NPC在玩家房间或者战斗中。
	if(EQUALSTR(env->querystr("area"), "野外") ) return notify_fail("曹掌柜叹气道：唉，不知为何，最近生意一直不好，没什么客官愿意上门了！");	//这个NPC在野外。
	if(env->query("renwu") ) return notify_fail("曹掌柜叹气道：唉，不知为何，最近生意一直不好，没什么客官愿意上门了！");	//这个NPC在特殊任务的房间中。
	
	me->set_temp("cao/id",npc->id(1));
	me->set_temp("cao/name",npc->name(1));
	me->set_temp("cao/map",env->name(1));
	
	say(snprintf(msg, 255, "曹掌柜说道：%s(%s)现在住在%s，昨日亲自过来订了一桌酒席，说好今天送去。", npc->name(1), npc->id(1),env->querystr("base_name")), me);
	int shuitime=300;
	i=400-me->query("level");
	i=i+shuitime;
	i=(i+random(i))/2;
	me->set_temp("cao/overtime",current_time+i);
	e=i/60;
	i=i-e*60;
	say(snprintf(msg, 255, "曹掌柜说道：现在时间已经耽误的差不多了，你赶快在%d分%d秒之内把这些菜给他送过去吧！", e,i), me);
	SendMenu(me);

	CContainer * ob=load_item("caiyao");
	ob->set("owner1",me->id(1));
	ob->set("cao/id",npc->id(1));
	ob->set("cao/name",npc->name(1));
	ob->set("cao/map",env->name(1));
	ob->move(me);

	me->set_temp("no_fei",1);
	me->set_temp("weight",me->Query_Weight());
	me->set_weight(5000000);
	return 1;
}

NPC_END;




