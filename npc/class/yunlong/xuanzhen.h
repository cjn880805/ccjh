//xuanzhen.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNyunlong_xuanzhen);

virtual void create()
{
	   set_name("真玄道长", "xuan zhen");
	set("gender", "男性");
	set("long", "这位沉默寡言的道人，便是天地会青木堂护法。他是青木堂数一数二的好手，一柄长剑使得出神入化。");
	set("age", 55);
	set("icon",old_man2);

	set("int", 30);
	
	set("hp", 1500);
	set("max_hp", 4500);
	set("shen_type", 1);

	set("combat_exp", 200000);
	set("attitude", "friendly");

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("sword", 100);
	set_skill("whip", 80);
	set_skill("hand", 70);
	set_skill("claw", 70);
	set_skill("yunlong_shengong", 70);
	set_skill("yunlong_shenfa", 70);
	set_skill("yunlong_xinfa", 70);
	set_skill("yunlong_bian", 70);
	set_skill("yunlong_jian", 80);
	set_skill("yunlong_shou", 50);
	set_skill("yunlong_zhua", 50);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 60);

	map_skill("force", "yunlong_shengong");
	map_skill("dodge", "yunlong_shenfa");
	map_skill("parry", "yunlong_jian");
	map_skill("sword", "yunlong_jian");
	map_skill("hand", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("whip", "yunlong_bian");

	prepare_skill("hand", "yunlong_shou");
	prepare_skill("claw", "yunlong_zhua");
	create_family("云龙门",2, "弟子");
	set("class", "yunlong_xinfa");
	set("book_count", 1);

    set_inquiry("陈远北","江湖威望值达到70就可以拜总舵主为师。");
	set_inquiry("天地会","只要是英雄好汉，都可以入我天地会");
	set_inquiry("入会","只要入了我天地会，可以向会中各位好手学武功。");
    set_inquiry("反清复明","去药铺和棺材店仔细瞧瞧吧！");
    set_inquiry("威望",ask_weiwang);
	set_inquiry("云龙经",ask_me);

	set("chat_chance_combat", 50);  

	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	carry_object("changbian");
    add_money(3000);
}


virtual char * chat_msg_combat()
{
	static char msg[255];
	CContainer * changjian = PresentName("changjian", IS_ITEM);
	CContainer * changbian = PresentName("changbian", IS_ITEM);

	switch(random(28))
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
		return "真玄道长说道：你我无冤无仇，何必如此?";
		
	}

	return "";
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	char msg[255];

    npc->say(snprintf(msg,255,"%s你现在的江湖威望也许是 %ld", query_respect(player),player->query("weiwang")),player);
	npc->say("真玄说道：如果你在江湖上见到一只叫旺财的狗，千万不要欺负它",player);
	npc->say("它也许还活在人世吧",player);
	npc->say("真玄又说：很希望再见到它，但它如果重出江湖的话……",player);
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

        return "好吧，这本「云龙经」你拿回去好好钻研。";
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (player->query("weiwang") < 50)
	{
		say("我云龙门武功盖世，对弟子要求也是极高。",player);
		say("你若能先加入我天地会，或许我可以考虑收你为徒。",player);
		SendMenu(player);
		return;
	}

	say("好吧，既然你也是我辈中人，今天就收下你吧。",player);
	SendMenu(player);
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

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        if(ob->query("weiwang")>=50)
	switch( random(3)){
		case 1:
			say( "真玄笑道：这位" + RANK_D->query_respect(ob)
				+ "，我带你去香堂吧。\n");
			ob->move("/d/city2/dating");
			message_vision("$N来到了大厅。\n",ob);
			break;
		default:
			say( "真玄说道：这位" + RANK_D->query_respect(ob)
				+ "，请自便。\n");
			break;
	}
	else say( "真玄笑道：这位" + RANK_D->query_respect(ob)
				+ "，到这儿来干什么？\n");
 
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