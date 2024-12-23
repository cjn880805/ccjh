//duanwuwei.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNdali_duanwuwei);

virtual void create()
{
	set_name("段无味","duan wuwei");

	set("title",  "镇南王府管家" );
	set("long", "他是大理国镇南王府管家。");
	set("gender", "男性");
	set("age", 40);
	set("icon", young_man2);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_hp", 1800);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 10);
	set("combat_exp", 30000);
	set("score", 2000);

    set_skill("force", 45);
    set_skill("dodge", 45);
    set_skill("parry", 45);
    set_skill("cuff", 45);
	set_skill("kurong_changong", 45);
    set_skill("tiannan_step", 45);
    set_skill("jinyu_quan", 45);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("cuff", "jinyu_quan");
	map_skill("parry", "jinyu_quan");

	set_inquiry("比武", ask_me, "与段无味比武");

	carry_object("cloth")->wear();
	add_money(200);
};

static char * ask_me(CNpc * me, CChar * who)
{
	if (who->query_skill("kurong_changong",1) < 30)
		return "这哪里敢当。";
	
	who->set_temp("fight_ok", 1);
	me->say("好，既然如此想切磋，那就看你的本事如何了。", who);
	me->AddMenuItem("开始比试", "$0bishi $1", who);
	me->AddMenuItem("放弃比试", "", who);
	me->SendMenu(who);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "段无味的比试会");
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
		say("你的武功可以进一步深造了 !");
		
		winner->set_temp("have_fight1", 1);
		return;
	}

	say("看来你还得多加练习，方能在大理段家诸多弟子中出人头地 !");
}

NPC_END;
