NPC_BEGIN(CNwiz_shangshanshi);

void create()
{
	set_name("笑问天", "xiao wentian");
	
	set("title", "赏善使者");
	set("icon", girl2);
	set("gender", "男性" );
	set("age", 25);
	
	set("grant", 85);
	
	set("combat_exp", 580000);
	set("attitude", "friendly");
	
	set("reward/default", 40000);
	
	set("reward/register/0", 0l);
	set("reward/done/0", 0l);
	
	set("biwu/register/0", 0l);
	set("biwu/done/0", 0l);
	
	set("dj/register/0", 0l);
	set("dj/done/0", 0l);

	set("mf/register/0", 0l);
	set("mf/done/0", 0l);

	set("coin/register/0", 0l);
	set("coin/done/0", 0l);
	
	Load();
};

int Save()
{
	return SaveToLocal("data/npc/shangshan.o", &_M);
}

int Load()
{
	return LoadFromLocal("data/npc/shangshan.o", &_M);	
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		AddMenuItem("打听相片奖励", "1", me);
		AddMenuItem("打听比武奖励", "2", me);	
		AddMenuItem("领取当机金钱补偿", "3", me);	
		AddMenuItem("领取当机书籍补偿", "4", me);	
		AddMenuItem("领取当机装备补偿", "5", me);
		AddMenuItem("领取金钱奖励", "6", me);	
		AddMenuItem("参与寻宝活动", "7", me);
		SendMenu(me);
		return 1;
	}
	else if(strcmp(ask, "1") == 0)
	{
		return reward_me(me, querymap("reward"), 1);	//1是1等级，0是自定义。
	}
	
	else if(strcmp(ask, "2") == 0)
	{
		return reward_me(me, querymap("biwu"), 0);
	}
	
	else if(strcmp(ask, "3") == 0)
	{
		return reward_me(me, querymap("dj"), 2);
	}
	
	else if(strcmp(ask, "4") == 0)
	{
		return reward_me(me, querymap("dj"), 3);
	}
	else if(strcmp(ask, "6") == 0)
	{
		return reward_me(me, querymap("coin"), 6);
	}
	else if(strcmp(ask, "7") == 0)
	{
		return reward_me(me, querymap("mf"), 7);
	}
	else 
	{
		return reward_me(me, querymap("dj"), 4);
	}
	
	return CNpc::do_talk(me,ask);
}

