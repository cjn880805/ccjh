//gaoshengtai.h
//Lanwood 2000-01-05

NPC_BEGIN(CNdali_gaoshengtai);

virtual void create()
{
	set_name("高升平", "gao shengping");
	set("title",  "大理善阐侯" );
	set("long", "大理国侯爷，这是位宽袍大袖的中年男子，三缕长髯，形貌高雅。");
	set("gender", "男性");
	set("age", 33);
	set("icon", young_man5);

	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	
	set("max_hp", 4500);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 80);
	set("combat_exp", 800000);
	set("score", 150000);

	set_skill("force", 110);
	set_skill("dodge", 110);
	set_skill("parry", 100);
	set_skill("cuff", 110);
	set_skill("strike", 110);
	set_skill("sword", 120);
	set_skill("staff", 120);
	set_skill("kurong_changong", 110);
	set_skill("tiannan_step", 120);
	set_skill("jinyu_quan", 110);
	set_skill("wuluo_zhang", 110);
	set_skill("duanjia_sword", 110);
	set_skill("literate", 60);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("sword", "duanjia_sword");
	map_skill("staff", "duanjia_sword");
	map_skill("parry", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

	set_inquiry("指点武功", ask_me);
	
	carry_object("magcloth")->wear();
	carry_object("marz")->wear();
	carry_object("cleansword")->wield();
	add_money(2000);

	create_family("大理段家",19,"武将");
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];
	char oldtitle[40];
	
	strncpy(oldtitle, me->querystr("title"), 40)[39] = 0;

	if (me->query_skill("kurong_changong",1) < 30 )
	{
		say("你的本门内功心法太低了，还是努努力先提高一下吧。", me);
		SendMenu(me);
		return;
	}

	if (me->query("repute") < 10000  )
	{
		say("我大理段氏向来行侠仗义，您请回吧！", me);
		SendMenu(me);
		return;
	}

	if (strstr(oldtitle, "大理镇南王府")) 
	{
		say("很好，既然入我门来就得终身为奴供我驱使。");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", oldtitle);
		me->UpdateMe();
	}
	else
	{
		say("你是何人，如此大胆，假冒我府中厮仆！");
		SendMenu(me);
		return;
	}
}

static char * ask_me(CNpc * me, CChar * who)
{
	const char * oldtitle;
	
	if (who->query_skill("kurong_changong",1) < 80)
		return "你的武功恐怕是不能胜任武将的薪俸，再练几年功夫吧。";
	
	oldtitle = who->querystr("title");
	if (strstr(oldtitle, "大理镇南王府卫士"))
	{
		who->set_temp("fight_ok", 1);
		me->say("好，既然如此想切磋，那就看你的本事如何了。", who);
		me->AddMenuItem("开始比试", "$0bishi $1", who);
		me->AddMenuItem("放弃比试", "", who);
		me->SendMenu(who);
		return 0;
	}
	
	return "只有卫士才能升武将。";		
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "武将比试会");
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
		say("你已经可以胜任大理武将 !");
		
		upgrade_title(winner, "大理镇南王府武将");
		return;
	}

	say("看来你还得多加练习，方能在大理段家诸多弟子中出人头地 !");
}

void upgrade_title(CChar * me, char * arg)
{
	me->set("title", arg);
	me->UpdateMe();
}

NPC_END;
