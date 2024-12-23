//yue_wife.h
//Lanwood 2000-01-08

NPC_BEGIN(CNhuashan_yue_wife);

virtual void create()
{
	set_name("岳夫人",  "yue wife");
	set("nickname", "淑女剑");
	set("gender", "女性");
	set("class", "swordsman");
	set("age", 50);
	set("long",
		"岳夫人脸上好像很不开心的样子。");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("icon",old_woman);
	
	set("str", 26);
	set("per", 26);
	set("int", 24);
	set("con", 30);
	set("dex", 30);
	
	set("mp", 4000);
	set("max_mp", 2400);
	set("mp_factor", 30);
	
	set("max_hp",6000);
	
	set("combat_exp", 1000000);
	set("repute", 200000);
	
	set("apprentice_available", 3);
	set("chat_chance_combat", 20);
	
	set_skill("unarmed", 180);
	set_skill("sword", 230);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("dodge", 200);
	set_skill("literate", 160);
	
	set_skill("huashan_sword", 200);
	set_skill("yunv_swords", 220);
	set_skill("zixia_shengong", 180);
	set_skill("hunyuan_zhang", 180);
	set_skill("huashan_shenfa", 200);
	set_skill("zhengqijue", 180);
	
	map_skill("sword", "yunv_swords");
	map_skill("parry", "yunv_swords");
	map_skill("force", "zixia_shengong");
	map_skill("unarmed", "hunyuan_zhang");
	map_skill("dodge", "huashan_shenfa");
	
	create_family("华山派", 13, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	
	set_inquiry("华山剑谱", ask_swordbook);
//	set("have_book",1);

	remove_call_out(do_reset);
	call_out(do_reset, 900, 0);
};

virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
			perform_action("force powerup", 0);
			break;
	case 1:
			perform_action("force recover", 0);
			break;
	case 2:
			perform_action("sword wushuang", 1);
			break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

    if( query("apprentice_available") ) 
	{
        if( DIFFERSTR(me->querystr("gender"), "女性") )
		{
             say(snprintf(msg, 255, "这位%s你还是找我夫君去吧.", query_respect(me)), me);
		}
		else 
		{
			say("好，好，只要你用心学，他日必有成就。");
			command(snprintf(msg, 80, "recruit %ld", me->object_id()) );
			
            me->set("class", "swordsman");
			add("apprentice_availavble", -1);
			return;
        } 
	}
	else
        say("今天好累哟。", me);
      
	SendMenu(me);
}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->set("apprentice_available", 3);
}

static char * ask_swordbook(CNpc * me, CChar * who)
{
	CContainer * r = load_room("华山居室");

	if( DIFFERSTR(who->querystr("family/family_name"), "华山派"))
		return "对不起，本派秘笈恕不外借。";
	if( EQUALSTR(who->querystr("family/master_id"), "feng butan"))
		return "剑宗的人来找气宗学剑？哈哈哈哈。。。";
	if( r->query_temp("have_book") < 1)
		return "你来晚了，剑谱已经给别的弟子了。";

	int level = who->query_skill("sword",1);

	if(level <= 100)
		load_item("sword_book1")->move(who);
	else if(level > 100)
		load_item("sword_book2")->move(who);

        r->add_temp("have_book", -1);
	return "拿好了，慢慢读。";
}

NPC_END;