//level = 1 表示等级经验
//level = 2 表示当机用户 秦波 2002、1、8
int reward_me(CChar * me, CMapping * m, int level)
{
	char msg[255];
	int money_dj=0;	//what?
	int lvl;
	if(! m) return 1;
	
	CMapping * reg = m->querymap("register");
	CMapping * done = m->querymap("done");
	if(! reg || ! done) return 1;
	
	LONG exp = reg->query(me->id(1));
	if(! exp) 
	{
		say("每位将照片公布到主页的玩家会被系统按等级奖励金钱。", me);
		say("已公布照片，但未领到奖励的玩家，请写信给103巫师询问。", me);
		say("若无比武胜利或者当机出错的玩家是领不到适当奖励和补偿的。", me);
		SendMenu(me);
		return 1;
	}
	
	if(! done->undefinedp(me->id(1)) )
	{
		say("你已经领过奖励了。");
		return 1;
	}
	
	if(level==1)
	{
		money_dj=me->query("level")*10000;
		me->add("balance", money_dj);
		g_Channel.do_channel(this, NULL, "sys", 
			snprintf(msg, 255, "%s(%s)领得%ld金币照片上传奖励！", me->name(1), me->id(1), money_dj));
		
		tell_object(me, snprintf(msg, 255, "$HIY你领得%ld金币照片上传奖励！", money_dj));
		done->set(me->id(1), 1);
	}
	
	else if(level==2)
	{
		done->set(me->id(1), 2);
		money_dj=me->query("level")*10000;
		me->add("balance", money_dj);
		g_Channel.do_channel(this, NULL, "sys", 
			snprintf(msg, 255, "%s(%s)领得%ld当机金钱补偿！", me->name(1), me->id(1), money_dj));
		
		tell_object(me, snprintf(msg, 255, "$HIY你被补偿了%ld金币！", money_dj));
	}
	
	else if(level==3)
	{
		done->set(me->id(1), 3);
		
		char *book_dj[]={
			"book_paper","parry_book","hand_book","strike_book","book_stone","dodge","force_book","yijing0","book_silk",
				"yijing1","wuji3","wuji2","throw_book","staff_book","staff_book","lbook1","lbook2","yunv_swordb","yunvjing1",
				"lbook3","miaoshou","xuanfeng_book","yijinjing","yunvjing2","lbook3","miaoshou",
				"zhengqi_book","18muou","sword_book1","skin","literateb4","dodgebook","book_iron"
		};
		
		if(me->query("level")<10)
		{
			lvl = random(9);
		}
		
		else if(me->query("level")<30)
		{
			lvl = random(10) + 9;
		}
		
		else if(me->query("level")<60)
		{
			lvl = random(7) + 19;
		}
		
		else
		{
			lvl = random(7) + 26;
		}
		
		CContainer * ob = load_item(book_dj[lvl]);
		ob->move(me);

		g_Channel.do_channel(this, NULL, "sys", 
			snprintf(msg, 255, "%s(%s)被补偿了一本%s！", me->name(1), me->id(1), ob->name()));
		
		tell_object(me, snprintf(msg, 255, "$HIY你被补偿了一本%s！", ob->name()));
	}
	else if(level==4)
	{
		done->set(me->id(1), 4);

		char *item_dj[]={
			"cleansword","snowsword","ruanjian","qin",
				"leizhendang","qingzuzang","jinlun",
				"zijin_staff","sword_2",
				"sword_3"
		};
		
		CContainer * yu1;
		CContainer * yu2;
		CContainer * yu3;
		CContainer * yu4;
		CContainer * yu5;

		if(me->query("level")<10)
		{
			yu1 = load_item("tiejia");
			yu2 = load_item(item_dj[random(4)]);
			yu3 = load_item("toukui");
			yu4 = load_item("yinlun");
			yu5 = load_item("armor_1");
		}
		
		else if(me->query("level")<30)
		{
			yu1 = load_item("jinsijia");
			yu2 = load_item(item_dj[random(3)+4]);
			yu3 = load_item("cycle");
			yu4 = load_item("toukui");
			yu5 = load_item("putongbishou");
		}
		
		else if(me->query("level")<60)
		{
			yu1 = load_item("jinsijia");
			yu2 = load_item(item_dj[random(2)+7]);
			yu3 = load_item("cycle");
			yu4 = load_item("cuiyu");
			yu5 = load_item("huoqiang");
		}
		
		else
		{
			yu1 = load_item("jinsijia");
			yu2 = load_item("sword_3");
			yu3 = load_item("cycle");
			yu4 = load_item("cuiyu");
			yu5 = load_item("huoqiang");
		}
		
		yu1->move(me);
		yu2->move(me);
		yu3->move(me);
		yu4->move(me);
		yu5->move(me);
		g_Channel.do_channel(this, NULL, "sys", 
			snprintf(msg, 255, "%s(%s)被补偿了一件%s、一件%s、一件%s、一件%s、一件%s！", me->name(1), me->id(1), yu1->name(),yu2->name(),yu3->name(),yu4->name(),yu5->name()));
		
		tell_object(me, snprintf(msg, 255, "$HIY你被补偿了一件%s、一件%s、一件%s、一件%s、一件%s！", yu1->name(),yu2->name(),yu3->name(),yu4->name(),yu5->name()));
	}

	else if(level==6)
	{
		done->set(me->id(1), 6);
		money_dj=exp-100000000;
		me->add("balance", money_dj);
		g_Channel.do_channel(this, NULL, "sys", 
			snprintf(msg, 255, "%s(%s)领得%ld金钱奖励！", me->name(1), me->id(1), money_dj));
		
		tell_object(me, snprintf(msg, 255, "$HIY你领取了%ld金币奖励！", money_dj));
	}
	else if(level==7)
	{
		done->set(me->id(1), 7);
		double value = 2592000;		//30天
		time_t t;
		time(&t);
		t += (time_t)value;	
		struct tm * newtime;
		newtime = localtime( &t );
		me->set("mf/year",1900 + newtime->tm_year);
		me->set("mf/month",newtime->tm_mon);
		me->set("mf/day",newtime->tm_mday);
		me->set("mf/endtime",t);
//		me->add("kill/flee", 1);

		if(me->query("kill/flee")<11)
		{
			if(me->query("kill/flee")>=me->query("kill/death"))
			{
				me->set("kill/flee", me->query("kill/flee")-me->query("kill/death")+1);
				me->del("kill/death");
			}
			message_vision("$HIR$N服用了保命金丹！金丹迅速进入$N的内腑，发散成热流，化入丹田后融入奇经八脉。\n$N的精神猛的一振，恭喜恭喜！$N获得了上天赋予的一条新生命!", me);
		}

		g_Channel.do_channel(this, NULL, "sys", 
			snprintf(msg, 255, "%s(%s)获得了一颗保命金丹和参与%d月寻宝活动的资格！", me->name(1), me->id(1),newtime->tm_mon));
		
		tell_object(me, snprintf(msg, 255,"$HIY你获得了一颗保命金丹和参与%d月寻宝活动的资格！",newtime->tm_mon ));
	}
	else
	{
		done->set(me->id(1), exp);
		me->add("combat_exp", exp);
		g_Channel.do_channel(this, NULL, "sys", 
			snprintf(msg, 255, "%s(%s)领得%ld点经验！", me->name(1), me->id(1), exp));
		
		tell_object(me, snprintf(msg, 255, "$HIY你被授予了%ld点经验！", exp));
	}

	
	Save();
	
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{	
	char team[40];
	
	if(wizardp(me) )
	{
		if(me->query("grant") > 90)
		{
			if(strcmp(comm, "biwu") == 0)	//指令用法: biwu 1193 5000
			{
				analyse_string(arg, team, 20);
				return do_register(me, querymap("biwu/register"), arg, atol(team));
			}
			
			else if(strcmp(comm, "reward") == 0)
			{
				analyse_string(arg, team, 20);
				LONG exp = atol(team);
				if(! exp)
					exp = query("reward/default");
				return do_register(me, querymap("reward/register"), arg, exp);
			}	
			else if(strcmp(comm, "coin") == 0)
			{
				analyse_string(arg, team, 20);
				LONG exp = atol(team);
				if(! exp)
					exp = query("coin/default");
				return do_register(me, querymap("coin/register"), arg, exp);
			}	
			else if(strcmp(comm, "dj") == 0)
			{
				analyse_string(arg, team, 20);
				return do_register(me, querymap("dj/register"), arg, atol(team));
			}
			else if(strcmp(comm, "mf") == 0)
			{
				analyse_string(arg, team, 20);
				return do_register(me, querymap("mf/register"), arg, atol(team));
			}	
			else if(strcmp(comm, "remove") == 0)
			{
				analyse_string(arg, team, 20);
				return do_remove(me, arg, team);
			}
		}
		
		if(strcmp(comm, "query") == 0)
		{
			analyse_string(arg, team, 20);
			return do_query(me, arg, team);
		}
	}
	
	return CNpc::handle_action(comm, me, arg);
}

int do_remove(CChar * me, const char * zu, const char * userid)
{
	char msg[255];
	
	CMapping * reg = querymap(snprintf(msg, 255, "%s/register", zu));
	CMapping * done = querymap(snprintf(msg, 255, "%s/done", zu));
	if(! reg || ! done)
		return notify_fail("请先用/call set reward/register/0 0\n 再用/call set reward/done/0 0");
	
	reg->del(userid);
	done->del(userid);
	Save();
	
	tell_object(me, snprintf(msg, 255, "在%s里清空用户%s。", zu, userid));
	
	return 1;
}

int do_query(CChar * me, const char * zu, const char * userid)
{
	char msg[255];
	
	CMapping * reg = querymap(snprintf(msg, 255, "%s/register", zu));
	CMapping * done = querymap(snprintf(msg, 255, "%s/done", zu));
	if(! reg || ! done)
		return notify_fail("请先用/call set reward/register/0 0\n 再用/call set reward/done/0 0");
	
	LONG exp = reg->query(userid);
	if(! exp)
		return notify_fail("该用户无奖励。");
	
	tell_object(me, snprintf(msg, 255, "用户%s在%s里有奖励%ld。%s",
		userid, zu, exp, (done->undefinedp(userid) ? "未领过。" : "已领过")));
	
	return 1;
}

int do_register(CChar * me, CMapping * m, const char * userid, LONG exp)
{
	char msg[255];
	if(! m) return notify_fail("请先用/call set reward/register/0 0\n 再用/call set reward/done/0 0");
	m->set(userid, exp);
	Save();

	if(exp==2)
	{
		tell_object(me, snprintf(msg, 255, "注册%s为当机补偿用户！", userid));
	}
	else if(exp==7)
	{
		tell_object(me, snprintf(msg, 255, "注册%s为本月寻宝人员！", userid));
	}
	else if(exp<100000000)
	{
		tell_object(me, snprintf(msg, 255, "注册%s为%ld点奖励！", userid, exp));
	}
	else
	{
		exp=exp-100000000;
		tell_object(me, snprintf(msg, 255, "注册%s为%ld点金钱奖励！", userid, exp));
	}
	return 1;
}

NPC_END;



