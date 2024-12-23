//chen.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNyunlong_chen);

virtual void create()
{
	   set_name("陈远北", "chen yuan bei");
	set("nickname", "英雄无敌" );
	set("long","这是一个文士打扮的中年书生，神色和蔼。他就是天下闻名的天地会总舵主陈远北,据说十八般武艺，样样精通。偶尔向这边看过来，顿觉他目光如电，英气逼人。");
	set("gender", "男性");
	set("age", 21);
	set("icon",young_man5);
	
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_hp", 15000);
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_force", 100);
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
	set_skill("houquan", 150);
	set_skill("yunlong_xinfa", 200);
	set_skill("yunlong_shengong", 200);
	set_skill("wuhuduanmendao", 150);
	set_skill("yunlong_jian", 200);

	set_skill("yunlong_shenfa", 150);
	set_skill("yunlong_bian", 150);
	set_skill("yunlong_shou", 150);
	set_skill("yunlong_zhua", 150);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhuduanmendao");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	create_family("云龙门",1, "开山祖师");
	set("class", "yunlong_xinfa");
	set("book_count", 1);

    set_inquiry("天地会","只要是英雄好汉，都可以入我天地会");
	set_inquiry("入会","只要入我天地会，可以向各位好手学武艺。");
    set_inquiry("反清复明","去棺材店和回春堂仔细瞧瞧吧！");
    set_inquiry("暗号","敲三下！");
    set_inquiry("威望",ask_weiwang);
	set_inquiry("云龙剑谱",ask_me);

	set("env/wimpy", 60);
	set("chat_chance_combat", 70);  

	carry_object("jinduan")->wear();
	carry_object("yaodai")->wear();
	carry_object("changjian")->wield();
	carry_object("heilongbian");
	carry_object("gangdao");
}


virtual char * chat_msg_combat()
{
	static char msg[255];
	CContainer * changjian = PresentName("changjian", IS_ITEM);
	CContainer * changbian = PresentName("heilongbian", IS_ITEM);
	CContainer * gangdao = PresentName("gangdao", IS_ITEM);

	switch(random(34))
	{
	case 0:
		g_Channel.do_emote(this, 0, "smile", 0);
		break;
	case 1:
		g_Channel.do_emote(this, 0, "haha", 0);
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		if(query_weapon() == changjian && changjian)
			command(snprintf(msg, 40, "unwield %ld", changjian->object_id()));
		break;
	case 11:
		if(! query_weapon() && changjian)
			command(snprintf(msg, 40, "wield %ld", changjian->object_id()));
		break;
	
	case 12:
	case 13:
	case 14:
		perform_action("sword xian",1);
		break;
	case 15:
	case 16:
		perform_action("whip chan",1);
		break ;
	case 17:
	case 18:
		perform_action("force recover",0);
		break ;
	case 19:
	case 20:
	case 21:
	case 22:
		if(! query_weapon() && changbian)
			command(snprintf(msg, 40, "wield %ld", changbian->object_id()));
		break ;
	case 23:
	case 24:
	case 25:
	case 26:
		if(query_weapon() == changbian && changbian)
			command(snprintf(msg, 40, "unwield %ld", changbian->object_id()));
		break ;
	case 27:
		return "陈远北说道：你我无冤无仇，何必如此?";

	case 28:
	case 29:
	case 30:
	case 31:
		if(query_weapon() == gangdao && gangdao)
			command(snprintf(msg, 40, "unwield %ld", gangdao->object_id()));
		break;
	case 32:
		if(! query_weapon() && gangdao)
			command(snprintf(msg, 40, "wield %ld", gangdao->object_id()));
		break;
	case 33:
		return "陈远北摇头叹道：螳臂当车，不自量力。唉，你这又是何苦呢";		
	}

	return 0;
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	char msg[255];

    npc->say(snprintf(msg,255,"%s你现在的江湖威望是……", query_respect(player),player->query("weiwang")),player);
	npc->say("陈远北说道：很久以前我养了一只狗，据说它后来变得很厉害。",player);
	npc->say("那只狗曾经改变了江湖的命运……",player);
	npc->say("陈远北又说：它现在也不知道去了哪里。",player);
	npc->SendMenu(player);
	return 0;
}

static char * ask_me(CNpc * npc , CChar * player)
{
		CContainer * ob;

        if (DIFFERSTR(player->querystr("family/family_name"), "云龙门"))
                return "你与本派素无来往，不知此话从何谈起？";

        if (npc->query("book_count") < 1)
                return "你来晚了，本派的云龙真经不在此处。";

        npc->add("book_count", -1);
        ob = load_item("yljing2");
        ob->move(player);

        return "好吧，这本「云龙剑谱」你拿回去好好钻研。";
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (player->query_skill("yunlong_shengong", 1) < 50)
	{
		say(" 我云龙神功乃内家武功，最重视内功心法。",player); 
		say("你还应该在云龙神功上多下点功夫？",player);
		SendMenu(player);
		return;
	}
	if (player->query("weiwang") <60)
	{
		say("我云龙门武功天下无敌，凡入我门，必闯荡江湖，行侠仗义，为天下苍生谋福利。"); 
		say("你应该先出去闯一闯，做几件惊天动地的大事？",player);
		SendMenu(player);
		return ;
	}
	if (player->query("repute") >0&&player->query("repute") < 5000) 
	{
		say("学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。",player);
		say("在德行方面，你做得还不够！",player);
		SendMenu(player);
		return ;
	}
	if(player->query("weiwang")>80)
	{
		if(player->query("repute")<0) say( "你虽然是邪派中人，但也还做了些好事。",player);

		say("我天地会所作所为，无一不是前人所未行之事。",player);
		say("万事开创在我，骇人听闻，物议沸然，又何足论？",player);
		say("今天就收了你吧！！",player);
		say("想不到我一身艺业，今日终于有了传人，哈哈哈哈……咳咳！！！！",player);
		message_vision("$N的江湖威望提高了！",player);
		SendMenu(player);
		player->set("weiwang",80);
	}

	command(snprintf(msg,255,"recruit %ld",player->object_id()) );

	if(DIFFERSTR(player->querystr("class"), "fighter"))
		player->set("class","fighter");

}
/*
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="tiandihui" )
	return notify_fail("你要加入什么组织？\n"); 
   if (ob->query("weiwang")<20)
        {
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	message_vision(HIC "真玄对$N摇了摇头说：你的江湖威望值太低。\n" NOR,this_player());
  	return 1;
  	}
    if(ob->query("weiwang")<50)
    {
    ob->set("weiwang",50);
    message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
    return 1;
    }
   else	return notify_fail("你已经加入天地会了！\n"); 
}


*/


NPC_END;