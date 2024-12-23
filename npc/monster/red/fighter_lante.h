
NPC_BEGIN(CNfighter_lante);

void create()
{
	set_name("大剑师兰特", "lan te");

	set("title", "华山论剑主持人");
	set("icon", girl2);
	set("gender", "男性" );
	set("age", 70);
	set("per",40);

	set("chname", "华山论剑");
	set("channel", "f1");

	set("grant", 80);
	
	set("combat_exp", 150000000);
	set("attitude", "friendly");
	
	set("biwu/name", "华山论剑大会");
	set("biwu/register/0", "空缺");
	set("biwu/turn0/0", "0");

	set("wait_time",3);
	set("no_talk",1);

	set("file_name", querystr("base_name"));

	Load();

	reset();
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

void reset()
{
	char msg[255];
	if(!query("华山论剑/count"))
	{
		for(int i=0;i<16;i++)
		{
			set(snprintf(msg, 255, "华山论剑/%d/门派",i+1),"空缺");
			set(snprintf(msg, 255, "华山论剑/%d/英雄",i+1),"空缺");
			set(snprintf(msg, 255, "华山论剑/%d/id",i+1),"空缺");
		}
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];

	int state = query("state");

	if(state == 0)		//报名阶段
	{
		if(! strlen(ask))
		{
			AddMenuItem("查看报名情况", "1", me);
			AddMenuItem("询问比赛条件", "tiaojian", me);

			if(! has_register(me))
				AddMenuItem("我要报名", "register", me);

			if(me->query("grant") > 80)
			{
				AddMenuItem("开始抽签", "chouqian", me);				
			}

		}
		else if(strcmp(ask, "1") == 0)
		{
			tell_object(me, "\n$HIR--------------------------------华山论剑英雄入围榜--------------------------------");
			char msg1[255],msg2[255],msg3[255];
			char tbuf[3][255];
#define _nSPLIT 20
			for(int i=0;i<16;i++)
			{
				snprintf(msg1, 255, "华山论剑/%d/门派",i+1);
				snprintf(msg2, 255, "华山论剑/%d/英雄",i+1);
				snprintf(msg3, 255, "华山论剑/%d/id",i+1);
				memset(&tbuf[0][0], ' ', 3*255);
				char len = _nSPLIT - strlen(querystr(msg1));
				strcpy(&tbuf[0][len], querystr(msg1));
				len = _nSPLIT - strlen(querystr(msg2));
				strcpy(&tbuf[1][len], querystr(msg2));
				len = _nSPLIT - strlen(querystr(msg3));
				strcpy(&tbuf[2][len], querystr(msg3));
				
				tell_object(me, snprintf(msg, 255, "$HIR%s%s%s",tbuf[0],tbuf[1],tbuf[2]));
			}
			tell_object(me, "$HIR----------------------------------------------------------------------------------\n");
			return 1;
		}		
		else if(strcmp(ask, "chouqian") == 0 && wizardp(me))
		{
			chouqian();			
			set("state", 1);	//抽签结束
			delete_temp("挑战");
			delete_temp("defy");
			Save();
			command("wiz 0 \n$HIR十年磨一剑，夜夜气冲天。重踏江湖之路,泯断世间恩仇。【华山论剑】正式开赛！\n\n");	
			start();
			return 1;
		}
		else if(strcmp(ask, "tiaojian") == 0)
		{
			say("华山论剑，乃天下各派英雄之大会，只要你是江湖中人，自认为是英雄好汉，就有资格报名参加。", me);
		}
		else if(strcmp(ask, "register") == 0)
			return register_me(me);		//我要报名
	}
	else
	{
		if(! strlen(ask))
		{
			AddMenuItem("查看分组情况", "2", me);
		}
		else if(strcmp(ask, "2") == 0)
		{
			tell_object(me, "\n$HIR--------------------------------华山论剑英雄分组榜--------------------------------");
			char msg10[255],msg20[255],msg30[255];
			char tbuf1[3][255];
			for(int i=0;i<4;i++)
			{
				for(int j=1;j<5;j++)
				{
					if(i==3)
						snprintf(msg, 255,"华山论剑/第1轮/D%d",j);
					else if(i==2)
						snprintf(msg, 255,"华山论剑/第1轮/C%d",j);
					else if(i==1)
						snprintf(msg, 255,"华山论剑/第1轮/B%d",j);
					else if(!i)
						snprintf(msg, 255,"华山论剑/第1轮/A%d",j);

					snprintf(msg10, 255, "华山论剑/%s/门派",querystr(msg));
					snprintf(msg20, 255, "华山论剑/%s/英雄",querystr(msg));
					snprintf(msg30, 255, "华山论剑/%s/id",querystr(msg));
					memset(&tbuf1[0][0], ' ', 3*255);
					char len1 = 15 - strlen(querystr(msg10));
					strcpy(&tbuf1[0][len1], querystr(msg10));
					len1 = 15 - strlen(querystr(msg20));
					strcpy(&tbuf1[1][len1], querystr(msg20));
					len1 = 15 - strlen(querystr(msg30));
					strcpy(&tbuf1[2][len1], querystr(msg30));
					
					tell_object(me, snprintf(msg, 255, "$HIR%s：%s%s%s",msg,tbuf1[0],tbuf1[1],tbuf1[2]));
				}
			}
			tell_object(me, "$HIR----------------------------------------------------------------------------------\n");
			return 1;
		}
	}
	SendMenu(me);
	return 1;
}

//报名程序
int register_me(CChar * me)
{
	if(me->query_temp("华山论剑/报名"))
	{
		if(has_register(me))
		{			
			say("您已登记，请耐心等待比武大会开始。不过需要提醒您的是，你的同门可能随时会挑战你的论剑资格，如您不在线或被战败，他（她）将会取你而代之。", me);
		}
		else if(query(me->querystr("family/family_name")))
		{
			say("贵派已有人报名参赛，你想取而代之吗？", me);
			AddMenuItem("我想挑战", "$0tiaozhan $1", me);
			AddMenuItem("那就算了", "", me);
			SendMenu(me);
			return 1;
		}
		else if(query("华山论剑/count")>=16)
		{
			say("华山论剑十六个名额已满，贵派还是等下一次吧！", me);
		}
		else
		{
			char msg[255];
			add("华山论剑/count",1);
			set(snprintf(msg, 255, "华山论剑/%d/门派",query("华山论剑/count")),me->querystr("family/family_name"));
			set(snprintf(msg, 255, "华山论剑/%d/英雄",query("华山论剑/count")),me->name(1));
			set(snprintf(msg, 255, "华山论剑/%d/id",query("华山论剑/count")),me->id(1));
			set(snprintf(msg, 255, "%s",me->querystr("family/family_name")),query("华山论剑/count"));
			register_join(me, querymap("biwu/register"));
			say("记下了，您就等候比武大会开始吧。不过需要提醒您的是，你的同门可能随时会挑战你的论剑资格，如您不在线或被战败，他（她）将会取你而代之。", me);			
		}
	}
	else
	{
		say("您必须先胜了丁春秋，方可有资格参加华山论剑。", me);
		me->set_temp("华山论剑/登记",1);
	}
	SendMenu(me);
	return 1;
}

//比赛分组抽签
int chouqian()
{		
	char msg[255];
	int i,j;
	i=query("华山论剑/count");
	//初始化分组数据
	for(j=0;j<i;j++)
	{
		set(snprintf(msg, 255,"%d",j+1),1);
	}
	//开始分组
	for(j=0;j<i;j++)
	{
		snprintf(msg, 255,"%d",random(i)+1);
		if(query(msg))
		{
			del(msg);
			char msg1[40];
			if(j>11)
				snprintf(msg1, 255,"华山论剑/第1轮/D%d",j-11);
			else if(j>7)
				snprintf(msg1, 255,"华山论剑/第1轮/C%d",j-7);
			else if(j>3)
				snprintf(msg1, 255,"华山论剑/第1轮/B%d",j-3);
			else
				snprintf(msg1, 255,"华山论剑/第1轮/A%d",j+1);
			set(msg1,msg);

		}
		else
			j--;
	}
	Save();
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(!strcmp(comm, "kill") || !strcmp(comm, "fight")	|| !strcmp(comm, "cast") )
	{
		message_vision("$n向$N皱了皱眉.", me, this);
		return 1;
	}

	if(!strcmp(comm, "tiaozhan") )//挑战同门，取而代之
	{
		if(!query_temp(me->querystr("family/family_name")))
		{
			set_temp(me->querystr("family/family_name"),1);
			defy(me);
		}
		else
		{
			message_vision("$n对说道：贵派已有人在进行挑战，$N还是等一会吧！。", me, this);
		}
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

//登记
void register_join(CChar * me, CMapping * team)
{
	if(team)
	{
		team->set(me->id(1), me->name(1));
		Save();
	}
}

//报名注册
int has_register(CChar * me)
{
	CMapping * team = querymap("biwu/register");
	if(! team) return 0;
	return team->querystr(me->querystr("id"))[0];
}

//挑战已经报名的同门
void defy(CChar * me)
{
	char msg[255];
	CUser * player;
	snprintf(msg, 255,"华山论剑/%d/id",query(me->querystr("family/family_name")));
	player=find_online(querystr(msg));
	if(!player)
	{
		//被挑战者不在线直接替换
		register_join(me, querymap("biwu/register"));
		del(snprintf(msg, 255, "biwu/register/%s",querystr(msg)));
		set(snprintf(msg, 255, "华山论剑/%d/英雄",query(me->querystr("family/family_name"))),me->name(1));
		set(snprintf(msg, 255, "华山论剑/%d/id",query(me->querystr("family/family_name"))),me->id(1));
		message_vision("\n$HIR由于对手不在线，$N获得了代替参加【华山论剑】的资格。\n", me);
		delete_temp(me->querystr("family/family_name"));
		Save();
	}
	else
	{
		//判断被挑战者是否改换了门派
		if(DIFFERSTR(player->querystr("family/family_name"),querystr(snprintf(msg, 255,"华山论剑/%d/门派",query(me->querystr("family/family_name"))))))
		{
			//如换了门派则不须挑战，直接替换
			set(snprintf(msg, 255, "华山论剑/%d/英雄",query(me->querystr("family/family_name"))),me->name(1));
			set(snprintf(msg, 255, "华山论剑/%d/id",query(me->querystr("family/family_name"))),me->id(1));
			message_vision("\n$HIR由于$n已经改换门派，不能再代表贵派出战，$N获得了参加【华山论剑】的资格。\n", me,player);
			register_join(me, querymap("biwu/register"));
			del(snprintf(msg, 255, "biwu/register/%s",player->id(1)));
			delete_temp(me->querystr("family/family_name"));
			Save();
		}
		else
		{
			//3分钟后开战
			snprintf(msg, 255, "\n\n$HIG【华山论剑】%s正式挑战%s的华山论剑资格，请%s做好准备，挑战将在3分钟后开始！", me->name(1), player->name(1), player->name(1));
			tell_object(me, msg);
			tell_object(player, msg);
			do_defy(me,player,query("wait_time"));
		}
	}

}

int do_defy(CChar * me, CChar * who,int wait_time)
{
	char msg[255];

	command(snprintf(msg, 255, "wiz 0 请【%s】%s(%s) VS %s(%s)做好准备，【华山论剑】挑战赛将在%ld分钟后进行。\n", me->querystr("family/family_name"),me->name(1),me->id(1),who->name(1),who->id(1), wait_time));

	if(me && who)
	{		
		snprintf(msg, 255, "\n$HIG【华山论剑】%s和%s请准备好！\n", me->name(1), who->name(1) );

		tell_object(me, msg);
		tell_object(who, msg);	
	}
	else
	{
		if(me)
		{
			set(snprintf(msg, 255, "华山论剑/%d/英雄",query(me->querystr("family/family_name"))),me->name(1));
			set(snprintf(msg, 255, "华山论剑/%d/id",query(me->querystr("family/family_name"))),me->id(1));
			command(snprintf(msg, 255,"wiz 0 由于对手不在线，%s%s(%s)获得了代替参加【华山论剑】的资格。\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
			register_join(me, querymap("biwu/register"));
			del(snprintf(msg, 255, "biwu/register/%s",who->id(1)));
			delete_temp(me->querystr("family/family_name"));
			Save();
		}
		else if(who)
		{
			command(snprintf(msg, 255,"wiz 0 由于对手中途弃权，%s%s(%s)继续保持参加【华山论剑】的资格。\n",who->querystr("family/family_name"),who->name(1),who->id(1)));	
			delete_temp(who->querystr("family/family_name"));
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
	CNfighter_lante * npc = (CNfighter_lante *)ob;
	
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

	snprintf(msg, 255, "\n$HIR【华山论剑】你距离挑战赛还有%ld分钟！时间到自动切入战斗，请做好准备。\n", wait_time);

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

		CContainer * env = Do_BiShi(me, who, "华山论剑挑战赛", 0);
		env->set("room_locked", FIGHT_LOCKED);	//战斗锁死.

		//加入战斗检测链表
		set_biwu(env);

		CContainer * oldenv = find_object(query_temp("is_boardcast"));
		if(! oldenv) do_snoop(env);
		
		return 1;
	}

	if(me) 
	{
		set(snprintf(msg, 255, "华山论剑/%d/英雄",query(me->querystr("family/family_name"))),me->name(1));
		set(snprintf(msg, 255, "华山论剑/%d/id",query(me->querystr("family/family_name"))),me->id(1));
		command(snprintf(msg, 255,"wiz 0 由于对手不在线，%s%s(%s)获得了代替参加【华山论剑】的资格。\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
		register_join(me, querymap("biwu/register"));
		del(snprintf(msg, 255, "biwu/register/%s",key2));
		delete_temp(me->querystr("family/family_name"));
		Save();
	}
	else if(who) 
	{
		command(snprintf(msg, 255,"wiz 0 由于对手中途弃权，%s%s(%s)继续保持参加【华山论剑】的资格。\n",who->querystr("family/family_name"),who->name(1),who->id(1)));	
		delete_temp(who->querystr("family/family_name"));
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

//得胜者获得【华山论剑】的资格
void register_winner(CChar * me, int team,CChar * who)
{
	char msg[255];
	if(team==1)
	{
		//挑战者获胜
		set(snprintf(msg, 255, "华山论剑/%d/英雄",query(me->querystr("family/family_name"))),me->name(1));
		set(snprintf(msg, 255, "华山论剑/%d/id",query(me->querystr("family/family_name"))),me->id(1));
		command(snprintf(msg, 255,"wiz 0 %s%s(%s) 挑战成功，获得了参加【华山论剑】的资格。\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
		register_join(me, querymap("biwu/register"));
		del(snprintf(msg, 255, "biwu/register/%s",who->id(1)));
		Save();
	}
	else if(team==2)
	{
		//被挑战者获胜
		command(snprintf(msg, 255,"wiz 0 %s%s(%s) 应战成功，继续保持参加【华山论剑】的资格。\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
	}
	delete_temp(me->querystr("family/family_name"));
	Save();
}

//【华山论剑】获胜处理
void register1_winner(CChar * winner,CChar * failer)
{
	char msg[255];
	switch(query("state"))
	{
	case 1://第一轮是循环赛，需要依据积分来确定小组出现资格
		if(failer)
			command(snprintf(msg, 255,"wiz 0 恭喜【%s】%s(%s) 战胜 【%s】%s(%s)，获得【华山论剑】第一轮比赛第%d场的胜利。\n",winner->querystr("family/family_name"),winner->name(1),winner->id(1),failer->querystr("family/family_name"),failer->name(1),failer->id(1),query("华山论剑/第一轮/场次")));	
		add(snprintf(msg, 255,"华山论剑/成绩表/%s",winner->id(1)),1);
		add(snprintf(msg, 255,"华山论剑/第一轮/第%d圈/比赛总数", query("华山论剑/第一轮/场次")),1);
		if(query(msg)==8)//四个小组当前一圈比赛全部结束，进入下一圈循环赛
		{
			del(msg);
			add("华山论剑/第一轮/场次",1);
			//小组循环赛若进行了三圈，则循环赛结束，进入下一轮淘汰赛
			if(query("华山论剑/第一轮/场次")>=3)
			{
				command(snprintf(msg, 255,"wiz 0 第一轮比赛现在结束，即将开始第二轮的比赛！"));	
				add("state",1);
				delete_temp("论剑");
				delete_temp("lunjian");
				del("华山论剑/第一轮");//清除第一轮循环赛特别设置的标志
				re_fenzu();//循环赛结束后，所有选手按成绩重新编号
			}
			start();
		}
		break;
	case 2://第二轮是淘汰赛，胜者进入8强，编号变为F组，负者进入8-16名，编号变为P组
		command(snprintf(msg, 255,"wiz 0 恭喜%s%s(%s) 战胜 %s%s(%s)，获得【华山论剑】第%d轮比赛的胜利,顺利进入下一轮。\n",winner->querystr("family/family_name"),winner->name(1),winner->id(1),failer->querystr("family/family_name"),failer->name(1),failer->id(1),query("state")));	
		break;
	}
	Save();
}

int re_fenzu()
{
	char msg[255],msg1[255],msg2[255],first[255],sec[255];
	int i,j;
	int one,two;
	for(j=1;j<5;j++)
	{
		one=0;
		two=0;
		snprintf(sec, 255,"%s","空缺");
		snprintf(first, 255,"%s","空缺");
		for(i=1;i<5;i++)
		{
			switch(j)
			{
			case 1:
				snprintf(msg, 255,"华山论剑/第1轮/A%d",i);
				break;
			case 2:
				snprintf(msg, 255,"华山论剑/第1轮/B%d",i);
				break;
			case 3:
				snprintf(msg, 255,"华山论剑/第1轮/C%d",i);
				break;
			case 4:
				snprintf(msg, 255,"华山论剑/第1轮/D%d",i);
				break;
			}
			snprintf(msg1, 255, "华山论剑/%s/id",querystr(msg));
			snprintf(msg2, 255,"华山论剑/成绩表/%s",querystr(msg1));
			if(query(msg2)>one)
			{
				two=one;
				one=query(msg2);
				snprintf(sec, 255,"%s",first);
				snprintf(first, 255,"%s",querystr(msg));
			}
			else if(query(msg2)>two)
			{
				two=query(msg2);
				snprintf(sec, 255,"%s",querystr(msg));
			}
		}
		if(DIFFERSTR(first,"空缺"))
		{
			add_temp("华山论剑/第2轮/count",1);
			set(snprintf(msg, 255,"华山论剑/第2轮/E%d",query_temp("华山论剑/第2轮/count")),first);
			querystr(snprintf(msg, 255, "华山论剑/%s/id",first));
			command(snprintf(msg, 255,"wiz 0 恭喜【%s】%s(%s)以小组第一的名次顺利进入第二轮的淘汰赛！",
				querystr(snprintf(msg, 255, "华山论剑/%s/门派",first)),querystr(snprintf(msg, 255, "华山论剑/%s/英雄",first)),
				querystr(snprintf(msg, 255, "华山论剑/%s/id",first))));	
		}
		if(DIFFERSTR(sec,"空缺"))
		{
			add_temp("华山论剑/第2轮/count",1);
			set(snprintf(msg, 255,"华山论剑/第2轮/E%d",query_temp("华山论剑/第2轮/count")),sec);
			command(snprintf(msg, 255,"wiz 0 恭喜【%s】%s(%s)以小组第二的名次顺利进入第二轮的淘汰赛！",
				querystr(snprintf(msg, 255, "华山论剑/%s/门派",sec)),querystr(snprintf(msg, 255, "华山论剑/%s/英雄",sec)),
				querystr(snprintf(msg, 255, "华山论剑/%s/id",sec))));	
		}
	}

	return 1;
}

//比赛结束处理
void is_defeated(CChar * winner, CChar * failer)
{
	if(winner == this || failer == this) return;

	int team = winner->query_temp("biwu/team");

	//下面是比武得胜者的处理
	if(!query("state"))
		register_winner(winner,team,failer);
	else
		register1_winner(winner,failer);

	winner->delete_temp("biwu");
	failer->delete_temp("biwu");

	winner->revive(1);
	failer->revive(1);

	full_me(winner);
	full_me(failer);

	CContainer * env = winner->environment();
	remove_biwu(env);

	if(env->object_id() == query_temp("is_boardcast"))
		transfer_info();
}

//【华山论剑】开赛
int start()
{
	//第一轮：小组循环赛
	if(query("state")==1)
	{
		int i;
		char one[255],two[255],thr[255],fou[255];
		for(i=0;i<4;i++)
		{
			switch(i)
			{
			case 0:
				snprintf(one, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/A1"));
				snprintf(two, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/A2"));
				snprintf(thr, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/A3"));
				snprintf(fou, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/A4"));
				break;
			case 1:
				snprintf(one, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/B1"));
				snprintf(two, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/B2"));
				snprintf(thr, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/B3"));
				snprintf(fou, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/B4"));
				break;
			case 2:
				snprintf(one, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/C1"));
				snprintf(two, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/C2"));
				snprintf(thr, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/C3"));
				snprintf(fou, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/C4"));
				break;
			case 3:
				snprintf(one, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/D1"));
				snprintf(two, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/D2"));
				snprintf(thr, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/D3"));
				snprintf(fou, 255, "华山论剑/%s/id",querystr("华山论剑/第1轮/D4"));
				break;
			}
			
			switch(query("华山论剑/第一轮/场次"))
			{
			case 0://第一场：1-2，3-4
				check_id(one,two);
				check_id(thr,fou);
				break;
			case 1://第二场：1-3，2-4
				check_id(one,thr);
				check_id(two,fou);
				break;
			case 2://第三场：1-4，2-3
				check_id(one,fou);
				check_id(two,thr);
				break;
			}
		}
	}
	//第二轮：9-16强赛
	//第二一轮：13-16强赛
	//第二二轮：9-12强赛
	//第三轮：1-8强赛
	//第三一轮：5-8强赛
	//第三二轮：1-4强赛
	return 1;
}

//检查选手是否在线、是否已经更换门派，并启动比赛
int check_id(char player1_id[255], char player2_id[255])
{
	char msg[255];
	CUser * player1 = find_online(querystr(player1_id));
	CUser * player2 = find_online(querystr(player2_id));

	//command(snprintf(msg, 255, "wiz 0 player1是 %s player2是%s。", querystr(player1_id),querystr(player2_id)));
	
	if(player1 && player2)	//两人均在线
	{	
		//检查选手是否已经更换门派
		snprintf(msg, 255,"华山论剑/%d/门派",query(player1->querystr("family/family_name")));
		if(EQUALSTR(querystr(msg),player1->querystr("family/family_name")))
		{
			//player1 ok
			set_temp("player1",1);
		}
		snprintf(msg, 255,"华山论剑/%d/门派",query(player2->querystr("family/family_name")));
		if(EQUALSTR(querystr(msg),player2->querystr("family/family_name")))
		{
			//player2 ok
			set_temp("player2",1);
		}
		if(query_temp("player1") && query_temp("player2")) //开始比赛
		{
			delete_temp("player1");
			delete_temp("player2");
			do_lunjian(player1,player2,query("wait_time"));
		}
		else if(query_temp("player1"))
		{
			//player2 已经更换了门派，失去了比赛资格，player1 获胜
			command(snprintf(msg, 255, "wiz 0 由于%s%s(%s)已经更换了门派，不能再代表原有门派参赛，%s%s(%s)自动获得了【华山论剑】本场比赛的胜利。\n", player2->querystr("family/family_name"),player2->name(1),player2->id(1),player1->querystr("family/family_name"),player1->name(1),player1->id(1)));
			register1_winner(player1,player2);
		}
		else if(query_temp("player2"))
		{
			//player1 已经更换了门派，失去了比赛资格，player2 获胜
			command(snprintf(msg, 255, "wiz 0 由于%s%s(%s)已经更换了门派，不能再代表原有门派参赛，%s%s(%s)自动获得了【华山论剑】本场比赛的胜利。\n", 
				player1->querystr("family/family_name"),player1->name(1),player1->id(1),
				player2->querystr("family/family_name"),player2->name(1),player2->id(1)));
			register1_winner(player2,player1);
		}
		else
		{
			//player1、2 都已经更换了门派，都失去了比赛资格
			command(snprintf(msg, 255, "wiz 0 两人都换了门派！"));
		}
		
	}
	else if(player1)
	{
		//player2不在线，失去了比赛资格，player1 获胜
		command(snprintf(msg, 255, "wiz 0 由于对手不在线，【%s】%s(%s)自动获得了【华山论剑】本场比赛的胜利。\n", 
			player1->querystr("family/family_name"),player1->name(1),player1->id(1)));
		register1_winner(player1,player2);
	}
	else if(player2)
	{
		//player1 不在线，失去了比赛资格，player2 获胜
		command(snprintf(msg, 255, "wiz 0 由于对手不在线，【%s】%s(%s)自动获得了【华山论剑】本场比赛的胜利。\n",
			player2->querystr("family/family_name"),player2->name(1),player2->id(1)));
		register1_winner(player2,player1);
	}
	else
	{
		//player1、2 都已经更换了门派，都失去了比赛资格
		//command(snprintf(msg, 255, "wiz 0 两人都不在！\n"));
		add(snprintf(msg, 255,"华山论剑/第一轮/第%d圈/比赛总数", query("华山论剑/第一轮/场次")),1);
	}
	return 1;
}

int do_lunjian(CChar * player1, CChar * player2,int wait_time)
{
	char msg[255];
	command(snprintf(msg, 255, "wiz 0 请【%s】%s(%s) VS 【%s】%s(%s)做好准备，【华山论剑】第一轮循环赛第%d场比赛将在%ld分钟后进行。\n", player1->querystr("family/family_name"),player1->name(1),player1->id(1), player2->querystr("family/family_name"),player2->name(1),player2->id(1), query("华山论剑/第一轮/场次"),wait_time));
	
	snprintf(msg, 255, "\n$HIG【华山论剑】%s和%s请准备好！\n", player1->name(1), player2->name(1) );
	
	tell_object(player1, msg);
	tell_object(player2, msg);

	add_temp("论剑",1);
	set_temp(snprintf(msg, 255,"lunjian/%d/A",query_temp("论剑")),player1->id(1));
	set_temp(snprintf(msg, 255,"lunjian/%d/B",query_temp("论剑")),player2->id(1));
	
	do_lunjian1(this,wait_time,query_temp("论剑"));
	
	return 1;
}

static void do_lunjian1(CContainer * ob, LONG wait_time, LONG team)
{
	CNfighter_lante * npc = (CNfighter_lante *)ob;
	
	if(wait_time <= 0)
	{
		npc->do_summon1(npc, team);
		npc->do_biwu1(team);
		return;
	}
	
	char msg[255];
	
	const char * key1 = npc->querystr_temp(snprintf(msg, 255,"lunjian/%d/A",team));
	const char * key2 = npc->querystr_temp(snprintf(msg, 255,"lunjian/%d/B",team));
	
	CUser * player1 = find_online(key1);
	CUser * player2 = find_online(key2);

	snprintf(msg, 255, "\n$HIR【华山论剑】你距离比赛还有%ld分钟！时间到自动切入战斗，请做好准备。\n", wait_time);

	if(player1)
		tell_object(player1, msg);
	if(player2)
		tell_object(player2, msg);

	npc->call_out(do_lunjian1, 60, wait_time-1,team);
}

//抓人进入正式比赛
int do_summon1(CChar * npc, int team)
{
	char msg[255];
	
	const char * key1 = npc->querystr_temp(snprintf(msg, 255,"lunjian/%d/A",team));
	const char * key2 = npc->querystr_temp(snprintf(msg, 255,"lunjian/%d/B",team));
	
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

//华山论剑正式比赛开始
int do_biwu1(int team)
{
	char msg[255];

	const char * key1 = querystr_temp(snprintf(msg, 255,"lunjian/%d/A",team));
	const char * key2 = querystr_temp(snprintf(msg, 255,"lunjian/%d/B",team));
	
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

		CContainer * env = Do_BiShi(me, who, "华山论剑大赛", 0);
		env->set("room_locked", FIGHT_LOCKED);	//战斗锁死.

		//加入战斗检测链表
		set_biwu(env);

		CContainer * oldenv = find_object(query_temp("is_boardcast"));
		if(! oldenv) do_snoop(env);
		
		return 1;
	}

	if(me) 
	{
		//who 不在线，me 获胜
	}
	else if(who) 
	{
		//me 不在线，who 获胜
	}
	else
		return notify_fail("都不在线。");

	return 1;
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



