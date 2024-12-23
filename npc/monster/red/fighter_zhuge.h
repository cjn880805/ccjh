
NPC_BEGIN(CNfighter_zhuge);

void create()
{
	set_name("诸葛小花", "zhu ge");

	set("title", "擂台赛主持人");
	set("icon", 34);
	set("gender", "男性" );
	set("age", 88);
	set("per",36);

	set("chname", "苏州擂台");
	set("channel", "f1");

	set("chat_chance", 2);

	set("grant", 80);
	
	set("combat_exp", 150000000);
	set("attitude", "friendly");
	
	set("biwu/name", "苏州擂台赛");
	set("biwu/register/0", "空缺");
	set("biwu/turn0/0", "0");

	set("wait_time",2);
	set("count",100);

	set("擂台/擂主门派","天山派");
	set("擂台/擂主姓名","武道我理");
	set("擂台/擂主ID","wiz");

	set("file_name", querystr("base_name"));

	Load();

};

int Save()
{
	char msg[255];
	return SaveToLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);
}

int Load()
{
	char msg[255];
	return LoadFromLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);	
}

char * chat_msg()
{
	if(query("count") && !random(10))
	{
		char msg[255];
		switch(random(8))
		{
		case 0:
			command("wiz 0 江湖人，江湖事，江湖恩怨情仇江湖了。\n");
			break;
		case 1:
			if(query("擂台/count"))
				command(snprintf(msg, 255,"wiz 0 拳打南山猛虎，脚踢北海蛟龙，苏州擂台第一人，唯【%s】%s(%s)是也。\n",querystr("擂台/擂主门派"),	querystr("擂台/擂主姓名"),querystr("擂台/擂主ID")));
			break;
		case 2:
			command("wiz 0 十年磨一剑，夜夜气冲天。重踏江湖之路,泯断世间恩仇。\n");
			break;
		case 3:
			command("wiz 0 铅华老去，风烟依旧。重踏江湖不归路！\n");
			break;
		case 4:
			command("wiz 0 纵横江湖的旧梦，如今重现……\n");
			break;
		case 5:
			command("wiz 0 十步杀一人，千里不留行，泯断江湖恩怨，不尽爱恨情仇……\n");
			break;
		case 6:
			command(snprintf(msg, 255,"wiz 0 本次擂台赛已经进行了%d场比赛，离结束挑战还剩%d场比赛。\n",	query("擂台/count"),query("count")-query("擂台/count")));
			break;
		case 7:
			command(snprintf(msg, 255,"wiz 0 本次擂台大赛的擂主可获得奖品“%s”一份。",check_jp()));
			break;
		}
	}
	return "";
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("count"))
	{
		char msg[255];
		if(! strlen(ask))
		{
			AddMenuItem("查看当前情况", "1", me);
			AddMenuItem("询问比赛条件", "tiaojian", me);
			AddMenuItem("查看奖品", "jiangpin", me);
			if(me->query("zhang/信任") && check(me))
				AddMenuItem("我要报名", "register", me);
			AddMenuItem("领取战报", "zhanbao", me);
			AddMenuItem("查询报名情况", "$0baoming $1", me);
		}
		else if(strcmp(ask, "1") == 0)
		{
			say(snprintf(msg, 255,"本次擂台赛已经进行了%d场比赛，离结束挑战还剩%d场比赛。",	query("擂台/count"),query("count")-query("擂台/count")) ,me);
			say(snprintf(msg, 255,"当前擂台擂主：【%s】%s(%s)，已经连续守擂成功%d场。",
				querystr("擂台/擂主门派"),	querystr("擂台/擂主姓名"),querystr("擂台/擂主ID"),query("擂台/擂主守擂数")) ,me);
		}		
		else if(strcmp(ask, "tiaojian") == 0)
			say(check_say(),me);

		else if(strcmp(ask, "jiangpin") == 0)
			say(snprintf(msg, 255,"本次擂台大赛的擂主可获得奖品“%s”一份。",check_jp()), me);

		else if(strcmp(ask, "register") == 0)
			return register_me(me);		//我要报名

		else if(strcmp(ask, "zhanbao") == 0)
			return ask_zhanbao(me);
		
		SendMenu(me);
	}
	return 1;
}

