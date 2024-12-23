//seller.h
//武道我理·贩卖ＮＰＣ·台湾（改在泉洲）·出售木人
//Teapot 2001-02-08
CNpc * random_npc();

VENDOR_BEGIN(CNpub_robotseller);

void create()
{
	set_name("武道我理", "Wudao woli");
	set("title", "泉洲青龙会小贩　「木人已到！」");
	set("gender", "男性");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);

	set("increase", 28);			//生产速度
	set("zhiren", 20);
	set("muren_left",  20);	//木人存货
	set("price", 1500);		//价格

	set_inquiry("木人", inquiry_muren);

	carry_good("readingbot", 120);
	carry_good("exercisebot", 120);
	carry_good("practicebot", 120);
	//carry_good("transfer_tie", 10);
	carry_good("yueping", 100);
	set("no_huan",1);

	//call_out(do_makemuren, 3600);
};

//制造木人 一小时增加一次
static void do_makemuren(CContainer * ob, LONG param1, LONG param2)
{
	CVendor * me = (CVendor *)ob;

	int inc = me->query("zhiren");

	me->set("muren_left", 28);
	me->carry_good("readingbot", inc + random(inc));
	me->carry_good("exercisebot", inc + random(inc));
	me->carry_good("practicebot", inc + random(inc));
	//me->carry_good("transfer_tie", 3);
	//me->carry_good("transfer_tie", 20);

	me->call_out(do_makemuren, 3600);
}

static char * inquiry_muren(CNpc * me, CChar * who)
{
	static char msg[255];

	int left = me->query("muren_left");

	if(left) 
		return snprintf(msg, 255, "昨天新到的一批东西，给我%ld块就给你一个。现在还有%d个，不买没了……", me->query("price"), left);
	
	return "木人没货了，你再等等吧。";
}

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

	if(! who) return;

	if(random(2)==0)
	    message_vision("$n神秘的凑近$N耳边，道：我这里有刚进的木人，要不要来一个？", who, me);
	else
	    message_vision("武道我理看着自己的锈剑道：多情自古空余恨，此恨绵绵无绝期……", me);

	return;
}


// good:owner
// me:name areaname exp itemname overtime

int accept_object(CChar * who, CContainer * ob)
{
	if(who->is_busy())
		return notify_fail("你上一个动作还没有完成");

	if ( DIFFERSTR(ob->querystr("id"), "coin") || ob->query("value") < query("price") )
	{	
		say("武道我理奇怪的看了一眼，说：ギんぬオザれがあヴ？", who);
		SendMenu(who);
		return 0;
	}

	char msg[255];
	CChar * bot;

	if(ob->query("value")==2500 && who->query("tongren")>0)
	{
		bot = load_npc("pub_tongren");
		bot->set("owner",who->querystr("id"));
		bot->set_name( snprintf(msg, 40, "%s的铜人", who->name(1)));
		who->add("tongren",-1);
		if(who->query("tongren")<=0)
			who->del("tongren");
	}
	else if ( ob->query("value")==5000 && who->querymap("tradepro") )
	{
		who->set_temp("tradepro/money",1);
		destruct(ob);
		return 1;
	}
	else
	{
		if(query("muren_left") < 1)
		{
			say("武道我理遗憾的说：我去催促工匠赶制木人，你过会儿再来吧。", who);
			SendMenu(who);
			return 0;
		}
		
		add("muren_left", -1);
		
		bot = load_npc("pub_muren");
		bot->set("owner",who->querystr("id"));
		bot->set_name( snprintf(msg, 40, "%s的木人", who->name(1)));
	}

	//CRoom * room = load_room(global_room_name[random(MAX_ROOM_NUM)]);
	//如果玩家有家，直接送到玩家家里！ lanwood 2001-04-06
	CRoom * room = CRresident::get_my_house(who);
	if(room)
	{	
		message_vision(snprintf(msg, 255, "武道我理把钱来回点了三遍，略带忧伤地叹了口气，道：货已经派人送到%s啦！", room->name()), who);
		bot->move(room);
	}
	else	//否则放入当前场景，跟着玩家走。
	{
		message_vision("武道我理把钱来回点了三遍，略带忧伤地叹了口气，对$N说道：木人放到这里，快领走吧！", who);
		bot->move(environment());
		bot->set_leader(who);
	}

	who->start_busy(2);
	
	destruct(ob);
	return 1;
}


