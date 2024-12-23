//daerba.h
//code by zwb
//1_15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_daerba);

virtual void create()
{
	   set_name("铁轮明王", "tielun mingwang");
        set("long","他是金轮明王座下的大弟子。深得明王的真传。身穿一件黄色袈裟，头带僧帽。");
        set("title", "活佛");
        set("gender", "男性");
        set("age", 45);
	set("icon",young_man2);
        
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_hp", 7500);
        set("mp", 3000);
        set("max_mp", 3000);
        set("mp_force", 50);
        set("combat_exp", 1000000);
        set("score", 150000);

        set_skill("mizong_xinfa", 80);
        set_skill("literate", 80);
        set_skill("force", 120);
        set_skill("xiaowuxiang", 120);
        set_skill("dodge", 100);
        set_skill("shenkong_xing", 100);
        set_skill("unarmed", 100);
        set_skill("yujiamu_quan", 80);
        set_skill("parry", 100);
        set_skill("sword", 70);
        set_skill("mingwang_jian", 60);
        set_skill("hammer", 120);
        set_skill("riyue_lun", 100 );


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong_xing");
        map_skill("unarmed", "yujiamu_quan");
        map_skill("parry", "riyue_lun");
        map_skill("sword", "mingwang_jian");
        map_skill("hammer", "riyue_lun");

        create_family("雪山寺", 3, "活佛");
        set("class", "bonze");

        carry_object("yinlun")->wield();
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

        if (player->query_skill("mizong_xinfa",1) < 40) 
		{
                say(" 入我雪山寺，修习密宗心法是首要的。",player);
                say(" 这位施主是否还应该多多钻研本门的心法？",player);
                SendMenu(player);
                return;
        }
		g_Channel.do_emote(this, player, "smile", 0);
		g_Channel.do_emote(this, player, "nod", 0);

		say("你就是我的弟子了！");

		command(snprintf(msg,40,"recruit %ld",player->object_id()) );

		player->set("title","大喇嘛");
		player->UpdateMe();
}

NPC_END;