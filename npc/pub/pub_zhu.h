// pub_zhu.c 朱熹

// code by Fisho
// date:2000-12-17
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_zhu);

virtual void create()
{
	set_name("朱熹","zhu xi");

	set("icon", old_man2);
	set("long","朱先生被称为当世第一大文学家，肚子里的墨水比海还要深。");
	set("gender", "男性");
	set("age", 65);
	set("no_get", 1);
	set_skill("literate", 300);
	
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	
	set("combat_exp", 400000);
	set("shen_type", 1);
	set("chat_chance", 3);

	set_inquiry("学位",ask_degree);
	set_inquiry("买书",ask_buy);
	set_inquiry("书","唉!书到用时方恨少。");
	set_inquiry("借书" ,"借？你不还我到哪里找你？哼!");

	carry_good("lbook1",500);
	carry_good("lbook2",500);
	carry_good("lbook3",500);
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch (random(4))
	{
	case 0:
		return "朱熹说道：普天之下，莫非王土；率土之滨，莫非王臣。";
	case 1:
		return "朱熹说道：出家人，小过损益焉；无妄大过，未济咸困之。";
	case 2:
		return "朱熹说道：大学之道，在明明德。在亲民，在止于至善。 ";
	case 3:
		return "朱熹说道：格物致知，诚意正心，修身齐家，治国平天下。";
	}
	return "";
}

virtual int handle_action(char *comm, CChar *me, char *arg)
{
	if(is_fighting()) return 0;
	
	if(strcmp(comm, "buy") == 0 && me->query_skill("literate", 1) < 21)
		return notify_fail("朱熹不肯卖给你。");
	if(strcmp(comm, "sell") == 0)
		return notify_fail("朱熹笑道：这样东西还是您自己留着吧。");

	return CVendor::handle_action(comm, me, arg);
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if(DIFFERSTR(arg, "literate")) return 1;

	me->add_temp("mark/朱3", -1);
	if(! me->query_temp("mark/朱3"))
	{
		DownLoad(me);
		return 1;
	}
	
	return 0;
}

int recognize_apprentice(CChar * ob)
{
	if (! ob->query_temp("mark/朱3"))
		return 0;

	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 1000) 
	{
		message_vision("朱熹同意指点$N一些读书写字的问题。", who);
		who->add_temp("mark/朱3", ob->query("value") / 1000);
		DownLoad(who);
        if( who->query_skill("literate", 1) > 21)
		{
			say("你现在已有一定的文化知识,也可以自己读书深造了。", who);
			SendMenu(who);
			destruct(ob);
			return 1;
		}
	}
	destruct(ob);
	return 1;
}

static char * ask_buy(CNpc *ob,CChar *me)
{
	return "我这可有不少读书人必读的书哟!";
}

static char * ask_degree(CNpc *who,CChar *ob)
{
	int lv;
	static char msg[255];
	static char degree_desc[][12] = {
		{"文盲"      ,},
		{"童生"      ,},
		{"秀才"      ,},
		{"举人"      ,},
		{"解元"      ,},
		{"贡士"      ,},
		{"会元"      ,},
		{"进士"      ,},
		{"探花"      ,},
		{"榜眼"      ,},
		{"状元"      ,},
		{"翰林院士"  ,},
        {"翰林硕士"  ,},
		{"翰林博士"  ,},
		{"翰林院编修",},
		{"庶吉士"    ,},
		{"学士"      ,},
		{"内阁大学士",},
        {"内阁首辅"  ,},
		{"文学大宗师",},
		{"圣人"      ,},
	};
	
	lv = (ob->query_skill("literate") / 5);
	if(lv > 20) lv = 20;
	
	if (lv < 3) 
	{
		ob->set("degree",degree_desc[lv]);
		return snprintf(msg,255,"%s，你那点墨水也好意思问? 随便给你个学位就算了! ",ob->name() );
	}

	if (lv < 10) 
	{
		ob->set("degree",degree_desc[lv]);
		return snprintf(msg,255,"%s，呃，不错，有前途，很高兴授予学位给你，继续好好努力! ",ob->name() );
	}
	

	ob->set("degree",degree_desc[lv]);
	return snprintf(msg,255,"果然是长江后浪逐前浪啊，%s，我非常荣幸能有机会为你授学位! ",ob->name());
}

VENDOR_END;