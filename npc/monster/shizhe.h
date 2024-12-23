//yongren.h
//玩家仆人
//2001-03-15

//可以自动问好。可以设置问好的语句
//可以设置仆人名字。
//可以设置描述

//2001-04-04
//增加售卖主人物品和租借的功能
//为纸人居增加。
char * check_legal_name(const char * name);
int valid_string(const char * msg);

NPC_BEGIN(CNmonster_shizhe);

void create()
{
	set_name("使者", "shi zhe");
    set("gender", "女性");
	set("icon", girl1);

    set("age", 20);
 //   set("attitude", "friendly");
    
	set("per", 18 + random(15));
    set("combat_exp", 20000);
	set("str", 40);
	set("no_kill", 1);

	set("infinity", 1);		//不受容量限制

	set("is_user", 1);
}

void init(CChar * me)
{
	CNpc::init(me);

	char msg[255];
/*
	if(me->query("mud_age")==me->query("death/mud_age")
		||me->query_temp("kill/flee")!=me->query("kill/flee")
		||me->query_temp("kill/death")!=me->query("kill/death"))
	{
		me->set_temp("block_msg/all",1);
		if(EQUALSTR((me->query_weapon())->querystr("id"), "tealeaf"))
			me->command(snprintf(msg, 40, "unwield %ld", (me->query_weapon())->object_id()));

		me->delete_temp("apply");
		me->delete_temp("block_msg/all");

		me->set_temp("kill/flee",me->query("kill/flee"));
		me->set_temp("kill/death",me->query("kill/death"));
		me->UpdateMe();
	}
*/
	if(me->query("tongji")||me->query("kill/红名时间"))
	{
		tell_object(me,"你的总舵已经被查封，现在无法进入。");
		tell_room(me->environment(),snprintf(msg,255,"只听“乒”地一声，%s被人从房里一脚踢了出来，狼狈万状的逃开了。",me->name()),me);
		me->move(load_room(global_room_name[random(MAX_ROOM_NUM)]));
		me->add("hp",-100);
	}

	else if(! is_fighting() && userp(me))
	{
		if(querystr("welcome")[0])
		{
			remove_call_out(do_greeting);
			call_out(do_greeting, 2, me->object_id());
		}		
	}	
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;	
	me->say(me->querystr("welcome"));		
}

int do_talk(CChar *me, char * ask)
{
	//只能在自己的家里设定仆人的	
	AddMenuItem("查看追杀令", "$0lookenemy $1", me);
	AddMenuItem("查看本帮成员", "$0wholook $1", me);

	if(me->querymap("corps"))
	{
		if(me->query("corps/level") <= environment()->query("caiwu"))
		{
			AddMenuItem("存款", "$1dep $1 $2", me);
			AddMenuItem("取款", "$1wit $1 $2", me);
			AddMenuItem("查看帐户", "$0bal $1", me);
		}

		if(me->query("corps/level") < 7)
		{
			AddMenuItem("索取接引令", "$0getling1 $1", me);
			AddMenuItem("索取开除令", "$0getling2 $1", me);
		}

		if(me->query("corps/level") < 3)
		{			
			AddMenuItem("设置留言", "$2welcome $1 $2", me);				
					
			AddMenuItem("发布追杀令", "$0enemy $1", me);
			AddMenuItem("撤消追杀令", "$0remenemy $1", me);	
			
			if(me->query("corps/level") == 1)
			{
				AddMenuItem("索取禅让令", "$0getling3 $1", me);
				AddMenuItem("本派等级制定", "$0setting $1", me);
				AddMenuItem("本派财务权限设定", "$0caiwu $1", me);
			}
		}

		if(me->query("corps/level") != 1)
		{
			AddMenuItem("退教", "$0leave $1", me);
		}
	}

	SendMenu(me);
		
	return 1;
}

int do_getling1(CChar * me)
{
	say("这支令牌用于招收新人。");	
	load_item("jieyinling")->move(me);
	return 1;
}

int do_getling2(CChar * me)
{
	say("这支令牌用于开除弟子。");
	if(me->query("corps/level") == 7)
		return notify_fail("你没有资格索要。");

	load_item("bangzhuling")->move(me);
	return 1;
}

