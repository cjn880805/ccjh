//yu.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNwudang_yu);

virtual void create()
{
	set_name("俞莲舟","yu lianzhou");
	set("nickname", "武当二侠");
	set("long","他就是张三丰的二弟子俞莲舟。他今年五十岁，身材魁梧，气度凝重。虽在武当七侠中排名第二，功夫却是最精。");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("foolid",132);	set("str", 30);
	set("int", 30);
	set("con", 32);
	set("dex", 32);
	set("icon",taoist_with_sword);	
	
	set("max_hp", 15500);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_force", 150);
	set("combat_exp", 2500000);
	set("score", 400000);

	set_skill("force", 220);
	set_skill("taiji_shengong", 220);
	set_skill("dodge", 190);
	set_skill("tiyunzong", 190);
	set_skill("unarmed", 230);
	set_skill("taiji_quan", 230);
	set_skill("parry", 230);
	set_skill("sword", 250);
	set_skill("taiji_jian", 250);
	set_skill("taoism", 200);
	set_skill("literate", 150);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");

	create_family("武当派", 2, "弟子");

	set("chat_chance_combat", 40);

	carry_object("changjian")->wield();
	carry_object("white_robe")->wear();
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword chan",1);
		break;
	case 1:
		perform_action("sword lian",1);
		break;
	case 2:
		perform_action("sword sui",1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (player->query("repute") < 10000 )
	 {
		say("我武当乃是堂堂名门正派，对弟子要求极严。",player);
		say("你在德行方面是否还做得不够？",player);
		SendMenu(player);
		return;
	 }
	if (player->query_skill("taiji_shengong",1) < 80 ||player->query_skill("force",1) < 80 )
	{
		say("我武当派最注重内功心法你应该在内功上多下点功夫啊?",player);
		SendMenu(player);
		return;
	}
	if (player->query_skill("taoism",1) < 80)
	{
		say("习武是为了强身健体,一味的练武是不可取的!",player);
		say("我看你还需要在修身养性方面多锻炼锻炼,以提高你的道德心法",player);
		SendMenu(player);
		return;
	}
	say("好吧，我就收下你了。");
	say("希望你能好好用功,发扬我武当精神!");
	
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
	player->set("class", "taoist");
}

NPC_END;