//检测当前报名人是否符合比赛条件
int check(CChar * me)
{
	switch(query("届数"))
	{
	//第一天
	case 0://60级以下可以参赛
		if(me->query("level")>60)	return 0;
		break;
	case 1://60-100级可以参赛
		if(me->query("level")>100 || me->query("level")<60)	return 0;
		break;
	case 2://100级以上可以参赛
		if(me->query("level")<100)	return 0;
		break;
	case 3://25岁以下可以参赛
		if(me->query("age")>25)	return 0;
		break;
	case 4://25-60岁以下可以参赛
		if(me->query("age")>60 || me->query("age")<25)	return 0;
		break;
	case 5://60岁以上可以参赛
		if(me->query("age")<60)	return 0;
		break;
	case 6://男号之战
		if(EQUALSTR(me->querystr("gender"), "女性"))	return 0;
		break;
	case 7://女号之战
		if(DIFFERSTR(me->querystr("gender"), "女性"))	return 0;
		break;
	case 8://总经验50万以下可以参赛
		if(me->query("combat_exp")>500000)	return 0;
		break;
	case 9://总经验50-500万以下可以参赛
		if(me->query("combat_exp")>5000000 || me->query("combat_exp")<500000)	return 0;
		break;
	case 10://总经验500-1500万以下可以参赛
		if(me->query("combat_exp")>15000000 || me->query("combat_exp")<5000000)	return 0;
		break;
	case 11://总经验1500万以上可以参赛
		if(me->query("combat_exp")<15000000)	return 0;
		break;
	case 12://无级别混战
		break;
	}
	return 1;	
}

char * check_say()
{
	switch(query("届数"))
	{
	case 0:
		return "60级以下的ID方可参加本场擂台大赛。";
	case 1:
		return "60级-100级之间的ID方可参加本场擂台大赛。";
	case 2:
		return "100级以上的ID方可参加本场擂台大赛。";
	case 3:
		return "25岁以下的ID方可参加本场擂台大赛。";
	case 4:
		return "25岁-60岁之间的ID方可参加本场擂台大赛。";
	case 5:
		return "60岁以上的ID方可参加本场擂台大赛。";
	case 6:
		return "现在只有男性和公公们的ID方可参加本场擂台大赛。";
	case 7:
		return "现在只有女性的ID方可参加本场擂台大赛。";
	case 8:
		return "总经验50万以下的ID方可参加本场擂台大赛。";
	case 9:
		return "总经验50万-500万之间的ID方可参加本场擂台大赛。";
	case 10:
		return "总经验500万-1500万之间的ID方可参加本场擂台大赛。";
	case 11:
		return "总经验1500万以上的ID方可参加本场擂台大赛。";
	case 12:
		return "擂台大赛，乃天下各派英雄之大会，只要你是江湖中人，自认为是英雄好汉，就有资格报名参加。";
	}
	return "";
}

char * check_jp()
{
	switch(query("届数"))
	{
	case 0:
		set("奖品","38huoqiang");
		return "点三八火枪";
	case 1:
		set("奖品","zidiaopifeng");
		return "紫貂披风";
	case 2:
		set("奖品","haoseshan");
		return "君子好色折扇";
	case 3:
		set("奖品","ruanweijia");
		return "帮主软猬甲";
	case 4:
		set("奖品","xuantiebishou");
		return "玄铁匕首";
	case 5:
		set("奖品","xuanwupao");
		return "玄武道袍";
	case 6:
		set("奖品","newyear1");
		return "寒烟翠袍";
	case 7:
		set("奖品","newyear");
		return "绮罗天衣";
	case 8:
		set("奖品","xuanwupao");
		return "金环头饰";
	case 9:
		set("奖品","kuihuaao");
		return "葵花小袄";
	case 10:
		set("奖品","xuanwupao");
		return "玄武道袍";
	case 11:
		set("奖品","zwsword");
		return "真武剑";
	case 12:
		set("奖品","yinguozhu");
		return "因果念珠";
	}
	return "";
}

//领取战报
int ask_zhanbao(CChar * me)
{
	char msg[255];
	CContainer * obj = load_item("wiz_leitaizhanbao");
	obj->set_name(snprintf(msg, 255, "%s战报", querystr("biwu/name")), "zhan bao");
	
	obj->move(me);
	obj->set("biwu", object_id());
	
	tell_object(me, snprintf(msg, 255, "$YEL你获得一份%s！利用它可随时查阅本场擂台大赛的比赛实况。", obj->name(1)));
	
	return 1;
}

