// pub_sun.c
//code by Fisho
//date : 2000-12-14
//inherit F_BANKER;

BANKOWNER_BEGIN(CNpub_sun);

virtual void create()
{
	set_name("���Ƥ","sun bopi");

	set("icon", pawnshop_boss);
	set("title", "Ǯׯ�ϰ�");
	set("nickname", "һë����");
	set("gender", "����");
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
	//��ʦ�ֶ���������
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
		return "���Ƥ������˵�����������Ѿ����ϰ������ʷ���ڽ��Ͽ���˵�ǵ�һ�ҡ�";
	case 1:
		return "���ƤЦ��˵�����ڱ����Ǯ����Ϣ���͹������Ű�ɡ�";
	case 2:
		return "���Ƥ��������˵���������¿��販�ʻ��ֻҪ���б����·��۵Ĳ�Ʊ���л����ô�Ӵ����";
	}
	return "";
}

virtual void init(CChar *me)
{
	if(me->query_temp("lj/renwu110")||me->query_temp("zhang/������"))
	{
		tell_object(me,"\n$HIR���ƤЦ�����Ĵյ������ǰ����λ�͹٣��ǲ�������Ϊ����������ү�Ӳ�������Ǯ�������أ�\n");
	}
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("lj/renwu110")||me->query_temp("zhang/������"))
	{
		say("���Ƥ�����Ц��������ү��ƽ���������˸�������",me);
		say("������������˰�Ǯ�浽����������ү�ӵ����ϣ���������ү�����ﻹ��ϲ���ġ�",me);
		SendMenu(me);
		return 1;
	}
	CContainer * biaozhi = load_room("pk");
	char msg[255];
	if(! strlen(ask))
	{
		if(biaozhi->query("cp/random"))
		{
			AddMenuItem("�鿴��Ʊ���Ʒ", "name", me);
			if(!query("cp/number"))
				AddMenuItem("�鿴��Ʊ�����ʱ��", "time", me);
			else
				AddMenuItem("�鿴�񽱲�Ʊ����", "nember", me);
		}
		if(me->query("grant") > 95)
		{
			AddMenuItem("���ò�Ʊ���伸��", "$2random $1 $2", me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "name"))
	{
		say(snprintf(msg, 255,"���ڲ�Ʊ��Ľ�Ʒ�ǣ�%s",biaozhi->querystr("cp/jp_name")), me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "time"))
	{
		say("ÿ�ڲ�Ʊ��Ŀ���ʱ��̶�Ϊ��ÿ�����������ϰ˵�����", me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "nember") && query("cp/number"))
	{
		say(snprintf(msg, 255,"���ڲ�Ʊ��Ļ񽱺����ǣ�%d��", query("cp/number")),me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * bot;
	if(who->is_busy())
		return notify_fail("����һ��������û�����");

	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value") >=500000 )
	{	
		if(who->query_temp("lj/renwu110")&&!who->query("lj/���"))
		{
			tell_object(who,"���ƤЦ��˵������λ�͹٣����Ѿ���������˼����50������Ӵ���ˣ����������վݣ������պá�");
			bot = load_item("lbook1");
			bot->set("����",who->querystr("id"));
			bot->set_name("��������");
			bot->move(who);
			who->delete_temp("lj/renwu110");
			who->set_temp("lj/renwu1101",1);
			destruct(ob);
			return 1;
		}
		else if(who->query_temp("zhang/������"))
		{
			tell_object(who,"���ƤЦ��˵������λ�͹٣����Ѿ���������˼����50������Ӵ���ˣ����������վݣ������պá�");
			bot = load_item("lbook1");
			bot->set("����",who->querystr("id"));
			bot->set_name("��������");
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
			message_vision(snprintf(msg, 255,"$HIW$n�͸�$Nһ��$HIR%s$HIW��",biaozhi->querystr("cp/jp_name")),who,this);
			
			g_Channel.do_channel(this, NULL, "news", snprintf(msg, 255,	"$HIW%s(%s)�Ѿ��һ��� $HIR%d$HIW �ڽ�Ʒ $HIR%s$HIW ��"
							,who->name(),who->id(),query("cp/index"),biaozhi->querystr("cp/jp_name")));

			//���ý�Ʒ
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
		return notify_fail("����Ϊ�ա� ");
	int jv = atoi(arg);
	if(jv<0 ||jv>100)
		return notify_fail("���ü��ʷǷ���");

	static char baowu[51][20]={
		"38huoqiang","xuantiebishou","dagoubang","shenshe_staff","haoseshan","btzheng","taibaizao","zwsword",
		"lvzhuxiao","conglinjian","newyear","newyear1","century_war","tiancanbaojia","fannaomao","liaochengpao",
		"yinguozhu","bolanxie","zhangmenhuan","jinhuantoushi","ruanweijia","shajiezhi","zidiaopifeng","dulonglian",
		"yinmopao","diaojiandai","xiantianyu","poliquan","yanshuhua","fengyizhen","jinlianxie","kuihuaao","xuanwupao",
		"yunshenglv","zijianhun","qinjianhun","luoshenjin","linboxie","zueiyupao","hanyuzhi","lantiandai","cangzuihu",
		"rumengdai","baomingdan","huanchunwan","bing_1","bing_2","bing_3","bing_4","bing_5","bing_6",
	};

	CContainer * biaozhi = load_room("pk");
	tell_object(me,snprintf(msg,255,"���ò�Ʊ���伸��Ϊ��%d��������Խ�󣬵��伸��Խ�ͣ�", jv));
	biaozhi->set("cp/random",jv);
	//���ý�Ʒ
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
		g_Channel.do_channel(&g_Channel, NULL, "news", snprintf(msg, 255,	"$HIW�� $HIR%d$HIW �ڲ�Ʊ�н����� $HIR%d$HIW ���ý�Ʒ $HIR%s$HIW ��������ȡ�����ϡ�"
			,me->query("cp/index"),me->query("cp/number"),biaozhi->querystr("cp/jp_name")));
		
		//���ý�Ʒ
		static char baowu[51][20]={
			"38huoqiang","xuantiebishou","dagoubang","shenshe_staff","haoseshan","btzheng","taibaizao","zwsword",
				"lvzhuxiao","conglinjian","newyear","newyear1","century_war","tiancanbaojia","fannaomao","liaochengpao",
				"yinguozhu","bolanxie","zhangmenhuan","jinhuantoushi","ruanweijia","shajiezhi","zidiaopifeng","dulonglian",
				"yinmopao","diaojiandai","xiantianyu","poliquan","yanshuhua","fengyizhen","jinlianxie","kuihuaao","xuanwupao",
				"yunshenglv","zijianhun","qinjianhun","luoshenjin","linboxie","zueiyupao","hanyuzhi","lantiandai","cangzuihu",
				"rumengdai","baomingdan","huanchunwan","bing_1","bing_2","bing_3","bing_4","bing_5","bing_6",
		};
		//���Ƶ�����ļ��ʣ�����ֱ��������¼���һ��
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
		||me->query("jp"))//ÿ�������ϰ˵㿪��
	{
		int number=biaozhi->query("cp/number");
		if(number)
		{
			int jp=random(number)+1;
			me->set("cp/number",jp);
			me->set("cp/index",biaozhi->query("cp/index"));
			g_Channel.do_channel(&g_Channel, NULL, "news", snprintf(msg, 255,
				"\n\n$HIW�� $HIR%d$HIW �ڲ�Ʊ�Ѿ��������н�����Ϊ�� $HIR%d$HIW ����ӵ�д˲�Ʊ�������5���Ӻ�����ǰ��Ч��ƾ��Ʊȥ���ݾ۱�ի���ϰ�һ����ڽ�Ʒ $HIR%s$HIW ��\n\n"
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