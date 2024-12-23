//jiumozhi.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_jiumozhi);

virtual void create()
{
	   set_name("鸠摩香", "jiumo xiang");
        set("nickname",  "大轮明王" );
        set("long","他就是雪山寺的掌门，人称大轮明王的鸠摩香。他对佛法有精深的研究。身穿一件大红袈裟，头带僧帽。");
        set("title","雪山寺掌门");
        set("gender", "男性");
        set("age", 60);
	set("icon",young_man3);
	set("foolid",160);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 40);
        set("con", 35);
        set("dex", 30);
        set("max_hp", 15000);
        set("mp", 6000);
        set("max_mp", 6000);
        set("mp_force", 150);
        set("combat_exp", 3500000);
        set("score", 700000);

        set_skill("force", 350);
        set_skill("xiaowuxiang", 350);
        set_skill("dodge", 300);
        set_skill("shenkong_xing", 300);
        set_skill("unarmed", 300);
        set_skill("yujiamu_quan", 300);
        set_skill("parry", 300);
        set_skill("sword", 300);
        set_skill("mingwang_jian", 300);
        set_skill("mizong_xinfa", 300);
        set_skill("literate", 300);
        set_skill("staff", 300);
        set_skill("xiangmo_chu", 300 );
        set_skill("strike", 300 );
        set_skill("huoyan_dao", 300);



        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong_xing");
        map_skill("unarmed", "yujiamu_quan");
        map_skill("parry", "mingwang_jian");
        map_skill("sword", "mingwang_jian");
        map_skill("staff", "xiangmo_chu");
        map_skill("strike","huoyan_dao");

        create_family("雪山寺", 1, "掌门");
        set("class", "bonze");

        carry_object("changjian")->wield();
        carry_object("r_jiasha")->wear();
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

        if (player->query_skill("mizong_xinfa", 1) < 100) 
		{
                say(" 入我雪山寺，修习密宗心法是首要的。",player);
                say(" 这位施主是否还应该多多钻研本门的心法？",player);
                SendMenu(player);
                return;
        }

       command(snprintf(msg,40,"recruit %ld",player->object_id()) );

		player->set("title","法王");
		player->UpdateMe();
}

NPC_END;