//lse.h
//陆山鹅·任务ＮＰＣ·台湾（改在泉洲）·做任务·类别：杀人·难度３０
//Teapot 2001-02-09


NPC_BEGIN(CNquanzhou_lse);

virtual void create()
{
	set_name("陆山鹅", "shan er");
	set("title", "前泉洲青龙会成员");
	set("gender", "男性");
	set("age", 21);
	set("per", 1);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("icon", young_man3);
	set("no_talk",1);
	set("no_huan",1);
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	CNpc::do_talk(me,ask);
	me->set_temp("teapot/lu32", 1);
	AddMenuItem("向陆山鹅询问任务", "$0askquest $1", me);
	AddMenuItem("向陆山鹅索要任务", "$0getquest $1", me);
	AddMenuItem("向陆山鹅要求清除任务", "$0clearquest $1", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("teapot/lu32"))
	{
		me->delete_temp("teapot/lu32");
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);
		if(strcmp(comm, "getquest") == 0)
			return do_gq(me);
		if(strcmp(comm, "clearquest") == 0)
			return do_cq(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

// shui/id shui/name shui/overtime shui/exp shui/finish

int do_gq(CChar * me)
{
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl1[10] = {				// 0~10
		{"男孩", "boy", 2,60,},
		{"女孩", "girl", 2,60,},
		{"宋兵", "bing", 3,60,},
		{"小偷", "thief", 4,60,},
		{"毒蛇", "du she", 3,60,},
		{"进香客", "guest", 4,60,},
		{"老虎", "laofu", 4,60,},
		{"竹叶青蛇", "qing she", 4,60,},
		{"太监", "taijian", 5,60,},
		{"陪练童子", "tongzi", 4,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl2[10] = {				//11~20
		{"酒馆老板", "lao ban", 5,60,},
		{"香火道人", "xianghuo", 6,60,},
		{"绿营会众", "lvying huizong", 6,60,},
		{"流氓头", "liumangtou", 7,60,},
		{"游方道人", "youfang daoren", 7,60,},
		{"锦衣卫士", "weishi", 7,60,},
		{"黄衣卫士", "weishi", 5,60,},
		{"段无味", "duan wuwei", 8,60,},
		{"曾广勇", "kuai huosan", 10,60,},
		{"李斧头", "li futou", 9,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl3[10] = {				//21~30
		{"傅思远", "fu siyuan", 12,60,},
		{"宁真师太", "ningzhen shitai", 10,60,},
		{"宁慧师太", "ninghui shitai", 10,60,},
		{"黎明", "li ming", 11,60,},
		{"江上流", "jiang shangliu", 13,60,},
		{"空空", "kong kong", 17,60,},
		{"左齐", "zuo qi", 14,60,},
		{"冷逊", "leng xun", 10,60,},
		{"封杯蛇", "feng beishe", 17,60,},
		{"胡铁牛", "hu tieniu", 11,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl4[10] = {				//31~40 : 20~30
		{"李教头", "li", 20,60,},
		{"范骏", "fan jun", 28,60,},
		{"静玄师太", "jingxuan shitai", 30,60,},
		{"鲁有腿", "lu youjiao", 20,60,},
		{"彭有劲", "peng youjing", 24,60,},
		{"刘在玄", "liu zaixuan", 30,60,},
		{"郝小通", "hao xiaotong", 22,60,},
		{"丘在机", "qiu zaiji", 28,60,},
		{"马玉", "ma yu", 26,60,},
		{"耶律平", "Yelv ping", 24,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl5[10] = {				//41~50 : 30~50
		{"白少庄主", "ouyang ke", 30,60,},
		{"华赫金", "hua hejin", 32,60,},
		{"高升平", "gao shengping", 34,60,},
		{"简有招", "jian youzhao", 36,60,},
		{"梁有桥", "liang cuangong", 44,60,},
		{"龙儿", "long er", 32,60,},
		{"岳夫人", "yue wife", 36,60,},
		{"剑梅", "jian mei", 40,60,},
		{"殷天罡", "yin tiangang", 44,60,},
		{"谢谦", "xie qian", 48,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl6[10] = {				//51~60 : 50~70
		{"段正朴", "duan zhengpu", 60,60,},
		{"周采薇", "zhou caiwei", 50,60,},
		{"封不坦", "feng butan", 54,60,},
		{"丛不放", "cong bufang", 58,60,},
		{"竹虚", "zhu xu", 62,60,},
		{"范逍", "fan xiao", 64,60,},
		{"杨遥", "yang yao", 68,60,},
		{"韦三笑", "wei sanxiao", 72,60,},
		{"苏情", "su quan", 72,60,},
		{"洪安顺", "hong anshun", 64,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl7[10] = {				//61~70 : 50~80
		{"高人", "gao laozhe", 50,60,},
		{"陈远北", "chen yuan bei", 80,60,},
		{"鸠摩香", "jiumo xiang", 60,60,},
		{"洪安顺", "hong anshun", 70,60,},
		{"血刀王", "xuedao wang", 60,60,},
		{"俞莲舟", "yu lianzhou", 60,60,},
		{"张松溪", "zhang songxi", 50,60,},
		{"宋远桥", "song yuanqiao", 80,60,},
		{"血刀王", "xuedao wang", 70,60,},
		{"萨木活佛", "samu huofo", 72,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl8[10] = {				//71~80 : 60~80
		{"龙木", "long daozhu", 60,60,},
		{"李清照", "li qing zhao", 62,60,},
		{"鸠摩香", "jiumo xiang", 64,60,},
		{"金轮明王", "inlun fawang", 66,60,},
		{"陈远北", "chen yuan bei", 68,60,},
		{"张松溪", "zhang songxi", 60,60,},
		{"木龙", "mu daozhu", 62,60,},
		{"鸠摩香", "jiumo xiang", 64,60,},
		{"金轮明王", "inlun fawang", 66,60,},
		{"陈远北", "chen yuan bei", 68,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl9[10] = {				//81~90 : 60~100
		{"李清照", "li qing zhao", 60,60,},
		{"鸠摩香", "jiumo xiang", 64,60,},
		{"鸠摩香", "jiumo xiang", 68,60,},
		{"龙木", "long daozhu", 72,60,},
		{"木龙", "mu daozhu", 76,60,},
		{"逍遥女", "xiaoyao nv", 80,60,},
		{"陈远北", "chen yuan bei", 68,60,},
		{"龙木", "long daozhu", 72,60,},
		{"木龙", "mu daozhu", 76,60,},
		{"金轮明王", "inlun fawang", 80,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvlmax[10] = {			//90+ : 80~100
		{"李清照", "li qing zhao", 60,60,},
		{"鸠摩香", "jiumo xiang", 64,60,},
		{"鸠摩香", "jiumo xiang", 68,60,},
		{"龙木", "long daozhu", 72,60,},
		{"木龙", "mu daozhu", 76,60,},
		{"金轮明王", "inlun fawang", 80,60,},
		{"陈远北", "chen yuan bei", 68,60,},
		{"龙木", "long daozhu", 72,60,},
		{"木龙", "mu daozhu", 76,60,},
		{"逍遥女", "xiaoyao nv", 80,60,},
	};
	
	long i;
	long e;
	char msg[255];
	
	
	i=current_time;

	e=me->query_temp("lu32/overtime");
	if(e && i>e)
	{
	    message_vision("$N低声骂了句什么。",this);
		say("□□□□□，又没按时完成。", me);
		SendMenu(me);
		me->set_temp("lu32/finish",0l);	
		me->delete_temp("lu32/id");		
		me->delete_temp("lu32/name");	
		me->delete_temp("lu32/overtime");	
		me->delete_temp("lu32/exp");		
		me->set("hp",me->query("hp")/4);
		me->set("mp",me->query("mp")/4);
	}

	if(e && i<=e)
	{
		say("不是让你去杀人吗？磨什么！", me);
		SendMenu(me);
		return 0;
	}

	i=me->query("level");
	e=i/3;
	i=i-e+2*random(e);
	const char * shuiname = "";
	const char * shuiid = "";
	int shuitime = 0;
	int shuiexp = 0;

	int task = random(10);

	switch(i/10)
	{
	case 0:
		shuiname=lvl1[task].name;
		shuiid=lvl1[task].id;
		shuiexp=lvl1[task].exp;
		shuitime=lvl1[task].time;
		break;
	case 1:
		shuiname=lvl2[task].name;
		shuiid=lvl2[task].id;
		shuiexp=lvl2[task].exp;
		shuitime=lvl2[task].time;
		break;
	case 2:
		shuiname=lvl3[task].name;
		shuiid=lvl3[task].id;
		shuiexp=lvl3[task].exp;
		shuitime=lvl3[task].time;
		break;
	case 3:
		shuiname=lvl4[task].name;
		shuiid=lvl4[task].id;
		shuiexp=lvl4[task].exp;
		shuitime=lvl4[task].time;
		break;
	case 4:
		shuiname=lvl5[task].name;
		shuiid=lvl5[task].id;
		shuiexp=lvl5[task].exp;
		shuitime=lvl5[task].time;
		break;
	case 5:
		shuiname=lvl6[task].name;
		shuiid=lvl6[task].id;
		shuiexp=lvl6[task].exp;
		shuitime=lvl6[task].time;
		break;
	case 6:
		shuiname=lvl7[task].name;
		shuiid=lvl7[task].id;
		shuiexp=lvl7[task].exp;
		shuitime=lvl7[task].time;
		break;
	case 7:
		shuiname=lvl8[task].name;
		shuiid=lvl8[task].id;
		shuiexp=lvl8[task].exp;
		shuitime=lvl8[task].time;
		break;
	case 8:
		shuiname=lvl9[task].name;
		shuiid=lvl9[task].id;
		shuiexp=lvl9[task].exp;
		shuitime=lvl9[task].time;
		break;
	
	default:
		shuiname=lvlmax[task].name;
		shuiid=lvlmax[task].id;
		shuiexp=lvlmax[task].exp;
		shuitime=lvlmax[task].time;
	}	

	me->set_temp("lu32/name",shuiname);
	me->set_temp("lu32/id",shuiid);

	i=380-me->query("level")*2;
	i=i+shuitime;
	i=(i+random(i))/2;
	me->set_temp("lu32/overtime",current_time+i);
	e=i/60;
	i=i-e*60;

	say(snprintf(msg, 255, "陆山鹅说：既然你这么想杀人，就顺手杀了%s(%s)吧！", shuiname, shuiid), me);
	say(snprintf(msg, 255, "陆山鹅说：不过我可没耐心久等，给你%d分%d秒去杀他", e,i), me);
	SendMenu(me);

	
	//g_Channel.do_channel(&g_Channel, 0, "sys", 
	//	snprintf(msg, 255, "%s接杀%s的任务，时限%d分%d秒。", me->name(1), shuiname, e, i));

	me->add_temp("lu32/finish",1);
	i=shuiexp+random(shuiexp);
	e=me->query_temp("lu32/finish");
	if(e<30)
		i=i*(e+5)/5;		// Gains more exp 
	else
		i=i*6;				// Limit:6
//	i=(random(i)+i)*8/3;	// Now i @ 1.5 . was *4/3.
	i=(random(i)+i)*4/3;

	i=i+(100-me->query("level"))*2/3;

	me->set_temp("lu32/exp", i);

	return 1;
}


int do_aq(CChar * me)
{
	if(!me->query_temp("lu32/overtime"))
	{
	    message_vision("$n看着$N，嘴里念叨着什么。", me,this);
		say("你想杀人？", me);
		say("顺便帮我杀几个吧。", me);
		say("当然，□□是会付回报给你的。", me);
		SendMenu(me);
		return 1;
	}
	long i;
	long e;
	char msg[255];

	i=current_time;
	e=me->query_temp("lu32/overtime");
	if (i>e)
	{
	    message_vision("$N骂了一句。",this);
		say("□□□，又没有完成。", me);
		SendMenu(me);
		return 1;
	}
	i=e-i;
	e=i/60;
	i=i-e*60;

    message_vision("$N不干净的说了句什么。",this);
	say(snprintf(msg, 255, "陆山鹅说：我不是让你去杀了%s(%s)吗！", me->querystr_temp("lu32/name"),me->querystr_temp("lu32/id")), me);
	say(snprintf(msg, 255, "陆山鹅说：只有%d分%d秒了！", e,i), me);
//	say(snprintf(msg, 255, "陆山鹅说：既然你这么想杀人，就顺手杀了%s(%s)吧！", me->querystr("lu32/name"),me->querystr("lu32/id")), me);
//	say(snprintf(msg, 255, "陆山鹅说：不过我可没耐心久等，给你%d分%d秒去杀他", e,i), me);
	SendMenu(me);
	return 1;
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

    message_vision("$n看了眼$N，口中不干不净的说了句什么。", who, me);

	return;
}


int do_cq(CChar * me)
{
	if(!me->query_temp("lu32/overtime"))
	{
		say("你并没有领取任务，笨！", me);
		SendMenu(me);
		return 1;
	}

		say("你给我１７０１文钱，我就清除这次的任务。", me);
		SendMenu(me);
		return 1;
return 1;
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")==1701)
	{
		//g_Channel.do_channel(&g_Channel, 0, "sys", 
		//snprintf(msg, 255, "%s清除杀%s的任务！", who->name(1), who->querystr("lu23/name")));
		who->delete_temp("lu32/id");
		who->delete_temp("lu32/name");
		who->delete_temp("lu32/exp");
		who->delete_temp("lu32/overtime");
		who->delete_temp("lu32/finish");	// Clear Finish 	
		destruct(ob);
		return 1;
	}

return 0;
}

void die()
{
	revive(1);
	message_vision("$N望空中深深的吸了口气。", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

}

NPC_END;

//吕布用拇指和食指从鬓间拈出一根绣花针