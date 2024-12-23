//song.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNwudang_song);

virtual void create()
{
	set_name("宋远桥","song yuanqiao");
	set("foolid",138);
	set("long","他就是张三丰的大弟子、武当七侠之首的宋远桥。身穿一件干干净净的灰色道袍。他已年过六十，身材瘦长，满脸红光。恬淡冲和，沉默寡言。");
	set("gender", "男性");
	set("age", 61);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 30);
	set("dex", 30);
	set("icon",old_man2);	
	
	set("max_hp", 18000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_force", 160);
	set("combat_exp", 2000000);
	set("score", 700000);

	set_skill("force", 250);
	set_skill("taiji_shengong", 250);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 220);
	set_skill("taiji_quan", 220);
	set_skill("parry", 220);
	set_skill("sword", 220);
	set_skill("taiji_jian", 220);
  	set_skill("taoism", 220);
	set_skill("literate", 150);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");

	create_family("武当派", 2, "弟子");

	set_inquiry("秘籍",ask_me);

	set("book_count", 1);

	set("chat_chance_combat", 40);

	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();

}

virtual char * char_msg_combat()
{
//	char msg[255];

	switch(random(2))
	{
	case 0:
		perform_action("unarmed zhen",1);
		break;
	case 1:
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
	say("好吧，我就收下你了。");
	say("希望你能好好用功,发扬我武当精神!");
	
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
	if(DIFFERSTR(player->querystr("class"), "taoist"))
		player->set("class", "taoist");
}

static char * ask_me(CNpc * npc , CChar * player)
{
	static char msg[255];
	CContainer * ob;

	if (DIFFERSTR(player->querystr("family/family_name"), "武当派"))
		return snprintf(msg,255,"%s与本派素无来往，不知此话从何谈起？",query_respect(player));
	if (npc->query("book_count") < 1)
		return "你来晚了，本派的内功心法不在此处。";

	npc->add("book_count", -1);
	ob = load_item("force_book");
	ob->move(player);
	
	return "好吧，这本「太极十三式」你拿回去好好钻研。";	
}

NPC_END;