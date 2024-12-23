NPC_BEGIN(CNwiz_gongpingzi);

void create()
{
	set_name("百鸟朝凤", "chao feng");

	set("title", "比武大会登记员");
	set("icon", girl2);
	set("gender", "女性" );
	set("age", 25);

	set("chname", "现场直播");
	set("channel", "wldh");

	set("grant", 80);
	
	set("combat_exp", 150);
	set("attitude", "friendly");
	
	set("tiaojian/young", 17);
	set("tiaojian/old", 31);

	set("young/register/0", "空缺");
	set("middle/register/0", "空缺");
	set("old/register/0", "空缺");

	set("young/turn0/0", "0");
	set("middle/turn0/0", "0");
	set("old/turn0/0", "0");
	set("no_kill",1);

	Load();
};

int Save()
{
	return SaveToLocal("data/gongpingzi.o", &_M);
}

int Load()
{
	return LoadFromLocal("data/gongpingzi.o", &_M);	
}

//报名程序
int register_me(CChar * me)
{
	char msg[255];

	if(me->query("combat_exp") < 5000)
	{
		say("就您这水平，一边歇会儿，成不？", me);
	}
	else
	{		
		int ret = 0;
		if( (ret = has_register(me) ))
		{
			char str[][7] = {"少年组", "成年组", "老年组"};
			say(snprintf(msg, 255, "您已经加入%s。请耐心等待比武大会开始。", str[ret - 1]), me);
		}
		else
		{
			if(me->query("age") < query("tiaojian/young"))
			{
					//少年组
				register_join(me, querymap("young/register"));
				say("记下了，少年组，等侯比武大会开始。", me);
			}
			else if(me->query("age") < query("tiaojian/old"))
			{
				//成年组
				register_join(me, querymap("middle/register"));
				say("记下了，成年组，等侯比武大会开始。", me);
			}
			else	
			{
				//老年组
				register_join(me, querymap("old/register"));
				say("记下了，老年组，等侯比武大会开始。", me);
			}
		}
	}

	SendMenu(me);
	return 1;
}

//抽签程序 
int chouqian(const char * zu)
{		
	char msg[255];
	CMapping * reg = querymap(snprintf(msg, 255, "%s/register", zu));
	CMapping * result = querymap(snprintf(msg, 255, "%s/turn0", zu));

	if(! result)
	{
		CMapping m;
		set(msg, m);
		result = querymap(msg);
	}

	if(! reg || ! result) return 0;

	int count, team = 0, st = 0;
	char str[20];
	CVector v;
	reg->keys(v);

	if(query("state"))	//在已分组的条件下继续分组
	{
		team = result->GetCount();
		for(int i=0; i<team; i++)
		{
			CMapping * ptr = result->querymap(snprintf(msg, 255, "%ld", i));
			const char * key = ptr->querystr("A");
			v.remove(key);
			key = ptr->querystr("B");

			if(key[0])
			{
				st = 0;
				v.remove(key);
			}
			else
				st = 1;			
		}

		if(st) team--;
	}	

	while(( count = v.count()))
	{
		const char * key = v[random(count)];

		if(! st)
		{
			result->set(snprintf(str, 20, "%ld/A", team), key);		
			v.remove(key);
		}

		if(count > 1 || st)
		{
			key = v[random(count - 1)];

			result->set(snprintf(str, 20, "%ld/B", team), key);
			v.remove(key);
			st = 0;
		}

		team ++;
	}

	return 1;
}

//查看对阵形式
int look_turn(CChar * me, int choice, int team)
{
	if(team < 0 || team > query("state")) return notify_fail("没有进行到这轮。");

	if(choice == 1)
		return show_result(me, "young", team);
	
	else if(choice == 2)
		return show_result(me, "middle", team);
	
	else if(choice == 3)
		return show_result(me, "old", team);

	else if(choice == 4)
		return show_result(me, "temp", team);

	return 0;
}

//打印对阵结果
int show_result(CChar * me, const char * zu, int turn)
{
	char msg[255], str[20];
	CMapping * m = querymap(snprintf(msg, 40, "%s/turn%ld", zu, turn));
	CMapping * reg = querymap(snprintf(msg, 40, "%s/register", zu) );
	CMapping * ptr;
	int i;
	
	if(! m || ! reg) return notify_fail("还没有结果。");

	tell_object(me, snprintf(msg, 255, "\n第%s轮对阵形式", chinese_number(turn, str)));
	tell_object(me, "-------------------------------------------------------");

	int count = (reg->GetCount() + 1) / 2;
//	for(i=0; i<turn; i++)
//		count = (count + 1) / 2;
	
	for(i=0; i<count; i++)
	{
		ptr = m->querymap(snprintf(msg, 255, "%ld", i));
		if(! ptr) continue;
		
		const char * key1 = ptr->querystr("A");
		const char * key2 = ptr->querystr("B");
		
		//判断是否优胜
		CMapping * next = querymap(snprintf(msg, 40, "%s/turn%ld/%ld", zu, turn + 1, i/2));
		int win = 0;

		if(next)
		{
			if( i % 2 == 0 )
			{
				if(	EQUALSTR(next->querystr("A"), key1))
					win = 1;
				if(	EQUALSTR(next->querystr("A"), key2))
					win = 2;
			}

			else
			{
				if( EQUALSTR(next->querystr("B"), key1))
					win = 1;
				if( EQUALSTR(next->querystr("B"), key2))
					win = 2;
			}
		}
			
		tell_object(me, snprintf(msg, 255, "$HIY第%s组：%s%s(%s)$HIY VS %s%s(%s)", 
				chinese_number(i + 1, str), 
				(win == 1 ? "$HIC" : ""),
				(key1[0] ? reg->querystr(key1) : "空缺"), 
				key1,
				(win == 2 ? "$HIC" : ""),
				(key2[0] ? reg->querystr(key2) : "空缺"), 
				key2) );
	}

	return 1;
}

