//lingzhi.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_lingzhi);

virtual void create()
{
	   set_name("灵芝上人", "lingzhi shangren");
        set("long","灵芝上人是雪山寺中地位较高的喇嘛。身穿一件青色袈裟，头带僧帽。");
        //set("nickname","上人");
        set("title", "大喇嘛" );
        set("gender", "男性");
        set("age", 40);
	set("icon",young_man6);
	set("foolid",155);        
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 25);
        set("int", 27);
        set("con", 28);
        set("dex", 26);
        set("max_hp", 4500);
        set("mp", 1500);
        set("max_mp", 1500);
        set("mp_force", 20);
        set("combat_exp", 500000);
        set("score", 80000);

        set_skill("mizong_xinfa", 60);
        set_skill("literate", 60);
        set_skill("force", 100);
        set_skill("xiaowuxiang", 100);
        set_skill("dodge", 100);
        set_skill("shenkong_xing", 80);
        set_skill("parry", 80);
        set_skill("staff", 60);
        set_skill("xiangmo_chu", 80 );
        set_skill("hammer",50);
        set_skill("riyue_lun",50);
        set_skill("unarmed", 110);
        set_skill("yujiamu_quan", 100);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong_xing");
        map_skill("unarmed", "yujiamu_quan");
        map_skill("parry", "yujiamu_quan");
        map_skill("staff", "xiangmo_chu");
        map_skill("hammer", "riyue_lun");

        create_family("雪山寺", 4, "大喇嘛");
        set("class", "bonze");

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
                say(" 这位施主还是回吧！",player);
                SendMenu(player);
                return;
        }

        if (DIFFERSTR(player->querystr("family/family_name"), "雪山寺"))   
		{
                say(" 这位施主既非本寺弟子，还是请回吧！",player);
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
        command(snprintf(msg, 40,"recruit %ld",player->object_id()) );

        player->set("title", "喇嘛");
		player->UpdateMe();
}


NPC_END;