int do_talk(CChar *me, char * ask)
{
	if(query(me->querystr("tradepro/quest_killnpc_id"))==99)
	{
		return CNpc::do_talk(me, ask);
	}

	if(! me->is_fighting() )
	{
		char msg[255];
		AddMenuItem(snprintf(msg, 255,"向%s领取「仗剑江湖」任务",name()), "$0get_huan $1", me);
		if(me->querymap("tradepro"))
		{
			AddMenuItem("查询目前的「仗剑江湖」任务说明", "$0show_huan $1", me);
			if(query("取消"))
				AddMenuItem("请求「仗剑江湖」任务失败", "$0cancel_huan $1", me);
		}
		SendMenu(me);
	}
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "get_huan") == 0 )
		return do_huan(me);
	if(strcmp(comm, "show_huan") == 0 && me->querymap("tradepro") )
		return do_show(me);
	if(strcmp(comm, "cancel_huan") == 0 && me->querymap("tradepro") )
		return do_cancel_huan(me);
	
	return CNpc::handle_action(comm, me, arg);
}

int do_show(CChar * me)
{
	char msg[255];
	if(!me->query_temp("tradepro/money"))
	{
		say("你给我5000文钱，我就帮你查查你现在的任务是什么。", me);
		SendMenu(me);
		return 1;
	}
	me->delete_temp("tradepro/money");
	
	if(current_time > me->query("tradepro/quest_time"))
	{
		say("你来的太迟了，你的任务已经过期了。",me);
		SendMenu(me);
		me->del("tradepro");
		return 1;
	}
	switch(me->query("tradepro/index"))
	{
	case 1:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 去买 %s，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 2:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 去找 %s，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 3:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 杀掉 %s，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 4:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 抓获 %s，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 5:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 在 %s 地带巡逻，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_mp"),me->query("tradepro/quest_time")-current_time);
		break;
	case 6:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 前往 %s 讨回公道（杀死掌门大弟子），剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_mp"),me->query("tradepro/quest_time")-current_time);
		break;
	case 7:
		snprintf(msg, 255,"你现在的任务（第%d个）是：找到%s(%s)，让他到我这里来一下，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_killnpc_name"),
			me->querystr("tradepro/quest_killnpc_id"),me->query("tradepro/quest_time")-current_time);
		break;
	case 8:
		if(me->query("tradepro/quest_pro_index")==1)
		{
			snprintf(msg, 255,"你现在的任务（第%d个）是：为了有能力帮助 %s 而承诺提高自身的总经验到 %d，剩余时间是： %d 秒。",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->query("tradepro/quest_pro_point"),me->query("tradepro/quest_time")-current_time);
		}
		else
		{
			snprintf(msg, 255,"你现在的任务（第%d个）是：为了有能力帮助 %s 而承诺提高自身的声望到 %d，剩余时间是： %d 秒。",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->query("tradepro/quest_pro_point"),me->query("tradepro/quest_time")-current_time);
		}
		break;
	case 9:
		snprintf(msg, 255,"你现在的任务（第%d个）是：答应 %s 去保一次镖，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->query("tradepro/quest_time")-current_time);
		break;
	case 10:
		if(me->query("tradepro/quest_killnpc_time")-current_time>0)
		{
			snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 保护 %s 的 %s ，确保他在剩余时间的 %d 秒中不死。",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_area"),
				me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_killnpc_time")-current_time);
		}
		else
		{
			snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 保护 %s ，现在你已经完成了任务。",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->querystr("tradepro/quest_killnpc_name"));
		}
		break;
	case 11:
		snprintf(msg, 255,"你现在的任务（第%d个）是：给 %s 上贡 %d 两银子，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->query("tradepro/quest_item_numer"),me->query("tradepro/quest_time")-current_time);
		break;
	case 12:
		snprintf(msg, 255,"你现在的任务（第%d个）是：给 %s 送去 %s，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 13:
		snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 收集 %s %d份，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_item_numer"),me->query("tradepro/quest_time")-current_time);
		break;
	case 14:
			snprintf(msg, 255,"你现在的任务（第%d个）是：帮助 %s 获得 %s 的画像，剩余时间是： %d 秒。",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	}
	say(msg, me);
	SendMenu(me);
	return 1;
}

int do_cancel_huan(CChar * me)
{
	if(!me->querymap("tradepro"))
	{
		say("你并没有领取任务……", me);
		SendMenu(me);
		return 1;
	}
	say("我对你真的是太失望了。。",me);
	SendMenu(me);
	me->del("tradepro");
	return 1;
}

const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//失败
	if(env->query("no_fight")) return 0;	//非战斗区。
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//玩家住宅

	while(env->environment())
		env = env->environment();

	return env->name(1);
}

int do_huan(CChar * me)
{
	if(me->query("trade/score")< 50000)
		return notify_fail("很抱歉，这个任务只能由萧大人亲自授予的「红顶商人」才可以去做。");

	if(me->query("level")<60)
		return notify_fail("为了你的安全，还是请你继续加强修为到60级后再来找我吧！");
	
	if(me->query("balance") < 100000)
		return notify_fail("请在你的帐号里存足十万！");

	char msg[255];

	if(me->querymap("tradepro") )
		return notify_fail("你不是已经接过任务了吗？");

	static char index2[5][255] =
	{
		"好久不见$HIW%s$COM了，麻烦你去找到他说我想念他。",
			"$HIW%s$COM前段时间来上门来拜访，我一直都没时间回访,烦请你替我去看看他。",
			"$HIW%s$COM已经失踪很久了,你是否有空替我去找下他，看看最近他怎么样了？",
			"我很想念$HIW%s$COM，你能不能替我送个口信给他，并替我问候他。",
			"前段时间我答应$HIW%s$COM去游山玩水的，但一直忙，请你跟他说声我最近有空，可以一起结伴而行。",
	};

	me->add("balance",-100000);

	CNpc * npc;

	int i;
	const char * area;
	for(i=0;i<10000;i++)
	{
		npc = random_npc();
		
		if(! npc ) continue;
		if(! living(npc)) continue;	//这个NPC快不行了。
		if(DIFFERSTR(npc->querystr("race"), "人类") ) continue;	//非人类NPC
		if(npc->query("no_kill")) continue;	//是一般玩家不可能找到的随机怪物
		if(npc->query("mfnpc_lvl")) continue;	//是梦泽山的随机怪物
		if(npc->query("no_talk")) continue;	//这个NPC有特殊设置
		if(npc->query("no_huan")) continue;	//这个NPC有特殊设置
		
		CContainer * env = npc->environment();
		
		//现在判断NPC大致的方位
		area = position_npc(npc);
		if(! area ) continue;	//这个NPC没有环境
		if(! area[0]) continue;	//这个NPC在玩家房间或者战斗中。
		if(EQUALSTR(env->querystr("area"), "fight") ) continue;	//这个NPC在玩家房间或者战斗中。
		if(EQUALSTR(env->querystr("area"), "野外") ) continue;	//这个NPC在野外。
		if(env->query("renwu") ) continue;	//这个NPC在特殊任务的房间中。
		break;
	}

	double value = 1800;		//30分钟
	time_t t;
	time(&t);
	t += (time_t)value;	

	me->set("tradepro/quest_time",t+i);

	me->set("tradepro/index",2);
	me->set("tradepro/quest_npc_id",npc->querystr("id"));
	me->set("tradepro/quest_npc_name",npc->querystr("name"));
	tell_object(me, snprintf(msg, 255, index2[random(5)], me->querystr("tradepro/quest_npc_name")));

	return 1;
}

// good:owner
// me:name areaname exp itemname overtime

VENDOR_END;
