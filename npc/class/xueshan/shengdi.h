//shengdi.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_shengdi);

virtual void create()
{
	   set_name("胜帝", "sheng di");
	   set("long","这是一个身形魁梧的西藏僧人，神色冷漠。武功是同门中最高的一人。");
	   set("title","血刀门第五代弟子");
	   set("gender", "男性");
	   set("age", 35);
	   set("icon",young_man5);
	   set("foolid",163);        
	   set("attitude", "peaceful");
	   set("shen_type", -1);
	   set("str", 30);
	   set("int", 30);
	   set("con", 30);
	   set("dex", 30);
	   set("max_hp", 3000);
	   set("mp", 1000);
	   set("max_mp", 1000);
	   set("mp_force", 50);
	   set("combat_exp", 500000);
	   set("score", 50000);
	   
	   set_skill("mizong_xinfa", 90);
	   set_skill("literate", 180);
	   set_skill("force", 180);
	   set_skill("parry", 180);
	   set_skill("blade", 180);
	   set_skill("dodge", 180);
	   set_skill("longxiang", 180);
	   set_skill("shenkong_xing", 180);
	   set_skill("hand", 180);
	   set_skill("dashou_yin", 180);
	   set_skill("xue_dao", 180);
	   
	   map_skill("force", "longxiang");
	   map_skill("dodge", "shenkong_xing");
	   map_skill("hand", "dashou_yin");
	   map_skill("parry", "xue_dao");
	   map_skill("blade", "xue_dao");
	   
	   create_family("雪山寺", 5, "弟子");
	   set("class", "bonze");
	   
	   carry_object("y_jiasha")->wear();
	   carry_object("gangdao")->wield();
	   
	   add_money(1000);
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[40];
	
	if (DIFFERSTR(player->querystr("gender"), "男性"))
	{
		say(" 女人是用来干的，不是用来教的。",player);
		SendMenu(player);
		return;
	}
	if (DIFFERSTR(player->querystr("family/family_name"), "雪山寺"))
	{
		say("你既非本门弟子，还是请回吧！",player);
		SendMenu(player);
		return;
	}
	if ((player->query("repute")) > -50000)
	{
		say(" 看来我还要先教你如何心狠杀人。",player);
		SendMenu(player);
		return;
	}
	if (player->query_skill("longxiang", 1) < 60)
	{
		say("入我血刀门，修习龙象功法是首要的。",player);
		SendMenu(player);
		return;
	}
	
	g_Channel.do_emote(this,player, "haha", 0);
	g_Channel.do_emote(this,player, "nod", 0);
	
	command(snprintf(msg, 40,"recruit %ld",player->object_id()) );
	
	player->set("title","血刀门第六代弟子");
	player->UpdateMe();
}

NPC_END;