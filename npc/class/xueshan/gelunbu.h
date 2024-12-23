//gelunbu.h
//code by zwb
//1_15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_gelunbu);

virtual void create()
{
	   set_name("哥伦布", "inlun fawang");
        set("long","哥伦布是雪山寺中护寺僧兵的头领。同时向本寺第子传授武功。身穿一件黑色袈裟，头带僧帽。");
        set("title", "喇嘛");
        set("nickname", "僧兵头领");
        set("gender", "男性");
        set("age", 30);
	set("icon",young_man4);
        
	set("foolid",157);        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_hp", 3000);
        set("mp", 1000);
        set("max_mp", 1000);
        set("mp_force", 20);
        set("combat_exp", 200000);
        set("score", 40000);

        set_skill("mizong_xinfa", 40);
        set_skill("literate", 30);
        set_skill("force", 80);
        set_skill("xiaowuxiang", 80);
        set_skill("dodge", 75);
        set_skill("shenkong_xing", 70);
        set_skill("parry", 60);
        set_skill("staff", 80);
        set_skill("xiangmo_chu", 70 );
        set_skill("hammer",50);
        set_skill("riyue_lun",40);
        set_skill("unarmed", 60);
        set_skill("yujiamu_quan", 60);



        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong_xing");
        map_skill("parry", "xiangmo_chu");
        map_skill("staff", "xiangmo_chu");
        map_skill("hammer","riyue_lun");
        map_skill("unarmed","yujiamu_quan");

        create_family("雪山寺", 5, "喇嘛");
        set("class", "bonze");

        carry_object("b_jiasha")->wear();
        carry_object("sengmao")->wear();
        carry_object("senggun")->wield();

        add_money(3000);
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


		say("我就传你一些武功吧！");	
		command(snprintf(msg,40,"recruit %ld",player->object_id()) );

        if(DIFFERSTR(player->querystr("class"), "bonze")) 
		{
                player->set("title","俗家弟子");
        }
        else 
		{
                player->set("title","小喇嘛");
        }

		player->UpdateMe();
}

NPC_END;