//shanyong.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_shanyong);

virtual void create()
{
	   set_name("善永", "shan yong");
	   set("long","一个胖胖的西藏僧人，面带笑容，却常干笑里藏刀的事。");
	   set("title","血刀门第五代弟子");
	   set("gender", "男性");
	   set("age", 35);
	   set("icon",young_man4);
	   set("foolid",164);        
	   set("attitude", "peaceful");
	   set("shen_type", -1);
	   set("str", 30);
	   set("int", 30);
	   set("con", 30);
	   set("dex", 30);
	   set("max_hp", 2400);
	   set("mp", 800);
	   set("max_mp", 800);
	   set("mp_force", 50);
	   set("combat_exp", 200000);
	   set("score", 20000);
	   
	   set_skill("mizong_xinfa", 50);
	   set_skill("literate", 60);
	   set_skill("force", 60);
	   set_skill("parry", 60);
	   set_skill("blade", 60);
	   set_skill("dodge", 60);
	   set_skill("longxiang", 60);
	   set_skill("shenkong_xing", 60);
	   set_skill("hand", 60);
	   set_skill("dashou_yin", 60);
	   set_skill("xue_dao", 30);
	   
	   map_skill("force", "longxiang");
	   map_skill("dodge", "shenkong_xing");
	   map_skill("hand", "dashou_yin");
	   map_skill("parry", "xue_dao");
	   map_skill("blade", "xue_dao");
	   
	   create_family("雪山寺", 5, "弟子");
	   set("class", "bonze");
	   
	   carry_object("y_jiasha")->wear();
	   carry_object("gangdao")->wield();
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];
	
	if (DIFFERSTR(player->querystr("gender"), "男性"))
	{
		say(" 女人是用来干的，不是用来教的。。",player);
		SendMenu(player);
		return;
	}
	
	g_Channel.do_emote(this,player, "haha", 0);
	
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
	
	player->set("title","血刀门第六代弟子");
	player->UpdateMe();
}

NPC_END;