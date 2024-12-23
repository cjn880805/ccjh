// pub_baixiaosheng 百晓生
//秦波 2002、3、5

NPC_BEGIN(CNpub_baixiaosheng);

virtual void create()
{
	set_name("百晓生", "bai xiao sheng");
	set("gender", "男性");
	set("age", 45);
	set("icon",35);
	
	set("combat_exp", 7000);
	set("shen_type", 1);
	
	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
	set("no_talk",1);
	set("no_huan",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	CContainer * bot;
	//情花、相思
	if(me->query_temp("gumu/jq_gu"))
	{
		say("你已经通过了考验，绝情谷在长白山一带,快点去那里吧。", me);
		SendMenu(me);
		return 1;
	}
	else if(me->query_temp("gumu/jq_dan"))
	{
		if(me->query_temp("gumu/jq_kill"))
		{
			if(me->query_temp("gumu/jq_kill")<=5)
			{
				if(me->query_temp("gumu/jq_renwu")==1)
					say(snprintf(msg, 255, "帮我杀了%s(%s)吗？", me->querystr_temp("gumu/kill_name"),me->querystr_temp("gumu/kill_id")), me);
				else
				{
					me->add_temp("gumu/jq_kill",1);
					me->add_temp("gumu/jq_renwu",-do_jq_kill(me));
				}
			}
			else
			{
				say("哈哈哈，我的武林名人谱上终于完成了。",me);
				say("好好好，你的表现不错，已经通过了考验，这把钥匙你拿去，绝情谷在长白山一带。", me);
				bot = load_item("anjinmenkey");
				bot->set("owner",me->querystr("id"));
				bot->set("bz",atoi(me->id(1)));
				bot->move(me);
				me->delete_temp("gumu/jq_dan");
				me->delete_temp("gumu/jq_kill");
				me->delete_temp("gumu/jq_renwu");
				me->set_temp("gumu/jq_gu",1);
			}
		}
		else
		{
			if(! strlen(ask))
			{
				AddMenuItem("询问[绝情谷]的位置", "wen", me);
			}
			else if(strcmp(ask, "wen") == 0)
			{
				say("你想去绝情谷，那里危险的很啊！你真的愿意去？", me);
				AddMenuItem("愿意", "y", me);
				AddMenuItem("算了还是下次吧", "n", me);
			}
			else if(strcmp(ask, "y") == 0)
			{
				me->set_temp("gumu/jq_kill",1);
				say("那你先帮我去杀掉几个人，让我看看你的实力吧！", me);
				me->set_temp("gumu/jq_renwu",do_jq_kill(me));
			}
			else if(strcmp(ask, "n") == 0)
			{
				say("呵呵，看起来你还得多增加点胆色才成啊。", me);
				me->delete_temp("gumu/jq_dan");
			}
		}
		SendMenu(me);
		return 1;
	}
	//胁迫御史毛成龙任务   秦波  2002\11\5
	else if(me->query_temp("zhang/百晓生") ||me->query("zhang/renwu5"))
	{
		if(!me->query_temp("zhang/百晓生礼物") && !me->query("zhang/renwu5"))
			say("百晓生说道：平白无故，我为什么要听那个老头的话教你？", me);
		else
		{
			if(! strlen(ask))
			{
				say("百晓生说道：御史毛大人家住北京城中，你既然是给张大人办事，我想你可以这么去做。。", me);
				if(!me->query("zhang/renwu5"))
				{
					if(me->query_per()>30 && me->query_int()>60)
					{
						me->set_temp("zhang/renwu5",1);
						AddMenuItem("说降毛成龙", "mao1", me);
					}
					else if(me->query_int()>60)
					{
						me->set_temp("zhang/renwu5",2);
						AddMenuItem("贿赂收买与毛成龙合谋的官员", "mao2", me);
					}
					else if(me->query_str()>50 && me->query_dex()>55)
					{
						me->set_temp("zhang/renwu5",3);
						AddMenuItem("绑架毛成龙幼子、威胁毛成龙", "mao3", me);
					}
					else
					{
						me->set_temp("zhang/renwu5",4);
						AddMenuItem("暗杀毛成龙", "mao4", me);
					}
				}
				else
				{
					if(me->query("zhang/renwu5")==1)
						say("百晓生说道：如果你真能兵不血刃的说服毛大人，那可不简单呀！", me);
					if(me->query("zhang/renwu5")==2)
						say("百晓生说道：毛成龙之所以敢如此胆大妄为，是因为朝野有几个人给他撑腰而已！", me);
					if(me->query("zhang/renwu5")==3)
						say("百晓生说道：毛成龙最疼爱的就是他的弱冠幼子，如果你将他的这个儿子给。。。", me);
					if(me->query("zhang/renwu5")==4)
						say("百晓生说道：你既然想为张大人办事，像毛成龙这种跳梁小丑人，只需一刀就可以让他住嘴！", me);
					maochenglong(me); 
				}
			}
			else if(!strcmp(ask, "mao1") && me->query_temp("zhang/renwu5")==1)
			{
				say("百晓生说道：如果你真能兵不血刃的说服毛大人，那可不简单呀！", me);
				me->set("zhang/renwu5",1);
				me->delete_temp("zhang/百晓生礼物");
				me->delete_temp("zhang/御史毛成龙");
				me->delete_temp("zhang/百晓生");
				//启动说降毛成龙任务
				maochenglong(me); 
			}
			else if(!strcmp(ask, "mao2") && me->query_temp("zhang/renwu5")==2)
			{
				say("百晓生说道：毛成龙之所以敢如此胆大妄为，是因为朝野有几个人给他撑腰而已！", me);
				say("百晓生说道：据我所知，这次参劾张大人的除御史毛成龙之外，联名上奏的还有四人。", me);
				say("百晓生说道：这四位大人听说分别是成都提督吴天良、户部尚书赵崇祚、礼部侍郎孙承宪、襄阳安抚使余光启。", me);
				say("百晓生说道：你只要将那些人想办法给摆平了，相信再给他毛成龙一个胆子他也不敢再去惹张大人的虎威了！", me);
				me->set("zhang/renwu5",2);
				me->delete_temp("zhang/百晓生礼物");
				me->delete_temp("zhang/御史毛成龙");
				me->delete_temp("zhang/百晓生");
				//启动贿赂收买与毛成龙合谋的官员任务
				maochenglong(me); 
			}
			else if(!strcmp(ask, "mao3") && me->query_temp("zhang/renwu5")==3)
			{
				say("百晓生说道：毛成龙最疼爱的就是他的弱冠幼子，如果你将他的这个儿子给。。。", me);
				me->set("zhang/renwu5",3);
				me->delete_temp("zhang/百晓生礼物");
				me->delete_temp("zhang/御史毛成龙");
				me->delete_temp("zhang/百晓生");
				//启动绑架毛成龙幼子、威胁毛成龙任务
				maochenglong(me); 
			}
			else if(!strcmp(ask, "mao4") && me->query_temp("zhang/renwu5")==4)
			{
				say("百晓生说道：你既然想为张大人办事，像毛成龙这种跳梁小丑人，只需一刀就可以让他住嘴！", me);
				me->set("zhang/renwu5",4);
				me->delete_temp("zhang/百晓生礼物");
				me->delete_temp("zhang/御史毛成龙");
				me->delete_temp("zhang/百晓生");
				//启动暗杀毛成龙任务
				maochenglong(me); 
			}
		}
		SendMenu(me);
		return 1;
	}
	//缥缈奇缘
	else
	{
		if(! strlen(ask))
		{
			if(me->query("lj/renwu_ok"))
			{
				say("百晓生说道：原来灵鹫宫的这些变故是因为逍遥派四人的蘖缘啊！", me);
				say("百晓生说道：如今事隔数十年除了当事人，世上恐怕也只有我知道这段爱恨情仇了，你想知道？那改日我们慢慢再聊吧！", me);
				if(!me->query("lj/renwuok_1") )
				{
					me->set("lj/renwuok_1",1);
					me->add("combat_exp",1000);
					me->UpdateMe();
					tell_object(me, "\n$HIR你完成了“向百晓生讲叙灵鹫奇遇”的任务，获得了1000点的经验奖励。\n");
				}
			}
			else if(me->query("lj/renwu110"))
			{
				say("百晓生说道：西夏国招的是驸马，你一个女子怎么可能进的去呀！", me);
				say("百晓生说道：如果你一定要去的话，给我50万，我帮你想想办法。", me);
				me->set_temp("lj/renwu110",1);
			}
			else if(me->query("lj/renwu10"))
			{
				say("百晓生说道：近日西夏国传来一件趣事，西夏国国主公开为他最疼爱的公主在招赘驸马！", me);
				say("百晓生说道：听说这个公主长的是沉鱼落雁、闭月羞花，性情温柔，端是一个天上地下少有的好女子。", me);
				tell_object(me, "\n$HIR你心中暗自想到，竹虚曾拜托留意梦姑的消息。");
				tell_object(me, "$HIR此次西夏驸马招亲，说不定能探听到梦姑的消息，圆了尊主一件心事，促成燕好。");
				tell_object(me, "\n$HIR你心里不禁激动起来，决心代竹虚去参加招亲，一探究竟。\n");
				me->set("lj/renwu11",1);
				me->del("lj/renwu10");
			}
			else if(me->query("lj/renwu5"))
				AddMenuItem("万仙大会", "wanxianhuei", me);
			else if(me->query_temp("lj/shizhong"))
				AddMenuItem("汇报灵鹫骚乱原因", "shizhong", me);
			else 
				AddMenuItem("询问近期江湖大事", "dating", me);
		}
		else if(strcmp(ask, "dating") == 0)
		{
			if(!me->querymap_temp("lj")&&!me->querymap("lj") 
				&& !me->querymap_temp("xy")&&!me->querymap("xy"))
			{
				AddMenuItem("缥缈峰头云乱", "dating_lj", me);
				AddMenuItem("逍遥令再现江湖", "dating_xy", me);
			}
		}
		else if(strcmp(ask, "dating_xy") == 0)//一梦逍遥
		{
			say("百晓生说道：听说逍遥派现任掌门逍遥女正广发逍遥令，召集门下弟子及邀请同道中人共聚逍遥商议要事。", me);
			if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
				say("百晓生说道：你身为逍遥门人，如何还在此游荡！", me);
			else
				say("百晓生说道：不知阁下是否有兴趣代老夫查探一番么？回来时必有酬谢！", me);
			me->set_temp("xy/逍遥令",1);
		}
		else if(strcmp(ask, "dating_lj") == 0)//缥缈奇缘
		{
			say("百晓生说道：灵鹫宫上上下下好像乱做一团，枉我自称百晓生却不知发生何事。", me);
			say("百晓生说道：你与灵鹫宫人素有来往，能代老夫查探一番么？回来时必有重要情报酬谢！", me);
			me->set_temp("lj/dating",1);
		}
		else if(strcmp(ask, "shizhong") == 0)
		{
			say("百晓生说道：啊！原来是铁姥失踪！恩，为了报答你，我告诉你---", me);
			say("百晓生说道：最近谣传一些江湖上的岛主洞主们会有一次大集会，你若有兴趣自可打探一番，当然了，知道了结果一定要告诉我哟！", me);
			say("百晓生说道：详情你可先问问我的好友川西碧磷洞商土公。", me);
			me->set("lj/renwu1",1);
			me->delete_temp("lj/shizhong");
		}
		else if(strcmp(ask, "wanxianhuei") == 0)
		{
			say("百晓生说道：哦？原来万仙大会也恰好和灵鹫有关？这倒是巧了。", me);
			if(!me->query("lj/renwu55"))
			{
				me->set("lj/renwu55",1);
				me->add("combat_exp",5000);
				me->UpdateMe();
				tell_object(me, "\n$HIR你完成了“替百晓生打听灵鹫骚乱事件”的任务，获得了5000点的经验奖励。\n");
			}
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

int do_jq_kill(CChar * me)
{
	static struct{
		char name[20];
		char id[20];
		int  exp;			
	} lvlmax[5] = {			
		{"卓一行","zhun yi hang", 60,},
		{"水云烟", "shui yun yan", 60,},
		{"李秋痕", "li qiou hen", 60,},
		{"独孤求", "du gu qiu", 60,},
		{"宁月", "ning yue", 60,},
	};

	char msg[255];
	const char * shuiname = "";
	const char * shuiid = "";
	int shuiexp = 0;

	int task = me->query_temp("gumu/jq_kill")-1;
	shuiname=lvlmax[task].name;
	shuiid=lvlmax[task].id;
	shuiexp=lvlmax[task].exp;
	
	me->set_temp("gumu/kill_name",shuiname);
	me->set_temp("gumu/kill_id",shuiid);

	if(!me->query_temp("gumu/jq_renwu"))
		say(snprintf(msg, 255, "百晓生说：既然你对自己很有信心，那么你就去帮我把%s(%s)杀了吧！", shuiname, shuiid), me);
	else
	{
		say("百晓生说：不错不错，我的武林名人谱上又可以勾掉一笔了。", me);
		say(snprintf(msg, 255, "百晓生说：不过我对你的能力还是有点不放心，你再去帮我把%s(%s)杀了吧！", shuiname, shuiid), me);
	}
	int exp=shuiexp+random(shuiexp);
	exp=exp+(me->query("level")-50)*2/3;
	me->set_temp("gumu/kill_exp", exp);

	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * bot;
	if(who->is_busy())
		return notify_fail("你上一个动作还没有完成");

	if (EQUALSTR(ob->querystr("name"), "银号收条") && EQUALSTR(ob->querystr("主人"), who->querystr("id")))
	{	
		if(who->query_temp("lj/renwu1101"))
		{
			tell_object(who,"百晓生说：我这里有一个我亲自做的人皮面具，你拿去吧！相信不要我告诉你该怎么去做吧！");
			bot = load_item("killermask");
			bot->set("主人",who->querystr("id"));
			bot->set_name("秘制人皮面具");
			bot->move(who);
			who->delete_temp("lj/renwu1101");
			who->set("lj/面具",1);
			return 1;
		}
		else if(who->query_temp("zhang/百晓生"))
		{
			who->set_temp("zhang/百晓生礼物",1);
			tell_object(who,"百晓生说：不看僧面看佛面，你如此心诚，我看在孔兄的面上就指点指点你吧！");
			return 1;
		}
		destruct(ob);
	}

	return 0;
}

void maochenglong(CChar * me)
{
	if(me->query("zhang/renwu5"))
	{
		time_t t;	
		struct tm * newtime;
		time(&t);
		newtime = localtime(&t); 
		double value ;		

		CContainer * env = load_room("北京西南");
		switch(me->query("zhang/renwu5"))
		{
		case 1://说降毛成龙
		case 3://绑架毛成龙幼子、威胁毛成龙
		case 4://暗杀毛成龙
			if(newtime->tm_hour < 20 && newtime->tm_hour > 7 )//每晚20点至次日7点前可以进入毛府
			{
				tell_object(me,"百晓生说：毛成龙的府邸守卫森严，你还是等天黑的时候再去吧！");
			}
			else if(!env->query("owner"))
			{
				tell_object(me,"百晓生说：毛成龙的府邸就在北京西南的，你可以去看看。");
				env->set("owner",atoi(me->id(1)));
				remove_call_out(do_open);
				call_out(do_open, 3);//开始毛府入口，并在每个场景中加入一定数目的护院
				remove_call_out(do_close);
				call_out(do_close, 1800);//30分钟后任务终止，如未完成则失败

				value = 1800;//限时30分钟
				t += (time_t)value;	
				if(!me->query("zhang/renwu5_endtime"))
					me->set("zhang/renwu5_endtime",t);
			}
			else if(env->query("owner")==atoi(me->id(1)))
			{
				tell_object(me,"百晓生说：毛成龙的府邸就在北京西南的，你可以去看看。");
			}
			else
			{
				tell_object(me,"百晓生说：现在毛府已经乱成一片，你还是等风声过后再去吧！");
			}
			break;
		case 2:
			//贿赂收买与毛成龙合谋的官员
			value =3600;//限时60分钟
			t += (time_t)value;	
			if(!me->query("zhang/renwu5_endtime"))
				me->set("zhang/renwu5_endtime",t);
			break;
		}
	}
}

static void do_open(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("北京西南");
	((CRoom *)env)->add_door("北京毛府", "北京毛府", "北京西南");
	CNpc * maofu;
	int i;
	for(i=0;i<random(5)+1;i++)
	{
		maofu = load_npc("pub_mao_huyuan2");
		maofu->move(load_room("北京毛府"));
	}
	for(i=0;i<random(5)+1;i++)
	{
		maofu = load_npc("pub_mao_huyuan2");
		maofu->move(load_room("北京毛府大厅"));
	}
	for(i=0;i<random(5)+1;i++)
	{
		maofu = load_npc("pub_mao_huyuan2");
		maofu->move(load_room("北京毛府内堂"));
	}
	for(i=0;i<random(5)+1;i++)
	{
		maofu = load_npc("pub_mao_huyuan2");
		maofu->move(load_room("北京毛府后院"));
	}
	maofu = load_npc("pub_maochenglong");
	maofu->move(load_room("北京毛府书房"));
	maofu = load_npc("pub_maochenglongzi");
	maofu->move(load_room("北京毛府后院"));
}

static void do_close(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("北京西南");
	env->del("owner");
	((CRoom *)env)->remove_all_doors();
	((CRoom *)env)->add_door("北京西北", "北京西北", "北京西南");
	((CRoom *)env)->add_door("北京皇城", "北京皇城", "北京西南");
	((CRoom *)env)->add_door("北京面馆", "北京面馆", "北京西南");
	((CRoom *)env)->add_door("北京客店2", "北京客店2", "北京西南");
	((CRoom *)env)->add_door("北京杂货铺", "北京杂货铺", "北京西南");
	((CRoom *)env)->add_door("北京棺材店", "北京棺材店", "北京西南");
	((CRoom *)env)->add_door("北京长安戏院", "北京长安戏院", "北京西南");
	((CRoom *)env)->add_door("北京回春堂药店", "北京回春堂药店", "北京西南");
}
NPC_END;



