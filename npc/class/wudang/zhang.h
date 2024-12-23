//zhang.h
//code by zwb
//12-16
//inherit F_MASTER;

ZUSHI_BEGIN(CNwudang_zhang);

virtual void create()
{
	set_name("张三丰","zhang sanfeng");
	set("nickname", "邋遢真人" );
	set("long", "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。身穿一件污秽的灰色道袍，不修边幅。身材高大，年满百岁，满脸红光，须眉皆白。");
	set("gender", "男性");
	set("age", 100);
	set("foolid",127);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",taoist);	
	
	set("hp",30000);
	set("max_hp", 30000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_force", 300);
	set("combat_exp", 70000000);
	set("score", 1200000);

	set_skill("force", 320);
	set_skill("taiji_shengong", 320);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 400);
	set_skill("taiji_quan", 350);
	set_skill("parry", 300);
	set_skill("sword", 330);
	set_skill("taiji_jian", 330);
	set_skill("blade", 300);
	set_skill("taiji_dao", 300);
	set_skill("taoism", 350);
	set_skill("literate", 300);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");

	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");

	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("shen_type", 1);
	set("no_huan",1);
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}

	return 0;
}


virtual void attempt_apprentice(CChar * player)
{
	static char msg[255];

	if (player->query_skill("taiji_shengong",1) < 100)
	{
		say("我武当派乃内家武功，最重视内功心法。",player); 
		SendMenu(player);
		return;
	}
	if (player->query("repute") < 100000)
	{
		say("学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。",player);
		say(snprintf(msg,255," 在德行方面，%s是否还做得不够？",query_respect(player)),player);
		SendMenu(player);
		return;
	}
	if (player->query_int() < 30) 
	{
		say("我武当派武功全从道藏悟出。",player);
		say("要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。",player);
		say("你的悟性还大有潜力可挖，还是请回吧。",player);
		SendMenu(player);
		return;
	}
	say(" 哈哈哈哈！！！！");
	say("想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
	
	command(snprintf(msg,255,"recruit %ld",player->object_id()));
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "武当桃园小路8" ))
		return notify_fail("我这是在哪里？");
	char msg[255];
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s点了点头，收下了你送过来的包裹。",name(1)));
		tell_object(who, "\n$YEL你完成了替福威镖局押运暗镖的任务。");
		tell_object(who, snprintf(msg, 255, "$YEL获得了%d的经验奖励，江湖声望上升了%d点",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)压运暗镖成功，获得了%d的经验奖励，江湖声望上升了%d点！", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}
	return 0;
}
ZUSHI_END;