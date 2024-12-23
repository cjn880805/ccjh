//baoxiang.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_baoxiang);

virtual void create()
{
	   set_name("宝相", "bao xiang");
	   set("long","一个极高极瘦的僧人，俩眼凶芒四射。此人在血刀老祖门下，最是心狠手辣。");
	   set("title","血刀门第五代弟子");
	   set("gender", "男性");
	   set("age", 35);
	   set("icon",young_man5);
	   
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
	   set("combat_exp", 250000);
	   set("score", 35000);
	   
	   set_skill("mizong_xinfa", 60);
	   set_skill("literate", 120);
	   set_skill("force", 120);
	   set_skill("parry", 120);
	   set_skill("blade", 120);
	   set_skill("dodge", 120);
	   set_skill("longxiang", 120);
	   set_skill("shenkong_xing", 120);
	   set_skill("hand", 120);
	   set_skill("dashou_yin", 120);
	   set_skill("xue_dao", 120);
	   
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
		say("女人是用来干的，不是用来教的。。",player);
		SendMenu(player);
		return;
	}
	
	if (player->query("repute")>0)
	{
		say(" 我正想找你们侠义道的晦气。");
		kill_ob(player);
		return;
	}
	
	if (player->query_skill("longxiang", 1) < 60) 
	{
		say(" 入我血刀门，修习龙象功法是首要的。",player);
		SendMenu(player);
		return;
	}
	
	g_Channel.do_emote(this,player, "nod", 0);
	
	command(snprintf(msg,40,"recruit %ld",player->object_id()) );
	
	player->set("title", "血刀门第六代弟子");
	player->UpdateMe();
}


NPC_END;