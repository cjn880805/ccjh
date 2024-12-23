// pub_sun.c
//code by Fisho
//date : 2000-12-14
//inherit F_BANKER;

BANKOWNER_BEGIN(CNpub_sun);

virtual void create()
{
	set_name("孙剥皮","sun bopi");

	set("icon", pawnshop_boss);
	set("title", "钱庄老板");
	set("nickname", "一毛不拔");
	set("gender", "男性");
	set("age", 44);
	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);
	set("hp", 500);
	set("max_hp", 1500);
	set("repute", 0l);
	
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
	add_money( 5);
	set("no_talk",1);
	set("no_huan",1);
}

virtual char * chat_msg()
{
	//巫师手动立即开奖
	if(query("jp")&!query("jp_ok"))
	{
		this->remove_call_out(do_renwu);
		call_out(do_renwu, 1);
		set("jp_ok",1);
//		del("jp");
	}
	switch (random(3) )
	{
	case 0:
		return "孙剥皮骄傲的说道：本银号已经有上百年的历史，在江南可以说是第一家。";
	case 1:
		return "孙剥皮笑着说道：在本店存钱无利息，客官您看着办吧。";
	case 2:
		return "孙剥皮得意洋洋说道：本店新开设博彩活动，只要你有本期新发售的彩票就有机会获得大奖哟！。";
	}
	return "";
}

virtual void init(CChar *me)
{
	if(me->query_temp("lj/renwu110")||me->query_temp("zhang/百晓生"))
	{
		tell_object(me,"\n$HIR孙剥皮笑嘻嘻的凑到你的面前：这位客官，是不是您在为百晓生百老爷子不收您的钱而发愁呢？\n");
	}
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("lj/renwu110")||me->query_temp("zhang/百晓生"))
	{
		say("孙剥皮诡异的笑到：百老爷子平生不爱别人给他送礼。",me);
		say("不过如果有心人把钱存到本银号他老爷子的帐上，我想他老爷子心里还是喜欢的。",me);
		SendMenu(me);
		return 1;
	}
	CContainer * biaozhi = load_room("pk");
	char msg[255];
	if(! strlen(ask))
	{
		if(biaozhi->query("cp/random"))
		{
			AddMenuItem("查看彩票活动奖品", "name", me);
			if(!query("cp/number"))
				AddMenuItem("查看彩票活动开奖时间", "time", me);
			else
				AddMenuItem("查看获奖彩票号码", "nember", me);
		}
		if(me->query("grant") > 95)
		{
			AddMenuItem("设置彩票掉落几率", "$2random $1 $2", me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "name"))
	{
		say(snprintf(msg, 255,"本期彩票活动的奖品是：%s",biaozhi->querystr("cp/jp_name")), me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "time"))
	{
		say("每期彩票活动的开奖时间固定为：每个周六的晚上八点整。", me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "nember") && query("cp/number"))
	{
		say(snprintf(msg, 255,"本期彩票活动的获奖号码是：%d。", query("cp/number")),me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * bot;
	if(who->is_busy())
		return notify_fail("你上一个动作还没有完成");

	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value") >=500000 )
	{	
		if(who->query_temp("lj/renwu110")&&!who->query("lj/面具"))
		{
			tell_object(who,"孙剥皮笑着说道：这位客官，我已经按您的意思把这50万的银子存好了！这里有张收据，您请收好。");
			bot = load_item("lbook1");
			bot->set("主人",who->querystr("id"));
			bot->set_name("银号收条");
			bot->move(who);
			who->delete_temp("lj/renwu110");
			who->set_temp("lj/renwu1101",1);
			destruct(ob);
			return 1;
		}
		else if(who->query_temp("zhang/百晓生"))
		{
			tell_object(who,"孙剥皮笑着说道：这位客官，我已经按您的意思把这50万的银子存好了！这里有张收据，您请收好。");
			bot = load_item("lbook1");
			bot->set("主人",who->querystr("id"));
			bot->set_name("银号收条");
			bot->move(who);
			destruct(ob);
			return 1;
		}
	}
	if(query("cp/number")&&query("cp/start"))
	{
		if(EQUALSTR(ob->querystr("id"), "cai piao") && ob->query("number") ==query("cp/number")
			 && ob->query("index") ==query("cp/index"))
		{
			destruct(ob);
			CContainer * biaozhi = load_room("pk");
			char msg[255];
			load_item(biaozhi->querystr("cp/jp"))->move(who);
			message_vision(snprintf(msg, 255,"$HIW$n送给$N一个$HIR%s$HIW。",biaozhi->querystr("cp/jp_name")),who,this);
			
			g_Channel.do_channel(this, NULL, "news", snprintf(msg, 255,	"$HIW%s(%s)已经兑换第 $HIR%d$HIW 期奖品 $HIR%s$HIW 。"
							,who->name(),who->id(),query("cp/index"),biaozhi->querystr("cp/jp_name")));

			//设置奖品
			static char baowu[51][20]={
				"38huoqiang","xuantiebishou","dagoubang","shenshe_staff","haoseshan","btzheng","taibaizao","zwsword",
					"lvzhuxiao","conglinjian","newyear","newyear1","century_war","tiancanbaojia","fannaomao","liaochengpao",
					"yinguozhu","bolanxie","zhangmenhuan","jinhuantoushi","ruanweijia","shajiezhi","zidiaopifeng","dulonglian",
					"yinmopao","diaojiandai","xiantianyu","poliquan","yanshuhua","fengyizhen","jinlianxie","kuihuaao","xuanwupao",
					"yunshenglv","zijianhun","qinjianhun","luoshenjin","linboxie","zueiyupao","hanyuzhi","lantiandai","cangzuihu",
					"rumengdai","baomingdan","huanchunwan","bing_1","bing_2","bing_3","bing_4","bing_5","bing_6",
			};
			int index=random(50);
			if(index>44)
				index=random(50);
			CContainer * bot=load_item(baowu[index]);
			biaozhi->set("cp/jp",bot->id());
			biaozhi->set("cp/jp_name",bot->name());
			del("cp");
			destruct(bot);
			return 1;
		}
	}
	return 0;
}

/*
virtual void init(CChar *me)
{
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
	delete_temp("busy");
}
*/

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp(comm,"random") == 0 && wizardp(me))
		return do_flatter(me,arg);

	return CBankOwner::handle_action(comm, me, arg);
}


