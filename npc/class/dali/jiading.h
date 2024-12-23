//jiading.h
//Lanwood 2000-01-05

NPC_BEGIN(CNdali_jiading);

virtual void create()
{
	set_name("家丁", "jia ding");
	set("title", "大理镇南王府");
	set("icon", young_man3);

	set("long", "他是大理国镇南王府的家丁。");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_hp", 900);
	set("mp", 200);
	set("max_mp", 200);
	set("mp_factor", 10);
	set("combat_exp", 10000);
	set("score", 2000);
	set("env/wimpy", 5);

    set_skill("force", 25);
    set_skill("dodge", 25);
    set_skill("parry", 25);
    set_skill("sword", 25);
    set_skill("cuff", 25);
	set_skill("kurong_changong", 25);
    set_skill("duanjia_sword", 25);
    set_skill("tiannan_step", 25);
    set_skill("jinyu_quan", 25);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("sword", "duanjia_sword");
	map_skill("cuff", "jinyu_quan");
	map_skill("parry", "jinyu_quan");

	set_inquiry("指点武功", ask_me );
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
	add_money(200);
};

static char * ask_me(CNpc * me, CChar * who)
{
	const char * oldtitle;
	
	if (who->query_skill("kurong_changong",1) < 30)
		return "你想当家臣，再练几年功夫去。";
	
	oldtitle = who->querystr("title");
//	tell_object(me,oldtitle);
	if (strstr(oldtitle, "大理镇南王府家丁")
		|| strstr(oldtitle, "大理镇南王府婢女"))
	{
		who->set_temp("fight_ok", 1);
		me->say("好，既然如此想切磋，那就看你的本事如何了。", who);
		me->AddMenuItem("开始比试", "$0bishi $1", who);
		me->AddMenuItem("放弃比试", "", who);
		me->SendMenu(who);
		return 0;
	}
	
	return "只有家丁或婢女才能升家臣。";		
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "家臣比试会");
		return 1;
	}

	return CNpc::handle_action(comm, me, arg);
}

//比试结束
virtual void is_defeated(CChar * winner, CChar * failer)
{
	if(failer == this)
	{
		if(! winner->query_temp("fight_ok")) return;

		winner->delete_temp("fight_ok");

		say("青出於蓝胜於蓝，不愧是大理段家的好弟子 ! 恭喜你了 !");
		say("你已经可以胜任大理家臣 !");
		
		upgrade_title(winner, "大理镇南王府家臣");
		return;
	}

	say("看来你还得多加练习，方能在大理段家诸多弟子中出人头地 !");
}

void upgrade_title(CChar * me, char * arg)
{
	me->set("title", arg);
	me->UpdateMe();
}

const char * clear_title(const char * arg)
{
	static char msg[80];

	strncpy(msg, arg, 80);

	replace_string(msg, "大理镇南王府家丁", "", 80);
	replace_string(msg, "大理镇南王府婢女", "", 80);
	
	return msg;
}

NPC_END;
