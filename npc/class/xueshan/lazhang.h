//lazhang.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_lazhang);

virtual void create()
{
	   set_name("拉章活佛", "lazhang huofo");
        set("long","拉章活佛是雪山寺有道的高僧，对佛法有精深的研究。 他身穿一件黄色袈裟，头带僧帽。慈眉善目，似乎手无缚鸡之力。"); 
        set("title","活佛"); 
        set("gender", "男性"); 
        set("age", 50);
	set("icon",young_man5);
	set("foolid",161);         
        set("attitude", "peaceful"); 
        set("shen_type", -1); 
        set("str", 30); 
        set("int", 30); 
        set("con", 30); 
        set("dex", 30); 
        set("max_hp", 12000); 
        set("mp", 4000); 
        set("max_mp", 4000); 
        set("mp_force", 50); 
        set("combat_exp", 1300000); 
        set("score", 100000); 
 
        set_skill("mizong_xinfa", 230); 
        set_skill("literate", 180); 
        set_skill("force", 180); 
        set_skill("xiaowuxiang", 180); 
        set_skill("dodge", 220); 
        set_skill("shenkong_xing", 210); 
        set_skill("unarmed", 240); 
        set_skill("yujiamu_quan", 240); 
        set_skill("parry", 220); 
        set_skill("sword", 180); 
        set_skill("mingwang_jian", 180); 
 
 
        map_skill("force", "xiaowuxiang"); 
        map_skill("dodge", "shenkong_xing"); 
        map_skill("unarmed", "yujiamu_quan"); 
        map_skill("parry", "riyue_lun"); 
        map_skill("sword", "mingwang_jian"); 
 
 
        create_family("雪山寺", 3, "活佛"); 
        set("class", "bonze"); 

        set_inquiry("剃度",ask_for_join);
 
        carry_object("y_jiasha")->wear(); 
        carry_object("sengmao")->wear(); 
 
        add_money(5000); 
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
				say(" 这位施主不如先跟哥伦布师傅学习？",player);
				SendMenu(player);
                return;
        }

        if (player->query_skill("mizong_xinfa", 1) < 60) 
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
        command(snprintf(msg, 40,"recruit %ld",player->object_id()) );

        player->set("title", "喇嘛");
		player->UpdateMe();
}

static char * ask_for_join(CNpc * npc , CChar * player)
{
	if(EQUALSTR(player->querystr("class"), "bonze") )
	{
		npc->say(" 阿弥陀佛！你我同是出家人，何故跟贫僧开这等玩笑？",player);
		npc->SendMenu(player);
		return 0;
	}

    if(DIFFERSTR(player->querystr("gender"), "男性") )
	{
		npc->say(" 施主若真心向佛，真是可喜可贺，可惜本寺只收男徒。",player);
		npc->SendMenu(player);
		return 0;
	}

    player->set_temp("pending/join_bonze", 1);
	npc->say(" 阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下受戒。",player);
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

	message_vision("$N双手合十，恭恭敬敬地跪了下来。$n说偈道：一微尘中入三昧，成就一切微尘定，而彼微尘亦不增，于一普现难思刹。”手掌提起，$N满头乌发尽数落下，头顶光秃秃地更无一根头发，便是用剃刀来剃亦无这等干净。",player, this);

	player->delete_temp("pending/join_bonze");
	player->set("class", "bonze");
    g_Channel.do_emote(this, player, "smile", 0);

	return 1;
}
NPC_END;