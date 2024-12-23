//gao_laozhe.h
//Lanwood 2000-01-08

NPC_BEGIN(CNhuashan_gao_laozhe);

virtual void create()
{
	set_name("高人",  "gao laozhe");
	set("title", "华山第十二代长老");
	set("long", "他就是华山的长老高人。一副浑不在乎的模样，开朗乐天，万事不萦");
	set("gender", "男性");
	set("age", 65);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	set("icon",old_man2);
	
	set("hp", 5800);
	set("max_hp", 8000);
	
	set("mp", 2400);
	set("max_mp", 2400);
	set("mp_factor", 100);

	set("combat_exp", 1250000);
	set("score", 200000);

	set_skill("cuff", 180);
	set_skill("force", 170);
	set_skill("blade", 250);
	set_skill("sword", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("strike", 180);
	set_skill("zixia_shengong", 200);
	set_skill("poyu_quan", 160);
	set_skill("fanliangyi_dao", 250);
	set_skill("huashan_sword", 180);
	set_skill("hunyuan_zhang", 160);
	set_skill("feiyan_huixiang",160);
	set_skill("literate", 150);
	
	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "feiyan_huixiang");
	map_skill("parry", "fanliangyi_dao");
	map_skill("blade", "fanliangyi_dao");
	map_skill("sword", "huashan_sword");
	map_skill("strike", "hunyuan_zhang");

	create_family("华山派", 12, "弟子");

	set("chat_chance_combat", 30);
	
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();
};

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
			perform_action("blade sanshen", 1);
			break;
	case 1:
			perform_action("force recover", 0);
			break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

	if ( me->querymap("family") &&
			DIFFERSTR(me->querystr("family/family_name"), "华山派"))
	{
		say(snprintf(msg, 255, "%s既然已有名师指点，何必又来拜老朽呢？", query_respect(me)), me);
		SendMenu(me);
		return;
	}

    if ((me->query_skill("force",1) < 80) || (me->query_skill("zixia_shengong",1) < 80))
	{
		say(snprintf(msg, 255, "我看%s的紫霞神功还没学到家吧。", query_respect(me)), me);
		SendMenu(me);
		return;
	}
    
	if ((me->query_skill("dodge",1) < 80) || (me->query_skill("feiyan_huixiang",1) < 80))
	{
        say(snprintf(msg, 255, "我看%s的飞燕回翔还没学到家吧。", query_respect(me)), me);
		SendMenu(me);
		return;
	}

    if (me->query("repute") < 50000)
	{
		say("我华山派乃是堂堂名门正派，对弟子要求极严。", me);
		say(snprintf(msg, 255, "在德行方面，%s是否还做得不够？", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	say("好吧，我就收下你了。");
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "fighter");
	me->UpdateMe();
}

NPC_END;