int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("不能为空。 ");
	int jv = atoi(arg);
	if(jv<0 ||jv>100)
		return notify_fail("设置几率非法。");

	static char baowu[51][20]={
		"38huoqiang","xuantiebishou","dagoubang","shenshe_staff","haoseshan","btzheng","taibaizao","zwsword",
		"lvzhuxiao","conglinjian","newyear","newyear1","century_war","tiancanbaojia","fannaomao","liaochengpao",
		"yinguozhu","bolanxie","zhangmenhuan","jinhuantoushi","ruanweijia","shajiezhi","zidiaopifeng","dulonglian",
		"yinmopao","diaojiandai","xiantianyu","poliquan","yanshuhua","fengyizhen","jinlianxie","kuihuaao","xuanwupao",
		"yunshenglv","zijianhun","qinjianhun","luoshenjin","linboxie","zueiyupao","hanyuzhi","lantiandai","cangzuihu",
		"rumengdai","baomingdan","huanchunwan","bing_1","bing_2","bing_3","bing_4","bing_5","bing_6",
	};

	CContainer * biaozhi = load_room("pk");
	tell_object(me,snprintf(msg,255,"设置彩票掉落几率为：%d。（数字越大，掉落几率越低）", jv));
	biaozhi->set("cp/random",jv);
	//设置奖品
	int index=random(50);
		if(index>44)
			index=random(50);
	CContainer * bot=load_item(baowu[index]);
	biaozhi->set("cp/jp",bot->id());
	biaozhi->set("cp/jp_name",bot->name());
	biaozhi->add("cp/index",1);
	this->remove_call_out(do_renwu);
	call_out(do_renwu, 1);

	return 1;
}

static void do_renwu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	time_t t;	
	struct tm * newtime;
	time(&t);
	newtime = localtime(&t); 
	
	char msg[255];
	
	CContainer * biaozhi = load_room("pk");
	if(newtime->tm_wday == 3 && newtime->tm_hour >= 20 && me->query("cp/number"))
	{
		g_Channel.do_channel(&g_Channel, NULL, "news", snprintf(msg, 255,	"$HIW第 $HIR%d$HIW 期彩票中奖号码 $HIR%d$HIW 所得奖品 $HIR%s$HIW 因无人领取而作废。"
			,me->query("cp/index"),me->query("cp/number"),biaozhi->querystr("cp/jp_name")));
		
		//设置奖品
		static char baowu[51][20]={
			"38huoqiang","xuantiebishou","dagoubang","shenshe_staff","haoseshan","btzheng","taibaizao","zwsword",
				"lvzhuxiao","conglinjian","newyear","newyear1","century_war","tiancanbaojia","fannaomao","liaochengpao",
				"yinguozhu","bolanxie","zhangmenhuan","jinhuantoushi","ruanweijia","shajiezhi","zidiaopifeng","dulonglian",
				"yinmopao","diaojiandai","xiantianyu","poliquan","yanshuhua","fengyizhen","jinlianxie","kuihuaao","xuanwupao",
				"yunshenglv","zijianhun","qinjianhun","luoshenjin","linboxie","zueiyupao","hanyuzhi","lantiandai","cangzuihu",
				"rumengdai","baomingdan","huanchunwan","bing_1","bing_2","bing_3","bing_4","bing_5","bing_6",
		};
		//控制掉落饼的几率，如出现饼则再重新计算一次
		int index=random(50);
		if(index>44)
			index=random(50);
		CContainer * bot=load_item(baowu[index]);
		biaozhi->set("cp/jp",bot->id());
		biaozhi->set("cp/jp_name",bot->name());
		me->del("cp/number");
		me->del("cp/index");
		destruct(bot);
		me->call_out(do_renwu, 3600);
	}
	else if(newtime->tm_wday == 6 && newtime->tm_hour >= 20 && biaozhi->query("cp/random")&& !me->query("cp/number")
		||me->query("jp"))//每周六晚上八点开奖
	{
		int number=biaozhi->query("cp/number");
		if(number)
		{
			int jp=random(number)+1;
			me->set("cp/number",jp);
			me->set("cp/index",biaozhi->query("cp/index"));
			g_Channel.do_channel(&g_Channel, NULL, "news", snprintf(msg, 255,
				"\n\n$HIW第 $HIR%d$HIW 期彩票已经开奖，中奖号码为： $HIR%d$HIW ，请拥有此彩票的玩家在5分钟后（重起前有效）凭彩票去苏州聚宝斋孙老板兑换本期奖品 $HIR%s$HIW 。\n\n"
				,me->query("cp/index"),jp,biaozhi->querystr("cp/jp_name")));
			biaozhi->del("cp/number");
			biaozhi->add("cp/index",1);
			if(me->query("jp"))
				me->del("jp");
			if(me->query("jp_ok"))
				me->del("jp_ok");
			me->call_out(do_renwu, 18000);
			me->call_out(do_start, 5);
		}
	}
	else
		me->call_out(do_renwu, 3600);
}

static void do_start(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	me->set("cp/start",1);
}

BANKOWNER_END