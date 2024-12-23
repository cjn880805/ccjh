//guxu.h
//code by zwb
//1-15

NPC_BEGIN(CNwudang_guxu);

virtual void create()
{
	set_name("谷虚道长", "guxu daozhang");
	set("long","他就是俞莲舟的弟子谷虚道长。他今年四十岁，主管武当派的俗事。");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("foolid",123);	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("icon",taoist_with_sword);	
	
	set("max_hp", 4500);
	set("mp", 2500);
	set("max_mp", 2500);
	set("mp_force", 50);

	set("combat_exp", 700000);
	set("score", 85000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("taiji_shengong", 80);
	set_skill("taiji_jian", 80);
	set_skill("taiji_quan", 80);
	set_skill("tiyunzong", 80);
	set_skill("taoism", 80);
  	set_skill("literate", 60);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");

	create_family("武当派", 3, "弟子");
	set("class", "taoist");

	set_inquiry("道德经",ask_me);
                                 
	set("book_count", 1);

	carry_object("changjian")->wield();
	carry_object("greenrobe")->wear();
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];
	
	if (player->query("betrayer") > 1 && DIFFERSTR(player->querystr("family/family_name"), "武当派"))
	{ 
		say(" 你这个逆贼，岂能入我门下，贫道今天就先杀了你以示后人！",player);
		SendMenu(player);
		kill_ob(player);
		return ;  
	}

	if (player->query("repute") < 0) 
	{
		say("我武当乃是堂堂名门正派，对弟子要求极严。",player);
		say("你在德行方面做得还不够！",player);
		SendMenu(player);
		return;
	}
	say(" 好吧，贫道就收下你了。",player);
	SendMenu(player);
	command(snprintf(msg,255,"recruit %ld",player->object_id()));
}

static char * ask_me(CNpc * npc , CChar * player)
{
	CContainer * ob;
	if (DIFFERSTR(player->querystr("family/family_name"), "武当派"))	//PARTY CHANGED TO FAMILY LANWOOD 2001-05-25
		return "你与本派素无来往，不知此话从何谈起？";
    if (npc->query("book_count") < 1)
		return "你来晚了，本派的道德真经不在此处。";
    npc->add("book_count", -1);
    ob = load_item("daodejing_ii");
    ob->move(player);
    return "好吧，这本「道德经」你拿回去好好钻研。";
}


NPC_END;