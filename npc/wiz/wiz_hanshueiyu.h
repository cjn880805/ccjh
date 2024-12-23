// wiz_hanshueiyu.h

//code by qinbo
//date:2001-12-31

NPC_BEGIN(CNwiz_hanshueiyu);

virtual void create()
{
	set_name("寒水鱼",  "han shueiyu");
	set("title", "兵器商人");
	set("long", "他看起来满面春风，面若秋月，举止适度。让人诧异的是，他居然座在一堆的兵器上面...");
	set("gender", "男性");
	
	set("age", 400);
	set("str", 100);
	set("con", 100);
	set("dex", 100);
	set("int", 100);
	set("icon", drugstore_boss);
	
	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
//	set_inquiry("新年礼物之二", ask_for_present),

	set_temp("no_kill", 1);
	set("hp", 15000);
	set("max_hp", 15000);
	set("mp", 5000);
	set("max_mp", 5000);
    set("mp_factor", 300);
	
	set_skill("dodge", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 500);
	set_skill("force",500);
    set_skill("literate",500);
    set_skill("cuff", 500);
	
    set_skill("qiankun_danuoyi",500);
    set_skill("jingang_quan",500);
    set_skill("hunyuan_yiqi",500);
	
    map_skill("force", "hunyuan_yiqi");
	map_skill("parry", "qiankun_danuoyi");
	map_skill("cuff", "jingang_quan");
    map_skill("dodge", "qiankun_danuoyi");
	
    prepare_skill("cuff", "jingang_quan");
	
	set_temp("apply/attack", 500);
	set_temp("apply/dodge", 500);
	
	set("chat_chance", 30);
	//set("renwu",1);
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
	CContainer * env = load_room("pk");
	if(!env->query("门派大赛") )
	{
		del("门派大赛");//如果当机的话，清除正在进行任务的标志
	}
}

virtual char * chat_msg()
{
	if(query("renwu"))
	{
		//门派大赛
		CContainer * env = load_room("pk");
		if(!env->query("门派大赛") && !query("门派大赛/自动"))
		{
			time_t t;	
			struct tm * newtime;
			time(&t);
			newtime = localtime(&t); 
			
			int day = newtime->tm_mday;
			if(day==17 && newtime->tm_hour >= 20 && query("renwu"))//自动启动门派大赛
			{
				remove_call_out(do_pk);
				call_out(do_pk, 10);
				set("门派大赛/自动",1);
				Save();
			}
			else if(query("pk") )//巫师手工启动门派大赛
			{
				del("pk");
				remove_call_out(do_pk);
				call_out(do_pk, 10);
			}
		}
	}
	return 0;
}

//开始进行比赛的准备，确定比赛的门派
static void do_pk(CContainer * ob, LONG param1, LONG param2)
{
	static char school[17][20] = 
	{
		"巫师门","华山派","武当派","古墓派","日月神教","少林派",
			"白驼山派","大理段家","峨嵋派","丐帮","灵鹫宫",
			"明教","全真教","桃花岛","星宿派","逍遥派","雪山寺"
	};
	char msg[255];
	int index;
	CChar * me = (CChar *)ob;
	CContainer * env = load_room("pk");
	if(!env->query("门派大赛"))
	{
		env->set("门派大赛",1);
		me->set("门派大赛/提示",6);
		if(!me->query("盟主/id"))//第一次比赛时，挑选第一个门派做盟主
		{
			index=1;
			me->set("盟主/门派",school[index]);
			me->set("盟主/id",index);
		}
		if(me->query("挑战/id") )
			if(me->query("挑战/id")<15)
				index=me->query("挑战/id")+1;
			else
				index=999;
		else
			index=2;//第一次开始比武，选择第二个门派做对手
		if(index==999)
		{
			//比武结束
		}
		else
		{
			me->set("挑战/门派",school[index]);
			me->set("挑战/id",index);
			me->Save();
			me->call_out(do_xuanchuan, 300);
			g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,
				"$HIR十年磨一剑，夜夜气冲天。重踏江湖之路,泯断世间恩仇。\n                              $HIC武林门派争霸赛即将开始！\n                         今天进行比赛的将是$HIR %s $HIC 对 $HIR %s$HIC。" ,
				me->querystr("盟主/门派"),me->querystr("挑战/门派"),me->query("门派大赛/提示")*5));
		}
	}
}