void full_me(CChar * me)
{
	int hp = me->query("hp");
	int max_hp = me->query("max_hp");

	if(hp < max_hp)
	{
		me->set("hp", max_hp);
		me->set("eff_hp", max_hp);
	}

	hp = me->query("mp");
	max_hp = me->query("max_mp");

	if(hp < max_hp * 2)
	{
		me->set("mp", max_hp * 2);
	}
	
	message_vision("$YEL只见$N浑身金光乍现，散发无穷活力！", me);
	me->FlushMyInfo();	
}

//比武开始
int do_biwu(int zu, int team)
{
	char msg[255];
	static char str[][10] = {"young", "middle", "old", "temp"};

	int state = query("state") - 1;
	if(state < 0) return 0;
	if(zu < 1 || zu > 4) return notify_fail("biwu <年龄分组> <组号>");

	CMapping * ptr = querymap(snprintf(msg, 255, "%s/turn%ld/%ld", str[zu - 1], state, team));
	if(! ptr) return notify_fail("没有该组。");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);

	if(fighter1 && fighter2)	//两人均在线，开始比武
	{	
		fighter1->set_temp("biwu/npc", object_id());	//将本NPC注册
		fighter1->set_temp("biwu/team", team);		
		fighter1->set_temp("biwu/zu", zu);		
		fighter2->set_temp("biwu/npc", object_id());	//将本NPC注册
		fighter2->set_temp("biwu/team", team);
		fighter2->set_temp("biwu/zu", zu);		

		full_me(fighter1);
		full_me(fighter2);
	//	command(snprintf(msg, 255, "full %ld", fighter1->object_id()));
	//	command(snprintf(msg, 255, "full %ld", fighter2->object_id()));

		CContainer * env = Do_BiShi(fighter1, fighter2, "武林大会", 0);
		env->set("room_locked", FIGHT_LOCKED);	//战斗锁死.

		const char * ch = querystr("channel");
		if(ch[0])
		{
			env->set("channel_cast", ch);
			env->set("channel_id", querystr("chname"));
		}

		return 1;
	}

	if(fighter1) 
		register_winner(fighter1, team, zu);
	else if(fighter2) 
		register_winner(fighter2, team, zu);
	else
		return notify_fail("都不在线。");

	return 1;
}

//抓人
int do_summon(CChar * me, int zu, int team)
{
	char msg[255];
	static char str[][10] = {"young", "middle", "old", "temp"};

	int state = query("state") - 1;
	if(state < 0) return 0;
	if(zu < 1 || zu > 4) return notify_fail("biwu <年龄分组> <组号>");

	CMapping * ptr = querymap(snprintf(msg, 255, "%s/turn%ld/%ld", str[zu - 1], state, team));
	if(! ptr) return notify_fail("没有该组。");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);
	
	CContainer * r = me->environment();

	if(fighter1) 
	{
		fighter1->move(r);
		message_vision("$N从天而降！", fighter1);
	}
	
	if(fighter2) 
	{
		fighter2->move(r);
		message_vision("$N从天而降！", fighter2);
	}
	
	return 1;
}


void is_defeated(CChar * winner, CChar * failer)
{
	if(winner == this || failer == this) return;

	int team = winner->query_temp("biwu/team");

	//下面是比武得胜者的处理
	register_winner(winner, team, winner->query_temp("biwu/zu"));

	winner->delete_temp("biwu");
	failer->delete_temp("biwu");
}

//得胜者进入下一轮名单
void register_winner(CChar * who, int team, int zu)
{
	char msg[255], tmp[20];
	int state = query("state");

	//检查获胜者分在哪一组
	if(zu < 1 || zu > 4 ) return;	

	static char str[][10] = {"young", "middle", "old", "temp"};
			
	if(team % 2 == 0)
		snprintf(msg, 255, "%s/turn%ld/%ld/A", str[zu - 1], state, team/2);
	else
		snprintf(msg, 255, "%s/turn%ld/%ld/B", str[zu - 1], state, team/2);

	set(msg, who->querystr("id"));	

	const char * zuname = querystr(snprintf(msg, 255, "%s/name", str[zu - 1]));
	g_Channel.do_channel(this, NULL, "wiz", snprintf(msg, 255, "恭喜%s(%s)顺利进入%s第%s轮比赛！", 			
			who->name(1), who->id(1), zuname, chinese_number(state, tmp) ));

	Save();
}

