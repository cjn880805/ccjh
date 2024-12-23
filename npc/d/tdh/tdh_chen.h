// chen.c 陈近南

NPC_BEGIN(CNtdh_chen);

virtual void create()
{
	set_name("陈近南", "chen jinnan");
	set("title", "天地会总舵主");
	set("nickname", "英雄无敌");
	set("long", "这是一个文士打扮的中年书生，神色和蔼。他就是天下闻名的天地会总舵主陈近南，据说十八般武艺，样样精通。偶尔向这边看过来，顿觉他目光如电，英气逼人。");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("per",27);
	
	set("max_hp", 13000);
	set("max_mp", 10000);
	set("hp", 13000);
	set("mp", 10000);
	set("combat_exp", 2000000);
	set("score", 500000);
	
	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 200);
	set_skill("yunlong-xinfa", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("wuhu-duanmendao", 200);
	set_skill("yunlong-jian", 200);
	set_skill("yunlong-shenfa", 200);
	set_skill("yunlong-bian", 200);
	set_skill("yunlong-shou", 200);
	set_skill("yunlong-zhua", 200);
	
	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu_duanmendao");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");
	
	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	create_family("云龙门",1, "开山祖师");
	set("book_count", 1);

	set_inquiry("天地会","只要是英雄好汉，都可以入我天地会(join tiandihui)。");
	set_inquiry("入会","只要入我天地会，可以向各位好手学武艺。");
	set_inquiry("反清复明","去棺材店和回春堂仔细瞧瞧吧！");
	set_inquiry("暗号","敲三下！");
	set_inquiry("切口","敲三下！");
	set_inquiry("江湖威望",ask_weiwang);
	set_inquiry("云龙剑谱",ask_me);
	set_inquiry("退会",ask_tuihui);

	set("env/wimpy", 60);
	carry_object("jinduan")->wear();
	carry_object("yaodai")->wear();
	carry_object("changjian")->wield();
	carry_object("hlbian");
	carry_object("gangdao");

}

static char * ask_me(CNpc * npc , CChar * player)
{
	static char msg[255];

	if(DIFFERSTR(player->querystr("family/family_name"), "云龙门"))
		return snprintf(msg,255,"%s与本派素无来往，不知此话从何谈起？",player->name());

	if (npc->query("book_count") < 1)
		return "你来晚了，本派的云龙真经不在此处。";

	npc->add("book_count", -1);
	CContainer * ob = load_item("yljianpu");
	ob->move(player);
	return "好吧，这本「云龙剑谱」你拿回去好好钻研。";
}


virtual void attempt_apprentice(CChar * ob)
{
	if (ob->query_skill("yunlong_shengong", 1) < 50)
	{
		message_vision("我云龙神功乃内家武功，最重视内功心法。\n$N是否还应该在云龙神功上多下点功夫？",ob);
		return;
	}
	if (ob->query("weiwang") <60)
	{
		message_vision("我云龙门武功天下无敌，凡入我门，\n必闯荡江湖，行侠仗义，为天下苍生谋福利。\n$N是否应该先出去闯一闯，做几件惊天动地的大事？",ob);
		return;
	}
	if (ob->query("repute") >0 &&ob->query("repute") < 5000)
	{
		message_vision("学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。\n在德行方面，$N是否还做得不够？",ob);
		return ;
	}
	if(ob->query("weiwang")<80)
	{
		if(ob->query("repute")<0)
			message_vision("$N虽然是邪派中人，但也还做了些好事。",ob);

		message_vision("\n我天地会所作所为，无一不是前人所未行之事。",ob);
		message_vision("万事开创在我，骇人听闻，物议沸然，又何足论？",ob);
		message_vision("今天就收了$N吧！！",ob);
		message_vision("想不到我一身惊人艺业，今日终于有了传人，哈哈哈哈！！！！\n",ob);

		message_vision("$HIC$N的江湖威望提高了！\n",ob);
		ob->set("weiwang",80);
	}
/*
	if(DIFFERSTR(ob->querystr("class"), "fighter"))
		ob->set("class","fighter");
*/
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	static char msg[255];
	npc->say(snprintf(msg,255,"你现在的江湖威望是 %d 。",player->query("weiwang")),player);
	npc->say("陈近南说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n",player);
	npc->say("陈近南又说：杀某些坏人或救某些好人可以提高江湖威望。\n",player);
	npc->SendMenu(player);
	return "";
}

static char * ask_tuihui(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("party/party_name"), "天地会"))
	{
		npc->say("陈近南笑了笑，对你说道：你还没加入我天地会呢，退什么退？", player);
		npc->SendMenu(player);
		return "";
	}
	if(EQUALSTR(player->querystr("family/family_name"), "云龙门"))
	{
		npc->say("陈近南板着脸对你说道：你已经是我云龙门弟子，如何能退会？", player);
		npc->SendMenu(player);
		return "";
	}
	npc->command("sigh ");
	npc->command("say 反清复明，就要坚贞志士，你去吧! ");
	player->del("party");
	return "";
}                                           

NPC_END;