int do_getling3(CChar * me)
{
	say("这支令牌用于转让帮主席位。只有本帮最高首领可以使用。");
	if(me->query("corps/level") != 1)
		return notify_fail("你没资格所要。");

	load_item("shanrangling")->move(me);
	return 1;
}

int do_leave(CChar * me, char * arg)
{
	if(! strlen(arg))
	{
		say("退出帮会组织需要缴纳10万。你考虑好了吗？", me);
		AddMenuItem("我考虑好了。", "$0leave $1 1", me);
		AddMenuItem("我再考虑考虑！", "", me);
		SendMenu(me);
		return 1;
	}

	if(! CMoney::Player_Pay(me, 100000))
		return notify_fail("你的现金不足！");

	const char * corps_id = me->querystr("corps/id");
	if(! corps_id[0]) return 0;

	if(me->query("corps/level") == 1)
		return notify_fail("你是本帮首领，不能主动退教！");

	char msg[255];
	CRoom * r = load_room(corps_id);
	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "我宣布：今天起与你们%s再无任何瓜葛！", r->name()));
	me->del("corps");
	me->setup();
	me->move(load_room(r->querystr("belong")));
	me->set("start_city", START_ROOM);
	me->Save();
	me->UpdateMe();

	return 1;
}

int do_enemy(CChar * me, char * arg)
{
	char msg[255];

	if(! strlen(arg))
	{
		say("可向本派帮众发布对其他玩家的追杀令。发布追杀令后，被追杀者如被本派帮众所杀，不记录罪行，且PK奖励加倍。", me);
		AddMenuItem("指定被追杀对象", "$2enemy $1 $2", me);
		SendMenu(me);
		return 1;
	}

	CContainer * env = environment();
	if(EQUALSTR(me->querystr("corps/id"), env->querystr("base_name"))
		&& me->query("corps/level") < 3)
	{
		CMapping * enemy = env->querymap("enemy");
		if(enemy && enemy->GetCount() >= 10)
			return notify_fail("同时追杀太多人了，请撤消几个追杀令。");

		CChar * who = find_online(arg);
		if(! who)
			return notify_fail("没有这个人。。。");

		if(! CMoney::Player_Pay(me, 50000) )
			return notify_fail("发布追杀令需要经费5万。");

		if(! env->LockData(1)) return 0;
		env->Load();

		int times = env->add(snprintf(msg, 80, "enemy/%s", who->id(1)), 1);

		env->Save();
		env->LockData(0);

		g_Channel.do_channel(me, NULL, "corps", 
			snprintf(msg, 255, "我宣布%s开始追杀%s(%s)！追杀%ld次！", env->name(), who->name(1), who->id(1), times));

		tell_object(who, snprintf(msg, 255, "$HIR你被%s追杀了。", env->name()));

		output_error(snprintf(msg, 255, "%s(%s)被%s(%s)追杀了.", who->name(1), who->id(1), me->name(1), me->id(1)));
		return 1;
	}

	return 0;
}

int do_lookenemy(CChar * me)
{
	char msg[255];
	CContainer * env = environment();
	CMapping * enemy = env->querymap("enemy");

	if(! enemy) return notify_fail("没有追杀令发布。");	

	CVector v;
	enemy->keys(v);

	for(int i=0; i<v.count(); i++)
		AddMenuItem(snprintf(msg, 255, "追杀(%s)%ld次", v[i], enemy->query(v[i])), "", me);

	SendMenu(me);
	return 1;	
}

