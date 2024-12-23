//ma.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNyunlong_ma);

virtual void create()
{
	   set_name("马兴超", "ma chaoxing");
	set("nickname", "赛马超" );
	set("long","。");
	set("gender", "男性");
	set("age", 21);
	set("icon",young_man4);
	
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

    set_inquiry("陈远北","n江湖威望值达到80就可以拜总舵主为师。");
    set_inquiry("天地会","只要是英雄好汉，都可以入我天地会");
	set_inquiry("入会","只要入我天地会，可以向各位好手学武艺。");
    set_inquiry("旺财","我也很想见它");
    set_inquiry("暗号","多情自古空余恨");
    set_inquiry("威望",ask_weiwang);
	set_inquiry("云龙剑谱",ask_me);

	set("env/wimpy", 60);
	set("chat_chance_combat", 70);  

	carry_object("changbian")->wear();
	carry_object("changjian")->wield();
	carry_object("dadao")->wield();
	carry_object("cloth")->wield();
}


virtual char * chat_msg_combat()
{
	static char msg[255];
	CContainer * changjian = PresentName("changjian", IS_ITEM);
	CContainer * changbian = PresentName("changbian", IS_ITEM);
	CContainer * dadao = PresentName("dadao", IS_ITEM);

	switch(random(33))
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
		return "马兴超说道：你我无冤无仇，何必如此?";

	case 28:
	case 29:
	case 30:
	case 31:
		if(query_weapon() == dadao && dadao)
			command(snprintf(msg, 40, "unwield %ld", dadao->object_id()));
		break;
	case 32:
		if(! query_weapon() && dadao)
			command(snprintf(msg, 40, "wield %ld", dadao->object_id()));
		break;
	}

	return 0;
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	char msg[255];

    npc->say(snprintf(msg,255,"%s你现在的江湖威望是 %ld……我也不知道是不是这么多", query_respect(player),player->query("weiwang")),player);
	npc->say("马兴超说道：当初有一只狗，将江湖上的英雄都不放在眼里",player);
	npc->say("它就是太骄傲了……",player);
	npc->say("马兴超又说：千万不要学他。",player);
	npc->SendMenu(player);
	return "";
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

	if(EQUALSTR(player->querystr("gender"), "无性"))
	{
 		say("云龙门顶天立地，怎会收你这样的废人？！",player);
 		SendMenu(player);
		return;
	}
	say("好吧，既然你也是我辈中人，今天就收下你吧。",player);

	command(snprintf(msg,255,"recruit %ld",player->object_id()) );

	if( DIFFERSTR(player->querystr("class"), "fighter"))
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


virtual int recognize_apprentice(CChar * player)
{
    if (player->query("weiwang")<50)
    {
		message_vision("$N摇了摇头。威望太底我不教。",player);
		return 0;
    }
    return 1;
}



NPC_END;