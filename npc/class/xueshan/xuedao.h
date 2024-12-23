//xuedao.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_xuedao);

virtual void create()
{
	   set_name("血刀王", "xuedao wang");
	   set("long","这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第四代掌门。");
	   set("title","血刀门第四代掌门");
	   set("gender", "男性");
	   set("age", 85);
	   set("icon",old_man1);
	   set("foolid",162);     
	   set("attitude", "peaceful");
	   set("shen_type", -1);
	   set("str", 30);
	   set("int", 30);
	   set("con", 30);
	   set("dex", 30);
	   set("max_hp", 9000);
	   set("mp", 2000);
	   set("max_mp", 2000);
	   set("mp_force", 50);
	   set("combat_exp", 1800000);
	   set("score", 180000);
	   
	   set_skill("mizong_xinfa", 250);
	   set_skill("literate", 180);
	   set_skill("force", 280);
	   set_skill("parry", 280);
	   set_skill("blade", 400);
	   set_skill("sword", 220);
	   set_skill("dodge", 280);
	   set_skill("longxiang", 280);
	   set_skill("shenkong_xing", 280);
	   set_skill("hand", 280);
	   set_skill("dashou_yin", 280);
	   set_skill("mingwang_jian", 220);
	   set_skill("xue_dao", 300);
	   
	   map_skill("force", "longxiang");
	   map_skill("dodge", "shenkong_xing");
	   map_skill("hand", "dashou_yin");
	   map_skill("parry", "xue_dao");
	   map_skill("blade", "xue_dao");
	   map_skill("sword", "mingwang_jian");
	   set("chat_chance_combat", 20);  
	   
	   create_family("雪山寺", 4, "弟子");
	   set("class", "bonze");
	   
	   carry_object("y_jiasha")->wear();
	   carry_object("xblade")->wield();
	   
	   add_money(2000);
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
	if ((player->query("repute") )> -100000)
	{
		say(" 你是不是向着侠义道，连杀人都不会！",player);
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
	
	player->set("title","血刀门第五代弟子");
	player->UpdateMe();
}

NPC_END;