//比赛的宣传信息， 每5分钟发布一次
static void do_xuanchuan(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];
	if(me->query("门派大赛/提示"))
	{
		me->call_out(do_xuanchuan, 300);
		g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,
				"                $HIC武林门派争霸赛即将开始！\n                         今天进行比赛的将是$HIR %s $HIC 对 $HIR %s$HIC。\n                     请以上两派弟子做好准备，比赛将在%d分钟后开始。" ,
				me->querystr("盟主/门派"),me->querystr("挑战/门派"),me->query("门派大赛/提示")*5));
		me->add("门派大赛/提示",-1);
	}
	else
	{
		me->call_out(do_start, 10);
		g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,
				"$HIC武林门派争霸赛正式开始！\n            今天进行比赛的将是$HIR %s $HIC 对 $HIR %s$HIC。\n      10秒种后所有在线的两派弟子将自动进入比赛场景开始对抗比赛，失败者立即淘汰出局。" ,
				me->querystr("盟主/门派"),me->querystr("挑战/门派")));
	}
}

//所有选手进入比赛
static void do_start(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	
	CContainer * env = load_room("pk");
	env->set("门派大赛/start",1);
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
	
		char msg[255];
		if(EQUALSTR(me->querystr("盟主/门派"),obj->querystr("family/family_name")) ||EQUALSTR(me->querystr("挑战/门派"),obj->querystr("family/family_name")))
		{
			obj->set_temp("门派大赛/online",1);
			env->add(snprintf(msg, 255, "门派大赛/%s/count",obj->querystr("family/family_name")),1);
			tell_object(obj, "$HIR武林门派争霸赛正式开始！");
			obj->move(load_room(snprintf(msg, 255,"武道场第%d广场",random(5)+1)));
		}
    }

	me->call_out(do_start2, 5);
}

//发布进入比赛的选手人数信息
static void do_start2(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("pk");
	CChar * me = (CChar *)ob;
	char msg[255];
	int count1=env->query(snprintf(msg, 255, "门派大赛/%s/count",me->querystr("盟主/门派")));
	int count2=env->query(snprintf(msg, 255, "门派大赛/%s/count",me->querystr("挑战/门派")));
	g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,
				"\n                        $HIC当前进入武林门派争霸赛的人数如下:\n                   %s:%ld人                      %s:%ld人\n",
				me->querystr("盟主/门派"),count1,me->querystr("挑战/门派"),count2));
	me->call_out(do_end, 3600);
	me->call_out(do_fabu, 300);
}

//战报10分钟发一次
static void do_fabu(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = load_room("pk");
	CChar * me = (CChar *)ob;
	char msg[255];
	if(!env->query("门派大赛/end"))
	{
		MAP2USER * user;
		iterator_user p;
		CUser * obj;
		
		user = users();
		for ( p=user->begin(); p!=user->end(); p++)
		{
			obj = p->second;
			
			if(obj->query_temp("门派大赛/online")&&!obj->query_temp("门派大赛/die"))
			{
				CContainer * env1 = obj->environment();
				if(((CChar *)env1)->Query(CChar::IS_USER))
				{
					env1=env1->environment();
				}
				if(EQUALSTR(env1->querystr("base_name"),"fight_room"))
				{
					env1=env1->environment();
				}
				if(!env1->query("门派大赛"))//不在比武场景中
				{
					snprintf(msg, 255, "门派大赛/%s/die_count",obj->querystr("family/family_name"));
					env->add(msg,1);
					obj->set_temp("门派大赛/die",2);//门派大战中逃跑
				}
			}
		}
		int count1=env->query(snprintf(msg, 255, "门派大赛/%s/count",me->querystr("盟主/门派")))-env->query(snprintf(msg, 255, "门派大赛/%s/die_count",me->querystr("盟主/门派")));
		int count2=env->query(snprintf(msg, 255, "门派大赛/%s/count",me->querystr("挑战/门派")))-env->query(snprintf(msg, 255, "门派大赛/%s/die_count",me->querystr("挑战/门派")));

		g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,
			"\n                        $HIC当前武林门派争霸赛的各派弟子人数如下:\n                   %s:%ld人                      %s:%ld人\n",
			me->querystr("盟主/门派"),count1,me->querystr("挑战/门派"),count2));
		if(!count1 ||!count2)
		{
			me->remove_call_out(do_end);
			me->call_out(do_end, 10);
		}
		else
			me->call_out(do_fabu, 300);
	}
}