int ask_zhanbao(CChar * me)
{
	if(me->query_temp("ask_zhanbao"))
	{
		say("你都已经要过一份了。", me);
		SendMenu(me);
	}
	else
	{
		me->set_temp("ask_zhanbao", 1);
		CContainer * obj = load_item("wiz_zhanbao");
		obj->move(me);
		obj->set("biwu", object_id());

		tell_object(me, "$YEL你获得一份即时战报！利用它可随时查阅最新对战形势。");
	}

	return 1;
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];

	int state = query("state");

	if(state == 0)		//报名阶段
	{
		if(! strlen(ask))
		{
			AddMenuItem("少年组报名情况", "1", me);
			AddMenuItem("成年组报名情况", "2", me);
			AddMenuItem("老年组报名情况", "3", me);			
			AddMenuItem("索取即时战报", "ask", me);
			AddMenuItem("我要报名", "4", me);
			if(me->query("grant") > 90)
				AddMenuItem("开始抽签", "chouqian", me);
		}
		else if(strcmp(ask, "1") == 0)
		{
			say(snprintf(msg, 255, "已有%ld人报名。", query_count(querymap("young/register"))), me);
		}
		else if(strcmp(ask, "2") == 0)
		{
			say(snprintf(msg, 255, "已有%ld人报名。", query_count(querymap("middle/register"))), me);
		}
		else if(strcmp(ask, "3") == 0)
		{
			say(snprintf(msg, 255, "已有%ld人报名。", query_count(querymap("old/register"))), me);
		}
		else if(strcmp(ask, "ask") == 0)
		{
			return ask_zhanbao(me);
		}
		else if(strcmp(ask, "chouqian") == 0 && wizardp(me))
		{
			chouqian("young");
			chouqian("middle");
			chouqian("old");

			set("state", 1);	//抽签结束
			return 1;
		}
		else
			return register_me(me);		//我要报名
	}
	else	//比武阶段 state = 第N轮
	{		
		char cmd[20];

		if(! strlen(ask))
		{
			AddMenuItem("查看少年组比武结果", "1", me);
			AddMenuItem("查看青年组比武结果", "2", me);
			AddMenuItem("查看老年组比武结果", "3", me);
			AddMenuItem("查看临时加赛结果", "4", me);
			AddMenuItem("索取即时战报", "ask", me);
			AddMenuItem("我要报名", "baoming", me);

			if(me->query("grant") > 90)
			{
				AddMenuItem("给新登记人分组", "chouqian", me);
			}
		}
		else if(strcmp(ask, "ask") == 0)
		{
			return ask_zhanbao(me);
		}
		else if(strcmp(ask, "chouqian") == 0 && wizardp(me))
		{
			chouqian("young");
			chouqian("middle");
			chouqian("old");
			chouqian("temp");
			return 1;
		}
		else if(strcmp(ask, "baoming") == 0)
		{
			return register_me(me);		//我要报名
		}
		else
		{			
			for(int i=0; i<=state; i++)
			{
				AddMenuItem(snprintf(msg, 255, "查看第%ld轮对阵形势", i), 
					snprintf(cmd, 20, "$0lookup $1 %s %ld", ask, i), me);	
			}
		}		
	}
	
	SendMenu(me);
	return 1;
}

//加到注册表里
int do_register(CChar * me, const char * zu, const char * id)
{
	char msg[255];
	CUser * user = find_online(id);
	if(! user) return notify_fail("该人不在线!");

	set(snprintf(msg, 255, "%s/register/%s", zu, id), user->name(1));
	tell_object(me, snprintf(msg, 255, "将%s注册到%s表.", user->name(1), zu));
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{	
	char team[40];

	if(strcmp(comm, "lookup") == 0)
	{			
		analyse_string(arg, team, 20);
		return look_turn(me, atol(arg), atol(team));
	}
	
	if(wizardp(me))
	{
		if(strcmp(comm, "biwu") == 0)	//指令用法: biwu 第N组
		{
			analyse_string(arg, team, 20);
			return do_biwu(atol(arg), atol(team));
		}
		else if(strcmp(comm, "summon") == 0)
		{
			analyse_string(arg, team, 20);
			return do_summon(me, atol(arg), atol(team));
		}
		else if(strcmp(comm, "register") == 0)	//登记 register temp 1193
		{
			analyse_string(arg, team, 20);
			return do_register(me, arg, team);
		}
	}

	return CNpc::handle_action(comm, me, arg);
}

//登记
void register_join(CChar * me, CMapping * team)
{
	if(team)
		team->set(me->id(1), me->name(1));
}

int query_count(CMapping * team)
{
	if(! team) return 0;
	return team->GetCount();
}

int has_register(CChar * me)
{
	if( query_register(me, querymap("young/register")) )
		return 1;
	if( query_register(me, querymap("middle/register")) )
		return 2;
	if( query_register(me, querymap("old/register")) )
		return 3;
	return 0;
}

int query_register(CChar * me, CMapping * team)
{
	if(! team) return 0;
	return team->querystr(me->querystr("id"))[0];
}

NPC_END;