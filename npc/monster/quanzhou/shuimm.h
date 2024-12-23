//shuimm.h
//水栀子·任务ＮＰＣ·台湾（改在泉洲）·做任务·类别：找东西·难度３０
//Teapot 2001-02-05
//Last Modify @ 2001-02-08
//Increase Bonus.
//Fix two bugs.


NPC_BEGIN(CNquanzhou_shuimm);

virtual void create()
{
	set_name("水栀子", "shui mm");
	set("long", "她一身飘逸的白色长裙，极尽人间绝色。");
	set("title", "泉洲青龙会副会长　「花分一脉」");
	set("gender", "女性");
	set("age", 17);
	set("per",40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("no_huan",1);
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 3, me->object_id());
	}
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	CNpc::do_talk(me,ask);
	me->set_temp("teapot/shui", 1);
	AddMenuItem("向水栀子询问任务", "$0askquest $1", me);
	AddMenuItem("向水栀子索要任务", "$0getquest $1", me);
	AddMenuItem("向水栀子要求清除任务", "$0cleanquest $1", me);
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("teapot/shui"))
	{
		me->delete_temp("teapot/shui");
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);
		if(strcmp(comm, "getquest") == 0)
			return do_gq(me);
		if(strcmp(comm, "cleanquest") == 0)
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
		{"包子", "baozi", 2,60,},
		{"牛皮酒袋", "jiudai", 2,60,},
		{"普通匕首", "dagger", 3,60,},
		{"军服", "junfu", 4,60,},
		{"铁甲", "tiejia", 3,60,},
		{"石块", "shikuai", 4,60,},
		{"金币", "coin", 4,60,},
		{"腹蛇胆", "shedan", 4,60,},
		{"老虎的尸体", "corpse", 5,60,},
		{"青蛇胆", "qingdan", 4,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl2[10] = {				//11~20
		{"铁锤", "hammer", 5,60,},
		{"瑶琴", "yaoqin", 6,60,},
		{"狗肉汤", "gouroutang", 6,60,},
		{"马夫的尸体", "corpse", 7,60,},
		{"垂钓者的尸体", "corpse", 7,60,},
		{"武将的尸体", "corpse", 7,60,},
		{"芝麻酥", "zhima su", 5,60,},
		{"铁锹", "tieqiao", 8,60,},
		{"长枪", "changqiang", 10,60,},
		{"夜行水靠", "shuikao", 9,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl3[10] = {				//21~30
		{"三股叉", "fork", 12,60,},
		{"丧门斧", "axe", 10,60,},
		{"黄布袈裟", "xu cloth", 10,60,},
		{"禅杖", "chanzhang", 11,60,},
		{"护法袈裟", "xuan cloth", 13,60,},
		{"袈裟", "jiasha", 17,60,},
		{"花瓣", "huaban", 14,60,},
		{"白色长袍", "baipao", 10,60,},
		{"药锄", "yaochu", 17,60,},
		{"何首乌", "shouwu", 11,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl4[10] = {				//31~40 : 20~30
		{"灰色道袍", "greyrobe", 20,60,},
		{"粉红绸衫", "pink cloth", 28,60,},
		{"黑色长衫", "heiyi", 30,60,},
		{"牛肉羹", "niu rou geng", 20,60,},
		{"桃木剑", "taomu jian", 24,60,},
		{"双刃剑", "shuang jian", 30,60,},
		{"钝剑", "dun jian", 22,60,},
		{"君子剑", "junzi jian", 28,60,},
		{"玉女剑", "yunv jian", 26,60,},
		{"碧血剑", "bixue jian", 24,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl5[10] = {				//41~50 : 30~50
		{"玄铁剑", "xuantie jian", 30,60,},
		{"青虹剑", "tie jian", 32,60,},
		{"青龙剑", "dragon sword", 34,60,},
		{"淑女剑", "shunv jian", 36,60,},
		{"龙胆剑", "longdan jian", 44,60,},
		{"百花聚精膏", "baihua gao", 32,60,},
		{"接骨散", "jiegu san", 36,60,},
		{"天仙玉露", "tianxian yulu", 40,60,},
		{"九转回神丹", "jiuzhuan dan", 44,60,},
		{"天香续命膏", "tianxiang gao", 48,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl6[10] = {				//51~60 : 50~70
		{"宫廷秘方", "gongting mifang", 60,60,},
		{"烈焰剑", "lieyan jian", 50,60,},
		{"青风刃", "qingfen ren", 54,60,},
		{"破玉剑", "poyu jian", 58,60,},
		{"干将剑", "ganjian jian", 62,60,},
		{"莫邪剑", "moye jian", 64,60,},
		{"轩辕剑", "xuyuan jian", 68,60,},
		{"盘古剑", "pangu jian", 72,60,},
		{"百香花", "baixiang", 72,60,},
		{"黑色袈裟", "jia sha", 64,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl7[10] = {				//61~70 : 50~80
		{"金边黑布袈裟", "jia sha", 50,60,},
		{"断掉的长鞭", "changbian", 80,60,},
		{"渡劫的尸体", "corpse", 70,60,},
		{"达摩令", "damo ling", 50,60,},
		{"铁焰令", "tieyan ling", 60,60,},
		{"重阳令", "chongyang ling", 60,60,},
		{"福冈一文字", "fuganyi wenzi", 50,60,},
		{"一晚十次刀", "Tiger blade", 80,60,},
		{"草莓", "caomei", 70,60,},
		{"玉箫", "yuxiao", 72,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl8[10] = {				//71~80 : 60~80
		{"无常", "wuchang dao", 60,60,},
		{"虎澈", "huche dao", 62,60,},
		{"福冈一文字", "fuganyi wenzi", 64,60,},
		{"菊一文字", "jvyi wenzi", 66,60,},
		{"长船", "changchuang dao", 68,60,},
		{"长光", "zhangguang dao", 70,60,},
		{"正恒", "zhengheng dao", 72,60,},
		{"寒雨", "hanyu dao", 74,60,},
		{"铁手套", "shou tao", 60,60,},
		{"朱红披风", "pi feng", 65,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvl9[10] = {				//81~90 : 60~100
		{"乌龟甲", "wugui jia", 60,60,},
		{"豹纹披风", "pi feng", 64,60,},
		{"大红披风", "pi feng", 68,60,},
		{"鹿皮靴", "pi xue", 72,60,},
		{"花头巾", "tou jin", 76,60,},
		{"虎皮手套", "shou tao", 80,60,},
		{"小楼一夜听春雨", "Spring blade", 84,60,},
		{"一晚十次刀", "Tiger blade", 88,60,},
		{"清雪流光斩", "Snow blade", 92,60,},
		{"大风刀", "Wind blade", 100,60,},
	};
	static struct{
		char name[20];
		char id[20];
		int  exp;			//经验
		int	 time;			//时间
	} lvlmax[10] = {			//90+ : 80~100
		{"陈居阳的尸体", "corpse", 80,60,},
		{"岳不凡的尸体", "corpse", 90,60,},
		{"周采薇的尸体", "corpse", 80,60,},
		{"金轮明王的尸体", "corpse", 90,60,},
		{"梅燕笙的尸体", "corpse", 100,60,},
		{"龙木的尸体", "corpse", 90,60,},
		{"简有招的尸体", "corpse", 80,60,},
		{"梁有桥的尸体", "corpse", 80,60,},
		{"逍遥女的尸体", "corpse", 80,60,},
		{"论语", "lun yu", 90,60,},
	};
	
	long i;
	long e;
	char msg[255];
	
	
	i=current_time;

	e=me->query("shui/overtime");
	if(e && i>e)
	{
	    message_vision("$N扬了扬眉。",this);
		say("你上一个任务没有完成……", me);
		SendMenu(me);
		me->set("shui/finish",0l);	
		me->del("shui/id");		
		me->del("shui/name");	
		me->del("shui/overtime");	
		me->del("shui/exp");		
		me->set("hp",me->query("hp")/2);
		me->set("mp",me->query("mp")/2);
	}

	if(e && i<=e)
	{
	    message_vision("$N扬了扬眉。",this);
		say("你上一个任务还没完成……", me);
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

	me->set("shui/name",shuiname);
	me->set("shui/id",shuiid);
	me->set("shui/exp",shuiexp);

	say(snprintf(msg, 255, "水栀子说道：去找%s(%s)给我……", shuiname, shuiid), me);
	i=400-me->query("level");
	i=i+shuitime;
	i=(i+random(i))/2;
	me->set("shui/overtime",current_time+i);
	e=i/60;
	i=i-e*60;
	say(snprintf(msg, 255, "水栀子说道：给你%d分%d秒去完成吧。", e,i), me);
	SendMenu(me);

	//g_Channel.do_channel(&g_Channel, 0, "sys", 
	//	snprintf(msg, 255, "%s接找%s的任务，时限%d分%d秒。", me->name(1), shuiname, e, i));
	return 1;
}

// shui/id shui/name shui/overtime shui/exp shui/finish

int do_aq(CChar * me)
{
	if(!me->query("shui/overtime"))
	{
	    message_vision("$n看着$N扬了扬眉毛，微微一笑。", me,this);
		say("你可以从我这里领取任务，以获得经验的奖励。", me);
		say("完成的任务越多，经验就越高。", me);
		say("当然，如果要了任务而没完成，是要受惩罚的。", me);
		SendMenu(me);
		return 1;
	}
	long i;
	long e;
	
	char msg[255];

	i=current_time;
	e=me->query("shui/overtime");
	if (i>e)
	{
	    message_vision("$N皱了皱眉头。",this);
		say("对不起……时间已经过了，你没有完成任务。", me);
		SendMenu(me);
		return 1;
	}
	i=e-i;
	e=i/60;
	i=i-e*60;

    say("水栀子微微蹩眉，道：让我想想……", me);
	say(snprintf(msg, 255, "水栀子说道：啊，你现在的任务是寻找%s(%s)。", me->querystr("shui/name"),me->querystr("shui/id")), me);
	say(snprintf(msg, 255, "水栀子说道：距离任务时限还有%d分%d秒……", e,i), me);
	SendMenu(me);
	return 1;
}

// shui/id shui/name shui/overtime shui/exp shui/finish




int do_cq(CChar * me)
{
	if(!me->query("shui/overtime"))
	{
		say("你并没有领取任务……", me);
		SendMenu(me);
		return 1;
	}

		say("你给我７０１文钱，我就清除这次的任务。", me);
		SendMenu(me);
		return 1;
return 1;
}




static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

    message_vision("$n看着$N扬了扬眉毛，神态清雅如诗。", who, me);

	return;
}



virtual int accept_object(CChar * who, CContainer * ob)
{
	long i;
	char msg[255];

	//1。newbie的任务 lanwood 2001-05-30
	if(who->query_temp("newbie/shuimm") == ob->object_id())
	{
		long money = 100 + random(100);
		say("你是新来的呀。这里有点钱，先拿去花吧。一开始不要买太贵的装备哦。不然很快就会没钱的。", who);
		SendMenu(who);
		message_vision(snprintf(msg, 255, "$N给$n数量%ld的金币。", money), this, who);
		CMoney::Pay_Player(who, money);
		destruct(ob);
		return 1;
	}

	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")==701)
	{
		//g_Channel.do_channel(&g_Channel, 0, "sys", 
		//snprintf(msg, 255, "%s清除找%s的任务！", who->name(1), who->querystr("shui/name")));
		who->del("shui/id");
		who->del("shui/name");
		who->del("shui/exp");
		who->del("shui/overtime");
		who->del("shui/finish");	// Clear Finish 	

		destruct(ob);
		return 1;
	}


	if ( DIFFERSTR(ob->querystr("id"), who->querystr("shui/id")) || DIFFERSTR(ob->querystr("name"), who->querystr("shui/name")) )
	{	
		say("水栀子扬扬眉毛，说：这是什么东西？", who);
		SendMenu(who);
		return 0;
	}

	if( ob->query("is_user") )
	{
		say("水栀子摇摇头：这是什么东西，我不要！", who);
		SendMenu(who);
		return 0;
	}

	long e;
	
	e=who->query("shui/overtime");
	i=current_time;

	if (i>e)
	{
		destruct(ob);	
		say("水栀子一扬眉毛，说：你知道时间已经过了吗？", who);
		SendMenu(who);
		return 1;
	}
	
	who->add("shui/finish",1);
	i=who->query("shui/exp");
	e=who->query("shui/finish");
	if(e<30)
		i=i*(e+5)/5;		// Gains more exp 
	else
		i=i*6;				// Limit:6
	i=(random(i)+i)*8/3;	// Now i @ 1.5 . was *4/3.
	i=i+(100-who->query("level"))/3;

	//g_Channel.do_channel(&g_Channel, 0, "sys", 
	//	snprintf(msg, 255, "%s完成找%s的任务，获得%ld经验！", who->name(1), who->querystr("shui/name"), i));

	who->add("combat_exp",i);
	who->del("shui/id");
	who->del("shui/name");
	who->del("shui/exp");
	who->del("shui/overtime");
	 
    message_vision("$n对$N扬了扬眉毛，露出一丝笑容。", who,this);
    message_vision(snprintf(msg, 255, "$N获得了%d经验！", i), who,this);

	destruct(ob);

	return 1;
}


virtual void die()
{
	revive(1);
	message_vision("$N望空中深深的吸了口气。", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

}

NPC_END;

// shui/id shui/name shui/overtime shui/exp shui/finish
