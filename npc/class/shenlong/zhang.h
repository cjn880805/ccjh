//zhang.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

SHENLONG_BEGIN(CNshenlong_zhang);

virtual void create()
{
	set_name("张淡日","zhang danren");
	set("title", "神龙教黑龙使");
	set("long", "这是一个黑衣大汉, 脸色大变, 身子发颤, 似乎恐惧已极." );
	set("gender", "男性");
	set("icon",young_man1);	

	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("con", 30);
	set("max_hp", 9000);
    set("hp",3000);
	set("max_mp",1000);
    set("mp",1000);
	set("mp_factor", 50);
	set("combat_exp", 500000);
	set("score", 40000);
	set("shen_type", -1);

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);

    set_skill("force", 100);
    set_skill("dodge", 100);
    set_skill("unarmed", 100);
    set_skill("strike", 90);
    set_skill("parry", 100);
    set_skill("staff", 90);
    set_skill("sword", 90);
	set_skill("literate", 90);
	
	set_skill("shenlong_xinfa", 90);
	set_skill("yixingbu", 90);
	set_skill("shenlong_bashi", 90);
	set_skill("huagu_mianzhang", 90);
	set_skill("shedao_qigong", 90);
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
    map_skill("sword", "shedao_qigong");
	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");

	create_family("神龙教",2,"弟子");
	set("chat_chance_combat", 30);

    set_inquiry("入教",do_join);
	set_inquiry("洪安顺","教主脾气不好,要讨他欢心才好");
	set_inquiry("教主","教主脾气不好,要讨他欢心才好。");
	set_inquiry("口号","万年不老!永享仙福!寿与天齐!文武仁圣!");

    carry_object("duanjian")->wield();
	add_money(1000);
}

virtual char * greeting(CChar * ob)
{
	if (userp(ob))
	{
		if (ob->present("baihua"))
		{
			set("combat_exp",100000);
			set("qi",100);
			set("jing",100);
		}
	}
	return "";
}

static char * do_join(CNpc * npc , CChar * player)
{
	if (player->query("repute") > 0)
	{
		message_vision("$N对$n大怒道：还想入教？一看你就不是好人! ", npc, player);
		npc->kill_ob(player);
		return 0;
	}

	if(player->querymap("party") && DIFFERSTR(player->querystr("party/party_name"), "神龙教"))
	{
		message_vision("$N摇摇头，对$n说道：你已经加入其他帮会了，不能再入我神龙教。", npc, player);
		return 0;
	}

	if(player->query("age") > 24)
	{
		message_vision("$N无奈地摇摇头对$n说：教主近来只喜欢招收少年男女，你无本教无缘啊。", npc, player);
		return 0;
	}

	if( EQUALSTR(player->querystr("party/party_name"), "神龙教") )
	{
		message_vision("$N摇摇头，对$n说道：你已经是我神龙教的人了。",npc, player);
		return 0;
	}

	char new_rank[40];
	snprintf(new_rank, 40, "黑龙使属下");
	player->set("party/party_name","神龙教");
	player->set("party/rank", new_rank);
	player->set("party/level", 1);
	
	g_Channel.do_emote(npc,player, "smile", 0);
	message_vision("$N对$n说道：你就暂时在本使座下效力吧！",npc,player);
	return 0;
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (DIFFERSTR(player->querystr("party/party_name"), "神龙教"))
	{
		say("你不是本教教众, 想来找死啊!",player);
		SendMenu(player);
		return;
	}
	if (player->query("repute") > 0  ) 
	{
		say("我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！",player);
		SendMenu(player);
		return;
	}

	say("很好，很好。");
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
}

NPC_END;