//比赛结束时间到
static void do_end(CContainer * ob, LONG param1, LONG param2)
{
	
	char msg[255];
	int point1;
	int point2;
	CChar * me = (CChar *)ob;
	CContainer * env = load_room("pk");
	if(env->querymap("门派大赛"))
	{
		int count1=env->query(snprintf(msg, 255, "门派大赛/%s/count",me->querystr("盟主/门派")))-env->query(snprintf(msg, 255, "门派大赛/%s/die_count",me->querystr("盟主/门派")));
		int count2=env->query(snprintf(msg, 255, "门派大赛/%s/count",me->querystr("挑战/门派")))-env->query(snprintf(msg, 255, "门派大赛/%s/die_count",me->querystr("挑战/门派")));
		
		point1=env->query(snprintf(msg, 255, "门派大赛/%s/point",me->querystr("盟主/门派")));//挑战门派得分
		point2=env->query(snprintf(msg, 255, "门派大赛/%s/point",me->querystr("挑战/门派")));//盟主门派得分
		g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,"$HIC武林门派争霸赛今日比赛中：$HIR%s 最终总得分：%d         %s 最终总得分：%d" ,me->querystr("盟主/门派"),point2,me->querystr("挑战/门派"),point1));
		//比赛时间未截止，已有一方门派选手全部淘汰
		if(!count1 )
		{
			//挑战门派获胜,战胜所有对方选手
			env->set("门派大赛/盟主",me->querystr("挑战/门派"));
			g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,"$HIC获胜门派为：$HIR-------- %s --------\n" ,me->querystr("挑战/门派")));
		}
		else if(!count2)
		{
			//盟主门派获胜,战胜所有对方选手
			env->set("门派大赛/盟主",me->querystr("盟主/门派"));
			g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,"$HIC获胜门派为：$HIR-------- %s --------\n" ,me->querystr("盟主/门派")));
		}
		//比赛截止时间到
		else if(point2>point1)
		{
			//盟主门派获胜
			env->set("门派大赛/盟主",me->querystr("盟主/门派"));
			g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,"$HIC获胜门派为：$HIR-------- %s --------\n" ,me->querystr("盟主/门派")));
		}
		else
		{
			//挑战门派获胜
			env->set("门派大赛/盟主",me->querystr("挑战/门派"));
			g_Channel.do_channel(&g_Channel, 0, "news",	snprintf(msg, 255,"$HIC获胜门派为：$HIR-------- %s --------\n" ,me->querystr("挑战/门派")));
		}
		
		
		CContainer * env = load_room("pk");
		MAP2USER * user;
		iterator_user p;
		CUser * obj;
		
		user = users();
		for ( p=user->begin(); p!=user->end(); p++)
		{
			obj = p->second;
			
			if(obj->query_temp("门派大赛/online"))
			{
				if((obj->environment())->query("门派大赛"))//将所有仍在比武场景的玩家移出
					obj->move(load_room(obj->querystr("start_city")) );
				if(EQUALSTR(env->querystr("门派大赛/盟主"),obj->querystr("family/family_name")))
				{
					char msg[255];
					int exp=obj->query_temp("门派大赛/count");
					
					obj->delete_temp("门派大赛");
					if(exp<1)//至少有一点奖励
						exp=1;
					if(exp>100000)//奖励不得超过10万
						exp=80000+random(20000);
					obj->add("combat_exp",exp);
					
					int repute=exp/2+random(10);
					if(obj->query("repute")<0)
						repute=-repute;
					obj->add("repute",repute);

					obj->UpdateMe();
					obj->delete_temp("门派大赛");
					tell_object(obj, snprintf(msg, 255,"$HIC\n你的门派在今日的武林门派争霸赛中获胜，因为你的卓越表现，你因此获得了%d点的经验奖励、%d点的声望奖励。\n",exp,repute));
					g_Channel.do_channel(&g_Channel, 0, "sys",snprintf(msg, 255,"%s(%s)获得了%d的武林门派争霸赛经验奖励、%d点的声望奖励。\n",obj->name(1),obj->id(1),exp,repute));
				}
			}
		}
		
		me->call_out(do_end2, 300);
	}
}

static void do_end2(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query("门派大赛/自动"))
		me->del("门派大赛/自动");
	CContainer * env = load_room("pk");
	if(env->querymap("门派大赛"))
		env->del("门派大赛");
	if(me->query("挑战/id")<15)
	{
		me->remove_call_out(do_pk);
		me->call_out(do_pk, 72000);
	}
}

/*
void init(CChar * me)
{
	CNpc::init(me);
	if( userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	
	if(! who) return;
	
    me->command(snprintf(msg, 255, "say %ld 恭喜你在新年里事事顺心、万事如意！", param1));
}
*/

