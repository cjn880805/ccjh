// pub_clothboss.h 老板娘
// code by Fisho

VENDOR_BEGIN(CNpub_clothboss);

virtual void create()
{
	set_name("老板娘","pub_clothboss");

	set("icon", young_woman12);
	set("title", "风情万种");
	set("gender", "女性" );
	set("age", 22);
	set("combat_exp", 6000);
	set("str", 100);
	set("dex", 100);
	set("con", 100);
	set("int", 100);
	set("per", 40);
	set_skill("sword", 100);
	set_skill("dodge", 600);
    set_skill("doggiesteps", 400);
	map_skill("dodge","doggiesteps");

	set("shen_type", 1);
	set("attitude", "friendly");
	add_money(5000);
	carry_object("dress")->Do_Action(DO_WIELD);
	carry_object("abab_sword")->Do_Action(DO_WIELD);

	carry_good("rover", 10);
	carry_good("female3_cloth", 10);
	carry_good("female4_cloth", 10);
	carry_good("female5_cloth", 10);
	carry_good("female6_cloth", 10);
	carry_good("female7_cloth", 10);
	carry_good("male4_cloth", 10);
	carry_good("male5_cloth", 10);
	carry_good("male7_cloth", 10);
	carry_good("male8_cloth", 10);
	carry_good("yan_dress", 10);
	carry_good("zi_dress", 10);
	carry_good("xiu_scarf", 10);
	carry_good("xiu_cloth", 10);
	carry_good("sha_dress", 10);
	carry_good("scarf", 10);
	carry_good("qi_dress", 10);
	carry_good("moon_dress", 10);
	carry_good("pink_dress", 10);
	carry_good("marry_dress", 10);
	carry_good("liu_dress", 10);
	carry_good("jade_belt", 10);
	carry_good("hat", 10);
	carry_good("gui_dress", 10);
	carry_good("guazi", 10);
	carry_good("fu_cloth", 10);
	carry_good("doupeng2", 10);
	carry_good("cuiyu", 10);
	carry_good("color_dress", 10);
	carry_good("cheng_cloth", 10);
	carry_good("belt", 10);
	carry_good("shuikao", 10);
	carry_good("zhanyi", 10);
	set("no_talk",1);


//	set_inquiry("问路", "????", "请问路怎么走？");
//	set_inquiry("名字", "别问我的名字。");

};
//与NPC的交互系统，主要用来做一些简单的任务
virtual int do_talk(CChar * me, char * ask = NULL)
{
	int mask;
	if(! me || ! ask) return 0;
	mask = me->query_temp("mark/老板娘");
	//now we handle the player's answer
	if (EQUALSTR(me->querystr("gender"), "女性"))
	{
		tell_object(me,"随便挑吧，姑娘，我这里有很多漂亮的衣服鞋帽。");
		return 0;
	}
	if(mask == 1)	//has questioned
	{
		if(strcmp(ask, "ihear") == 0)	//player selected the answer 1
		{
			say("今晚来陪我好吗……帅哥（^_^）。", me);
			AddMenuItem("你给我什么好处？", "do3", me);
			AddMenuItem("我太忙，找别人帮你吧。", "", me);
			//set mark
			me->set_temp("mark/老板娘", 2);
			SendMenu(me);
			return 1;
		}
	}

	if(mask == 2)	//has questioned 2 times
	{
		if(strcmp(ask, "do3") == 0)	
		{				
			say("那就50金，怎么样？", me);
			AddMenuItem("好吧，看在金的份上……", "do50", me);
			AddMenuItem("去去去，那么点钱谁跟你干！", "", me);
			//set mark
			me->set_temp("mark/老板娘", 3);
			SendMenu(me);
			return 1;
		}
	}

	//if mask > 100, it stand for the price of discuss
	if(mask >= 3)
	{
		if(mask == 3 && strcmp(ask, "do50") == 0)
		{
			say("再来一次，好吗……", me);
			AddMenuItem("好呀，不过你先付点补身费吧！", "yes", me);
			AddMenuItem("下次再说吧！", "", me);
			me->set_temp("mark/老板娘", 50);
			me->add("mp", -10);
			me->add("hp",-100);
			SendMenu(me);
		//	me->UpdateMe ();
			return 1;
		}
		if(strcmp(ask, "yes") == 0)
		{
			if ( me->query("hp")<1)
			{
				char msg[255];
				snprintf(msg, 255, "%s由于操劳过度，终于精尽人亡了。", me->name());
				MessageVision(me, "chat", msg);
				return 1;
			}
			me->add("combat_exp", 1);
			char msg[255];
			snprintf(msg, 255, "浪漫过后，一个傻仔%s涨了 5 点经验，同时得了%d金。真是傻人有傻福。", me->name(), mask);
			MessageVision(me, "chat", msg);
			CMoney::Pay_Player(me, mask);
			me->set_temp("mark/老板娘", 0l);
			return 1;
		}
	}

//	if(mask == -1)
//	{
		//default
		//set the npc questions
		say("唉……自从我相公走了之后，我晚上睡觉好害怕呀……你晚上有没有空？", me);
		//set my answer 1
		AddMenuItem("嘿，晚上我除了睡觉，其他事一律不干。", "ihear", me);
		//set my answer 2
		AddMenuItem("不好意思，我没空。", "", me);
		//set mark
		me->set_temp("mark/老板娘", 1);
		//must have this state, to send the questions to client
		SendMenu(me);
		return 1;
//	}
//	me->set_temp("mark/老板娘", -1);
//	return 1;
//	return CNpc::do_talk(me, ask);
}

VENDOR_END;