//报名程序
int register_me(CChar * me)
{
	//这里还需要加入一定的判断，防止有人利用大米之类的ID参加比赛
	if(!me->query_temp("擂台/lost"))
	{
		char msg[255];
		if(has_register(me))
		{			
			command(snprintf(msg, 255, "wiz 0 【%s】%s(%s) 已经登上【苏州擂台】，静候天下英雄前来挑战。\n", me->querystr("family/family_name"),me->name(1),me->id(1)));
			say("您已获得擂台擂主资格，请耐心等待其他朋友的挑战。不过需要提醒您的是，如您不在线或被战败，他（她）将会取你而代之。", me);
			set("擂台/擂主门派",me->querystr("family/family_name"));
			set("擂台/擂主姓名",me->name(1));
			set("擂台/擂主ID",me->id(1));
		}
		else
		{
			say(snprintf(msg, 255,"当前擂台擂主：【%s】%s(%s)，已经连续守擂成功%d场。",
				querystr("擂台/擂主门派"),	querystr("擂台/擂主姓名"),querystr("擂台/擂主ID"),query("擂台/擂主守擂数")) ,me);
			AddMenuItem("我想挑战", "$0tiaozhan $1", me);
			AddMenuItem("那就算了", "", me);
			SendMenu(me);
			return 1;
		}
	}
	else
	{
		say("您参与【苏州擂台】擂台赛失败，在重新进入游戏前，你已经失去了再次参加擂台赛的资格。", me);
	}
	SendMenu(me);
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	char msg[255],msg1[255];
	if(!strcmp(comm, "kill") || !strcmp(comm, "fight")	|| !strcmp(comm, "cast") )
	{
		message_vision("$n向$N皱了皱眉。", me, this);
		return 1;
	}
	if(!strcmp(comm, "baoming") && query("count") )
	{
		if(query_temp("报名/挑战次数")<=query_temp("报名/总数"))
		{
			tell_object(me,"---------------------------登记挑战玩家--------------------------------");
			for(int i=query_temp("报名/挑战次数");i<=query_temp("报名/总数");i++)
			{
				//显示报名者名单
				tell_object(me,snprintf(msg, 255,"第%d名登记挑战玩家ID:    %s  ",i, querystr_temp(snprintf(msg1, 255,"登记/%d",i))));
			}
			tell_object(me,"-----------------------------------------------------------------------");
		}
		else
		{
			tell_object(me,"当前无人报名登记挑战");
		}
		return 1;
	}
	else if(!strcmp(comm, "tiaozhan") && query("count") && check(me) && me->query("zhang/信任"))
	{
		if(!query_temp("擂台/挑战"))
		{
			if(EQUALSTR(me->id(1),querystr("擂台/擂主ID")))//擂主不得挑战自己的设置
			{
				tell_object(me,"诸葛小花向你皱了皱眉：“你闲着没事，自己想挑战自己？”" );
				return 1;
			}
			else
			{
				add_temp("报名/挑战次数",1);
				add_temp("报名/总数",1);
				set_temp("擂台/挑战",atoi(me->id(1)));
				defy(me);
			}
		}
		else if(EQUALSTR(me->id(1),querystr("擂台/擂主ID")) || query_temp(snprintf(msg, 255,"报名/%s",me->id(1))))//报名挑战后不得再次选择挑战
		{
			tell_object(me,"诸葛小花对你说道：你已经报名登记过了，你还是抓紧时间去做些准备工作吧！。");
		}
		else
		{
			add_temp("报名/总数",1);
			set_temp(snprintf(msg, 255,"报名/%s",me->id(1)),1);
			set_temp(snprintf(msg, 255,"登记/%d",query_temp("报名/总数")),me->id(1));
			tell_object(me,"诸葛小花对你说道：已经给你登记了，现在有人已经在进行挑战，你还是等一下吧！");
		}
/*		else if(query_temp("擂台/挑战")==atoi(me->id(1)))//报名挑战后不得再次选择挑战
		{
			tell_object(me,"诸葛小花对你说道：你已经在挑战状态了，你还是抓紧时间去做些准备工作吧！。");
		}
		else
		{
			tell_object(me,"诸葛小花对你说道：已经有人在进行挑战，你还是等一会吧！");
		}
*/		return 1;
	}
	else if(strcmp(comm, "opench") == 0)
	{
		CVector * tuned_ch = me->queryvec("channels");
		const char * channel = querystr("channel");
		if(channel[0])
		{
			if( ! tuned_ch )
			{
				CVector v;
				v.append(channel);
				me->set("channels", v);
			}
			else if( tuned_ch->find(channel) == tuned_ch->end() )
			{
				tuned_ch->append(channel);
			}
		}
		return 1;
	}
	else if(strcmp(comm, "closech") == 0)
	{
		const char * channel = querystr("channel");
		if(channel[0])
			me->command(snprintf(msg, 40, "tune 0 %s", channel));
		return 1;
	}
	else if(strcmp(comm, "chaxun") == 0)
	{
		say(snprintf(msg, 255,"本次擂台赛已经进行了%d场比赛，离结束挑战还剩%d场比赛。",	query("擂台/count"),query("count")-query("擂台/count")) ,me);
		say(snprintf(msg, 255,"当前擂台擂主：【%s】%s(%s)，已经连续守擂成功%d场。",
			querystr("擂台/擂主门派"),	querystr("擂台/擂主姓名"),querystr("擂台/擂主ID"),query("擂台/擂主守擂数")) ,me);
		SendMenu(me);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

//报名注册
int has_register(CChar * me)
{
	if(!atoi(querystr("擂台/擂主ID")))
		return 1;
	return 0;
}

//挑战
void defy(CChar * me)
{
	char msg[255];
	CUser * player;
	player=find_online(querystr("擂台/擂主ID"));
	if(!player)
	{
		//被挑战者不在线直接替换
		set("擂台/擂主门派",me->querystr("family/family_name"));
		set("擂台/擂主姓名",me->name(1));
		set("擂台/擂主ID",me->id(1));
		del("擂台/擂主守擂数");
		command(snprintf(msg, 255,"wiz 0 由于对手不在线，%s%s(%s)获得了【苏州擂台】擂主资格。\n",me->querystr("family/family_name"),me->name(1),me->id(1)));
		delete_temp("擂台/挑战");
		defy_next();
		Save();
	}
	else
	{
		//3分钟后开战
		snprintf(msg, 255, "\n\n$HIG 【%s】 %s(%s)登上【苏州擂台】挑战【%s】 %s(%s)的擂主资格，请%s做好准备，挑战将在%d分钟后开始！", 
			me->querystr("family/family_name"),me->name(1),me->id(1),
			me->querystr("family/family_name"),player->name(1), player->id(1),
			player->name(1),query("wait_time"));
		tell_object(me, msg);
		tell_object(player, msg);
		do_defy(me,player,query("wait_time"));
	}

}

int do_defy(CChar * me, CChar * who,int wait_time)
{
	char msg[255];

	command(snprintf(msg, 255, "wiz 0 请【%s】%s(%s) VS 【%s】%s(%s)做好准备，【苏州擂台】挑战赛将在%ld分钟后进行。\n", me->querystr("family/family_name"),me->name(1),me->id(1),
		who->querystr("family/family_name"),who->name(1),who->id(1), wait_time));

	if(me && who)
	{		
		snprintf(msg, 255, "$HIG【苏州擂台】%s和%s请准备好！", me->name(1), who->name(1) );

		tell_object(me, msg);
		tell_object(who, msg);	
	}
	else
	{
		if(me)
		{
			set("擂台/擂主门派",me->querystr("family/family_name"));
			set("擂台/擂主姓名",me->name(1));
			set("擂台/擂主ID",me->id(1));
			del("擂台/擂主守擂数");
			command(snprintf(msg, 255,"wiz 0 由于对手不在线，%s%s(%s)获得了【苏州擂台】擂主资格。\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
			delete_temp("擂台/挑战");
			defy_next();
			Save();
		}
		else if(who)
		{
			command(snprintf(msg, 255,"wiz 0 由于对手中途弃权，%s%s(%s)继续保持【苏州擂台】擂主资格。\n",who->querystr("family/family_name"),who->name(1),who->id(1)));	
			delete_temp("擂台/挑战");
			defy_next();
		}
		return 1;
	}
	add_temp("挑战",1);
	set_temp(snprintf(msg, 255,"defy/%d/A",query_temp("挑战")),me->id(1));
	set_temp(snprintf(msg, 255,"defy/%d/B",query_temp("挑战")),who->id(1));
	do_defy1(this,wait_time,query_temp("挑战"));
	return 1;
}

static void do_defy1(CContainer * ob, LONG wait_time, LONG team)
{
	CNfighter_zhuge * npc = (CNfighter_zhuge *)ob;
	
	if(wait_time <= 0)
	{
		npc->do_summon(npc, team);
		npc->do_biwu(team);
		return;
	}
	
	char msg[255];
	
	const char * key1 = npc->querystr_temp(snprintf(msg, 255,"defy/%d/A",team));
	const char * key2 = npc->querystr_temp(snprintf(msg, 255,"defy/%d/B",team));
	
	CUser * me = find_online(key1);
	CUser * who = find_online(key2);

	snprintf(msg, 255, "\n$HIR【苏州擂台】你距离擂台挑战赛还有%ld分钟！时间到自动切入战斗，请做好准备。\n", wait_time);

	if(me)
		tell_object(me, msg);
	if(who)
		tell_object(who, msg);

	npc->call_out(do_defy1, 60, wait_time-1,team);
}

//抓人
int do_summon(CChar * npc, int team)
{
	char msg[255];
	
	const char * key1 = npc->querystr_temp(snprintf(msg, 255,"defy/%d/A",team));
	const char * key2 = npc->querystr_temp(snprintf(msg, 255,"defy/%d/B",team));
	
	CUser * me = find_online(key1);
	CUser * who = find_online(key2);
	
	CContainer * r = npc->environment();

	if(me) 
	{
		me->move(r);
		if(me->query("mp")>me->query("max_mp")*4)
			me->set("mp",me->query("max_mp")*4);
		message_vision("$N从天而降！", me);
	}
	
	if(who) 
	{
		who->move(r);
		if(who->query("mp")>who->query("max_mp")*4)
			who->set("mp",who->query("max_mp")*4);
		message_vision("$N从天而降！", who);
	}
	
	return 1;
}

//挑战赛开始
int do_biwu(int team)
{
	char msg[255];

	const char * key1 = querystr_temp(snprintf(msg, 255,"defy/%d/A",team));
	const char * key2 = querystr_temp(snprintf(msg, 255,"defy/%d/B",team));
	
	CUser * me = find_online(key1);
	CUser * who = find_online(key2);

	if(me && who)	//两人均在线，开始比武
	{	
		me->set_temp("biwu/npc", object_id());	//将本NPC注册
		me->set_temp("biwu/team", 1);		
		who->set_temp("biwu/npc", object_id());	//将本NPC注册
		who->set_temp("biwu/team", 2);

		full_me(me);
		full_me(who);
		
		me->set_weight(50000000);
		who->set_weight(50000000);

		me->set_temp("no_fei", 1);	//禁止逃跑	
		who->set_temp("no_fei", 1);	

		CContainer * env = Do_BiShi(me, who, "擂台挑战赛", 0);
		env->set("room_locked", FIGHT_LOCKED);	//战斗锁死.

		//加入战斗检测链表
		set_biwu(env);

		CContainer * oldenv = find_object(query_temp("is_boardcast"));
		if(! oldenv) do_snoop(env);
		
		return 1;
	}

	if(me) 
	{
		set("擂台/擂主门派",me->querystr("family/family_name"));
		set("擂台/擂主姓名",me->name(1));
		set("擂台/擂主ID",me->id(1));
		del("擂台/擂主守擂数");
		command(snprintf(msg, 255,"wiz 0 由于对手不在线，%s%s(%s)获得了【苏州擂台】擂主资格。\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
		delete_temp("擂台/挑战");
		defy_next();
		Save();
	}
	else if(who) 
	{
		command(snprintf(msg, 255,"wiz 0 由于对手中途弃权，%s%s(%s)继续保持【苏州擂台】擂主资格。\n",who->querystr("family/family_name"),who->name(1),who->id(1)));	
		delete_temp("擂台/挑战");
		defy_next();
	}
	else
		return notify_fail("都不在线。");

	return 1;
}

//比赛前补满HP、MP
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


//比赛结束处理
void is_defeated(CChar * winner, CChar * failer)
{
	if(winner == this || failer == this) return;

	int team = winner->query_temp("biwu/team");

	//下面是比武得胜者的处理
	
	winner->delete_temp("biwu");
	failer->delete_temp("biwu");

	winner->revive(1);
	failer->revive(1);
	failer->set_temp("擂台/lost",1);

	winner->delete_temp("no_fei");
	failer->delete_temp("no_fei");	

	full_me(winner);
	full_me(failer);

	winner->set_weight(50000);
	failer->set_weight(50000);

	CContainer * env = winner->environment();
	remove_biwu(env);

	if(env->object_id() == query_temp("is_boardcast"))
		transfer_info();

	register_winner(winner,team,failer);

}

//得胜者获得【苏州擂台】擂主资格
void register_winner(CChar * me, int team,CChar * who)
{
	char msg[255];
	if(team==1)	//挑战者获胜
	{
		set("擂台/擂主门派",me->querystr("family/family_name"));
		set("擂台/擂主姓名",me->name(1));
		set("擂台/擂主ID",me->id(1));
		add("擂台/count",1);
		if(query("擂台/擂主守擂数")>10)
		{
			//奖励原有擂主一定的礼品
		}
		del("擂台/擂主守擂数");
		command(snprintf(msg, 255,"wiz 0 【%s】%s(%s) 挑战成功，获得了【苏州擂台】擂主资格。\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
	}
	else if(team==2)	//擂主获胜
	{
		add("擂台/count",1);
		add("擂台/擂主守擂数",1);
		int repute=100*query("擂台/擂主守擂数");
		CContainer * RMB=load_item("coin");
		RMB->set_amount(repute);
		if(RMB) RMB->move(me);
		if(me->query("repute")<0)repute=-repute;
		me->add("repute",repute);
		command(snprintf(msg, 255,"wiz 0 【%s】%s(%s) 应战成功，继续保持【苏州擂台】擂主资格，同时获得数目 %d 的守擂彩金 。\n",me->querystr("family/family_name"),me->name(1),me->id(1),repute));	
		
		tell_object(me,snprintf(msg, 255,"$HIR你守擂成功，江湖声望上升了%d点。" ,repute));
		me->UpdateMe();
	}
	delete_temp(querystr(snprintf(msg, 255,"报名/%s",who->id(1))));//清除失败者登记记录
	if(query("擂台/count")==query("count"))
	{
		command(snprintf(msg, 255,"wiz 0 【苏州擂台】本场擂台赛结束，【%s】%s(%s) 成为本场擂台大赛的最终胜利者。\n赢得擂台赛奖品“%s”一份。\n",me->querystr("family/family_name"),me->name(1),me->id(1),check_jp()));	
		load_item(querystr("奖品"))->move(me);
		del("擂台");
		add("届数",1);
		if(query("届数")>12)
			del("count");
		delete_temp("挑战");
		delete_temp("报名");
		delete_temp("defy");
		delete_temp("擂台");
		delete_temp("登记");
	}
	else
	{
		//继续挑战
		defy_next();
	}
	Save();
}

void defy_next()
{
	add_temp("报名/挑战次数",1);
	if(query_temp("报名/挑战次数")<=query_temp("报名/总数"))
	{
		CUser * player;
		char msg[255];
		player=find_online(querystr_temp(snprintf(msg, 255,"登记/%d",query_temp("报名/挑战次数"))));
		if(player)
		{
			set_temp("擂台/挑战",atoi(querystr_temp(snprintf(msg, 255,"登记/%d",query_temp("报名/挑战次数")))));
			defy(player);
		}
		else
			defy_next();
	}
	else
	{
		delete_temp("擂台/挑战");
	}
}

void set_biwu(CContainer * ob)
{
	char msg[40];

	snprintf(msg, 40, snprintf(msg, 40, "%ld", ob->object_id()));

	if( m_biwulist.find(msg) == m_biwulist.end() )
		m_biwulist.append(msg);
}

void remove_biwu(CContainer *ob)
{
	char msg[80];
	m_biwulist.remove(snprintf(msg, 40, "%ld", ob->object_id()));
}

//随机转播
void transfer_info()
{
	while(m_biwulist.count())
	{
		CContainer * env = find_object(atol(m_biwulist[0]));
		if(env)
		{
			do_snoop(env);
			return;
		}
		m_biwulist.remove(m_biwulist[0]);
	}
}

void do_snoop(CContainer * env)
{
	const char * ch = querystr("channel");
	if(! ch[0])	return;
		
	env->set("channel_cast", ch);
	env->set("channel_id", querystr("chname"));
	set_temp("is_boardcast", env->object_id());			
}
protected:
	CVector		m_biwulist;

NPC_END;