virtual int do_talk(CChar * me, char * ask = NULL)
{
	
	if(userp(me) && ! is_fighting() && me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		if(! strlen(ask))
		{
			say("我是兵器商人，最爱乐善好施，有需要我帮忙的吗？", me);
			AddMenuItem("送我件盔甲吧。", "kueijia", me);
			AddMenuItem("送我把剑吧。", "sword", me);
			AddMenuItem("送我把刀吧。", "blade", me);
			AddMenuItem("送我根杖吧。", "staff", me);
			AddMenuItem("送我根鞭吧。", "bian", me);
			AddMenuItem("送我柄棍吧。", "gun", me);
		}
		else if(strcmp(ask, "kueijia") == 0)
			return do_a1(me);
		else if(strcmp(ask, "sword") == 0)
			return do_a2(me);
		else if(strcmp(ask, "blade") == 0)
			return do_a3(me);
		else if(strcmp(ask, "staff") == 0)
			return do_a4(me);
		else if(strcmp(ask, "bian") == 0)
			return do_a5(me);
		else if(strcmp(ask, "gun") == 0)
			return do_a6(me);
	}
	else
		say("我是兵器商人，最爱乐善好施，有需要我帮忙的吗？", me);
	SendMenu(me);
	return 1;
}

int do_a1(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("好吧，我这里刚好有一件铁甲，就送给你吧！", me);
		SendMenu(me);
		CContainer * bot = load_item("tiejia");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

int do_a2(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("好吧，我这里刚好有一把长剑，就送给你吧！", me);
		SendMenu(me);
		CContainer * bot = load_item("changjian");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

int do_a3(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("好吧，我这里刚好有一把钢刀，就送给你吧！", me);
		SendMenu(me);
		CContainer * bot = load_item("gangdao");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

int do_a4(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("好吧，我这里刚好有一根钢杖，就送给你吧！", me);
		SendMenu(me);
		CContainer * bot = load_item("gangzhang");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

int do_a5(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("好吧，我这里刚好有一根长鞭，就送给你吧！", me);
		SendMenu(me);
		CContainer * bot = load_item("changbian");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

int do_a6(CChar * me)
{
	if(me->query("combat_exp")<10000 && me->query_temp("hanshueiyu/count")<2)
	{
		say("好吧，我这里刚好有一根木棍，就送给你吧！", me);
		SendMenu(me);
		CContainer * bot = load_item("mugun");
		bot->set("value", 0l);      
		bot->move(me);
		me->add_temp("hanshueiyu/count",1);
		return 1;
	}
	return 1;
}

/*
static char * ask_for_present(CNpc * npc, CChar * who)
{
	char msg[255];	
	int i;
	if (who->query("combat_exp") < 3000 || who->query("mud_age") < 18000)
        return "嘿嘿，想用新玩家来骗我，没门！。";
	
	who->del("exam");
	who->del("liwu_weapon");
	who->del("liwu_book");
	who->del("youqin_gift");

	if (who->query("combat_exp") >=3000 ) 
    {
		CMapping * skl = who->query_skills();
		CVector sname;
		int how = 0;
		
		skl->keys(sname);
		
        for(i=0; i< sname.count(); i++)
            if (skl->query(sname[i]) >= 10) how ++;
			
			if(how < 3)
				return "就你的水平？再去练一会儿！。";
	} 
	
	if(EQUALSTR(who->querystr("liwu_weapon0404"), "havedone"))
		return "我的武器是很多，但你要领双份，那还是不可能的。";

	CRoom * room = CRresident::get_my_house(who);
	if(!room)
		return "你连个家都没有，哪来的物品损失？";

	if(who->query("家"))
		return "不要以为你才买的房子我不知道。。。。";
	
	static char book[31][20] = {
		"sword_1","sword_2","sword_3","zijin_staff","yuzhu_zhang","yuxiao",
		"youlongsword",	"yinlun","yaoqin","xuedao","xblade","xiao",
		"xem_sword","wuqing_sword","shenghuo_ling","sea_wood",
		"ring_whip","qingzuzang","qin","lianxindan","leizhendang",
		"langyabang","jinlun","jinhua","huoqiang","huaji","green_sword",
		"blade_2","bishou","blade_1","tongren"
	};
	
	CContainer * ob = load_item(book[random(31)]);
	
	ob->move(who);
	who->set("liwu_weapon0404", "havedone");
	
	message_vision(snprintf(msg, 255, "$n说道：仓库里面堆着这些东西都快要上绣了，趁着新年来的时候，巫师做个人情就送给你一件吧。\n由你挑，随你选，但眼睛不许挣。祝你在新年好运长存！\n$n给$N数量1的%s。",  ob->name()), who, npc);
	return 0;
}
*/
NPC_END;