int do_remenemy(CChar * me, char * arg)
{
	char msg[255], cmd[40];
	CContainer * env = environment();
	CMapping * enemy = env->querymap("enemy");

	if(! enemy) return notify_fail("没有追杀令发布。");

	if(! strlen(arg))
	{			
		CVector v;
		enemy->keys(v);

		for(int i=0; i<v.count(); i++)
			AddMenuItem(snprintf(msg, 255, "撤消追杀(%s)", v[i]),
					snprintf(cmd, 40, "$0remenemy $1 %s", v[i]), me);

		SendMenu(me);
		return 1;
	}
	
	if(EQUALSTR(me->querystr("corps/id"), env->querystr("base_name"))
		&& me->query("corps/level") < 3)
	{
		if(! env->LockData(1)) return 0;
		env->Load();

		enemy = env->querymap("enemy");
		if(! enemy)
		{
			env->LockData(0);
			return 0;
		}

		enemy->del(arg);		
		if(! enemy->GetCount())
			env->del("enemy");
		env->Save();
		env->LockData(0);

		g_Channel.do_channel(me, NULL, "corps", 
			snprintf(msg, 255, "我宣布%s停止追杀%s！", env->name(), arg));
		return 1;
	}

	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "welcome") == 0)
		return do_welcome(me, arg);
	else if(strcmp(comm, "getling1") == 0)
		return do_getling1(me);
	else if(strcmp(comm, "getling2") == 0)
		return do_getling2(me);
	
	else if(strcmp(comm, "leave") == 0)
		return do_leave(me, arg);
	else if(strcmp(comm, "enemy") == 0)
	{
		CContainer * env = environment();
		if(! env->LockData(1)) return 0;
		env->Load();
		int ret = do_enemy(me, arg);
		env->LockData(0);
		return ret;
	}
	else if(strcmp(comm, "remenemy") == 0)
	{
		CContainer * env = environment();
		if(! env->LockData(1)) return 0;
		env->Load();
		int ret = do_remenemy(me, arg);
		env->LockData(0);
		return ret;
	}
	else if(strcmp(comm, "lookenemy") == 0)
		return do_lookenemy(me);
	else if(strcmp(comm, "wholook") == 0)
		return do_who(me);

	if(me->query("corps/level") <= environment()->query("caiwu") && ! g_Combatd.query("disable_corps_balance"))
	{
		if(strcmp(comm, "dep") == 0)
		{
			return do_balance(1, me, atol(arg));
		}
		else if(strcmp(comm, "wit") == 0)
		{
			return do_balance(2, me, atol(arg));
		}
		else if(strcmp(comm, "bal") == 0)
		{
			return do_balance(3, me, atol(arg));
		}
	}
	
	if(me->query("corps/level") == 1)
	{
		if(strcmp(comm, "getling3") == 0)
			return do_getling3(me);
		else if(strcmp(comm, "setting") == 0)
		{
			CContainer * env = environment();
			if(! env->LockData(1)) return 0;
			env->Load();
			int ret = do_setting(me, arg);
			env->LockData(0);
			return ret;
		}
		else if(strcmp(comm, "chset") == 0)
		{
			CContainer * env = environment();
			if(! env->LockData(1)) return 0;
			env->Load();
			int ret = do_chset(me, arg);
			env->LockData(0);
			return ret;
		}
		else if(strcmp(comm, "caiwu") == 0)
		{
			CContainer * env = environment();
			if(! env->LockData(1)) return 0;
			env->Load();
			int ret = do_caiwu(me, arg);
			env->LockData(0);
			return ret;
		}
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_welcome(CChar * me, char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 250)
	{
		say("请把留言写得简洁漂亮点。", me);
		SendMenu(me);
		return 1;
	}

	if(! valid_string(arg) )
		return 0;
	
	set("welcome", arg);
	set_name(me->name(1));

	CContainer * where = environment();

	if(! where->LockData(1)) return 0;
	where->Load();

	where->set("shizhe/welcome", arg);
	where->set("shizhe/name", me->name(1));
	where->Save();

	where->LockData(0);

	tell_object(me, "OK.");
	return 1;
}

//列出本帮在线人员清单
int do_who(CChar * me)
{
/*	char msg[255];
	MAP2USER * list = users();
	iterator_user p;

	typedef map<string, CUser *, less <string> > MYLIST;
	MYLIST list2;
	MYLIST::iterator p2;
	CUser * who;
	
	for(p = list->begin(); p != list->end(); p++)
	{
		who = p->second;
		if(DIFFERSTR(who->querystr("corps/id"), me->querystr("corps/id")) ) continue;

		snprintf(msg, 255, "%ld %s", who->query("corps/level"), who->id(1));
		list2[msg] = who;
	}

	//排序
	for(p2 = list2.begin(); p2 != list2.end(); p2++)
	{
		who = p2->second;
		AddMenuItem(snprintf(msg, 255, "(%ld) %s(%s) %s", 
			who->query("corps/level"), who->name(1), who->id(1), who->querystr("corps/rank")), "", me);
	}

	SendMenu(me);
*/	return 1;
}

