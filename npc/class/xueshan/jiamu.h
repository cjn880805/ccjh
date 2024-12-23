//jiamu.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_jiamu);

virtual void create()
{
	   set_name("嘉木活佛", "jiamu huofo");
        set("long","嘉木活佛是雪山寺有道的高僧，对佛法有精深的研究。他身穿一件黄色袈裟，头带僧帽。目光如电，似乎身怀绝技。");
        set("title","活佛");
        set("gender", "男性");
        set("age", 45);
	set("icon",young_man2);
	set("foolid",158);        
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_hp", 9000);
        set("mp", 3000);
        set("max_mp", 3000);
        set("mp_force", 50);
        set("combat_exp", 1200000);
        set("score", 100000);

        set_skill("mizong_xinfa", 220);
        set_skill("literate", 180);
        set_skill("force", 220);
        set_skill("xiaowuxiang", 210);
        set_skill("dodge", 230);
        set_skill("shenkong_xing", 220);
        set_skill("unarmed", 220);
        set_skill("yujiamu_quan", 180);
        set_skill("parry", 220);
        set_skill("sword", 230);
        set_skill("mingwang_jian", 240);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong_xing");
        map_skill("unarmed", "yujiamu_quan");
        map_skill("parry", "riyue_lun");
        map_skill("sword", "mingwang_jian");

        create_family("雪山寺", 3, "活佛");
        set("class", "bonze");

        carry_object("changjian")->wield();
        carry_object("y_jiasha")->wear();
        carry_object("sengmao")->wear();

        add_money(5000);
}

virtual void attempt_apprentice(CChar * player)
{
		char msg[40];

 		  if (DIFFERSTR(player->querystr("gender"), "男性"))
		  {
        		say(" 修习密宗内功需要纯阳之体。",player);
                say(" 这位施主还是请回吧！",player);
                SendMenu(player);
                return;
		  }

		  if (DIFFERSTR(player->querystr("class"), "bonze"))
		  {
        	    say(" 我佛门的清规戒律甚多。",player);
                say(" 这位施主还是请回吧！",player);
                SendMenu(player);
                return;
		  }

        if (DIFFERSTR(player->querystr("family/family_name"), "雪山寺"))
        {
                say(" 这位施主既非本寺弟子，还是请回吧！",player);
                SendMenu(player);
                return;
		}

        if (player->query_skill("mizong-xinfa", 1) < 60) 
		{
                say(" 入我雪山寺，修习密宗心法是首要的。",player);
                say(" 这位施主是否还应该多多钻研本门的心法？",player);
                SendMenu(player);
                return;
        }
		g_Channel.do_emote(this, player, "smile", 0);
		g_Channel.do_emote(this, player, "nod", 0);

		say("你就随我学习佛法吧！",player);
		SendMenu(player);

		command(snprintf(msg,40,"recruit %ld",player->object_id()) );

		player->set("title","大喇嘛");
		player->UpdateMe();
}

NPC_END;