//guoshi.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_guoshi);

virtual void create()
{
	   set_name("贡唐仓国师", "gongtangcang guoshi");
	   set("long","贡唐仓国师是雪山寺中地位较高的喇嘛。身穿一件青色袈裟，头带僧帽。");
	   set("title", "大喇嘛" );
	   set("nickname", "国师" );
	   set("gender", "男性");
	   set("age", 40);
	   set("foolid",159);
	   set("icon",young_man6);
	   
	   set("attitude", "peaceful");
	   set("shen_type", -1);
	   set("str", 24);
	   set("int", 28);
	   set("con", 26);
	   set("dex", 25);
	   
	   set("max_hp", 4500);
	   set("mp", 1500);
	   set("max_mp", 1500);
	   set("mp_force", 20);
	   set("combat_exp", 500000);
	   set("score", 80000);
	   
	   set_skill("mizong_xinfa", 60);
	   set_skill("literate", 50);
	   set_skill("force", 100);
	   set_skill("xiaowuxiang", 100);
	   set_skill("dodge", 100);
	   set_skill("shenkong_xing", 80);
	   set_skill("parry", 70);
	   set_skill("staff", 80);
	   set_skill("xiangmo_chu", 80 );
	   set_skill("hammer",50);
	   set_skill("riyue_lun",40);
	   set_skill("unarmed", 90);
	   set_skill("yujiamu_quan", 80);
	   
	   
	   map_skill("force", "xiaowuxiang");
	   map_skill("dodge", "shenkong_xing");
	   map_skill("unarmed", "yujiamu_quan");
	   map_skill("parry", "xiangmo_chu");
	   map_skill("staff", "xiangmo_chu");
	   map_skill("hammer", "riyue_lun");
	   
	   create_family("雪山寺", 4, "大喇嘛");
	   set("class", "bonze");
	   
	   set_inquiry("剃度",ask_for_join);
	   //set_inquiry("法轮常转",do_say);
	   
	   carry_object("chanzhang")->wield();
	   carry_object("c_jiasha")->wear();
	   carry_object("sengmao")->wear();
	   
	   add_money(1000);
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[40];
	
	if (DIFFERSTR(player->querystr("gender"), "男性"))
	{
		say("修习密宗内功需要纯阳之体。",player);
		say("这位施主还是请回吧！",player);
		SendMenu(player);
		return;
	}
	
	if (DIFFERSTR(player->querystr("class"), "bonze"))
	{
		say(" 我佛门的清规戒律甚多。",player);
		player->set_temp("pending/join_bonze", 1);
		say("施主若真心皈依我佛，就请跪下受戒");
		SendMenu(player);
		return;
	}
	
	if (DIFFERSTR(player->querystr("family/family_name"), "雪山寺"))   
	{
		say(" 这位施主既非本寺弟子，还是请回吧！",player);
		say(" 这位施主不如先跟葛伦布师傅学习？",player);
		SendMenu(player);
		return;
	}
	
	if (player->query_skill("mizong_xinfa", 1) < 40) 
	{
		say(" 入我雪山寺，修习密宗心法是首要的。",player);
		say(" 你还应该多多钻研本门的心法",player);
		SendMenu(player);
		return;
	}
	
	g_Channel.do_emote(this,player, "smile", 0);
	g_Channel.do_emote(this,player, "nod", 0);
	
	say(" 就传你一些武功吧！",player);
	SendMenu(player);
	command(snprintf(msg,40,"recruit %ld",player->object_id()) );
	
	player->set("title", "喇嘛");
	player->UpdateMe();
}

static char * ask_for_join(CNpc * npc , CChar * player)
{
	if(EQUALSTR(player->querystr("class"), "bonze") )
		return "阿弥陀佛！你我同是出家人，何故跟贫僧开这等玩笑？";
	
    if(DIFFERSTR(player->querystr("gender"), "男性") )
        return "施主若真心向佛，真是可喜可贺，可惜本寺只收男徒。";
	
    player->set_temp("pending/join_bonze", 1);
	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下受戒。";
	
	npc->AddMenuItem("下跪", "kneel", player);
	npc->AddMenuItem("离开", "", player);
	npc->SendMenu(player);
	
	return "";
	
}

virtual int do_talk(CChar * player , char * ask=NULL)
{
	if(!ask) return 0;
	
	if(player->query_temp("pending/join_bonze"))
	{
		if(strcmp(ask, "kneel") == 0)
		{
			return do_kneel(player);
		}
		return 1;
	}
	return CNpc::do_talk(player, ask);
}

int do_kneel(CChar * player)
{
    if( !player->query_temp("pending/join_bonze") )
		return 0;
	
	message_vision("$N双手合十，恭恭敬敬地跪了下来。$n说偈道：一微尘中入三昧，成就一切微尘定，而彼微尘亦不增，于一普现难思刹。”手掌提起，$N满头乌发尽数落下，头顶光秃秃地更无一根头发，便是用剃刀来剃亦无这等干净。",player);
	
	player->delete_temp("pending/join_bonze");
	player->set("class", "bonze");
    g_Channel.do_emote(this, player, "smile", 0);
	
	return 1;
}

static char * do_say(CNpc * npc , CChar * player)
{
	player->move(load_room("雪山寺"));
	return "";
}
NPC_END;