int do_list(CChar * me)
{
	char rank[80], key[10], msg[80];
	CRoom * r = load_room(me->querystr("corps/id"));
	int num = r->query("level_num");
	if(num < 1 || num > 20) return 0;

	AddMenuItem("更改本派级别个数", "$1chset $1 $2", me);

	for(int i=1; i<num + 1; i++)
	{			
		snprintf(key, 10, "%ld", i);
		strncpy(rank, r->querystr(key), 40);
		if(! rank[0])
			snprintf(rank, 40, "%ld级帮众", i);

		AddMenuItem(rank, snprintf(msg, 80, "$2setting $1 %ld $2", i), me);
	}

	SendMenu(me);
	return 1;
}

//设定本派头衔
int do_setting(CChar * me, char * arg)
{
	CRoom * r = load_room(me->querystr("corps/id"));
	int num = r->query("level_num");
	
	char rank[80], key[10];

	if(! strlen(arg))
	{	
		say(snprintf(rank, 80, "目前本派共划分为%ld个级别。", num), me);
		return do_list(me);
	}	

	analyse_string(arg, rank, 40);

	int lv = atol(arg);
	if(lv < 1 || lv > num) return 0;

	if(strlen(rank) > 14)
		return notify_fail("头衔太长。");

	snprintf(key, 10, "%ld", lv);
	if(! rank[0])
		strncpy(rank, r->querystr(key), 40);
	else
	{		
		const char * ptr = check_legal_name(rank);
		if(ptr[0])
			return notify_fail(ptr);
	}

		
	r->set(key, rank);
	r->Save();

	tell_object(me, "OK");
	return do_list(me);
}

int do_chset(CChar * me, char * arg)
{
	int num = atol(arg);

	if(num < 3 || num > 20)
		return notify_fail("设置的等级个数只能在3-20之间。");

	CRoom * r = load_room(me->querystr("corps/id"));
	r->set("level_num", num);
	r->Save();
	tell_object(me, "OK");
	return do_list(me);
}

//设置存取权限
int do_caiwu(CChar * me, char * arg)
{
	CRoom * r = load_room(me->querystr("corps/id"));

	if(! strlen(arg))
	{
		int caiwu = r->query("caiwu");

		char rank[80], key[10], msg[80];		
		int num = r->query("level_num");
		if(num < 1 || num > 20) return 0;

		say("选择本派最低财务权限", me);

		for(int i=1; i<num + 1; i++)
		{			
			snprintf(key, 10, "%ld", i);
			snprintf(rank, 40, "%s%s", caiwu == i ? "(V)" : "   ", r->querystr(key));
			if(! rank[0])
				snprintf(rank, 40, "%s%ld级帮众", caiwu == i ? "(V)" : "   ", i);

			AddMenuItem(rank, snprintf(msg, 80, "$0caiwu $1 %ld", i), me);
		}

		SendMenu(me);
		return 1;
	}
	
	r->set("caiwu", atol(arg));
	r->Save();
	tell_object(me, "OK");
	return 1;
}

int do_balance(int flag, CChar * me, LONG money)
{
	char msg[255];
	CContainer * env = environment();
	if(! env->LockData(1)) return 0;
	env->Load();
	
	LONG balance = env->query("balance");
		
	switch(flag)
	{
	case 1:		//存
		if(CMoney::Player_Pay(me, money))
		{
			balance += money;
			env->set("balance", balance);
			env->Save();

			message_vision(snprintf(msg, 255, "$N存入%ld金。", money), me);
			output_error("%s(%s)在%s存入%ld金，余额：%ld.", me->name(1), me->id(1), env->name(1), money, balance);
		}
		else
			tell_object(me, "你没有那么多钱。");
		break;
	case 2:		//取		
		if(money <= 0 || money > balance)
		{
			env->LockData(0);
			return notify_fail("没有那么多钱。");
		}

		balance -= money;
		env->set("balance", balance);
		env->Save();

		CMoney::Pay_Player(me, money);
		message_vision(snprintf(msg, 255, "$N取出%ld金。", money), me);
		output_error("%s(%s)从%s取出%ld金。余额:%ld.", me->name(1), me->id(1), env->name(1), money, balance);
		break;
	case 3:
		tell_object(me, snprintf(msg, 255, "存款是%ld金。", balance));
		break;
	}

	env->LockData(0);
	return 1;
}

NPC_END;




