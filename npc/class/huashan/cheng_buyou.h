//cheng_buyou.h
//Lanwood 2000-01-08

NPC_BEGIN(CNhuashan_cheng_buyou);

virtual void create()
{
		set_name("成不喜", "cheng buxi");
        set("gender", "男性");
        set("class", "swordsman");
        set("title", "华山剑宗第十三代弟子");
        set("age", 41);
        set("long",  "一个白净面皮的矮子，可也不能小看他。");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set("icon",young_man1);

        set("mp", 4000);
        set("max_mp", 2400);
        set("mp_factor", 30);
        set("max_hp",6000);
        
        set("combat_exp", 1000000);
        set("repute", -200000);
        set("apprentice_available", 3);

        set("chat_chance_combat", 80);
        
        set_skill("unarmed", 80);
        set_skill("sword", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("literate", 100);
        set_skill("huashan_sword", 150);
        set_skill("zixia_shengong", 150);
        set_skill("huashan_ken", 80);
        set_skill("huashan_zhangfa", 80);
        set_skill("huashan_shenfa", 120);

        map_skill("sword", "huashan_sword");
        map_skill("parry", "huashan_sword");
        map_skill("force", "zixia_shengong");
        map_skill("unarmed", "huashan_zhangfa");
        map_skill("dodge", "huashan_shenfa");

        create_family("华山派剑宗", 13, "弟子");
        
        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
};

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
			perform_action("sword feilong", 1);
			break;
	case 1:
			perform_action("force powerup", 0);
			break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	say("老夫从不收徒，你找我封师兄好了。", me);
	SendMenu(me);
}

virtual void init(CChar * me)
{
        CNpc::init(me);

		if(userp(me) && ! is_fighting())
        {
                remove_call_out(do_greeting);
                call_out(do_greeting, 10, me->object_id());
        }
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if(! who) return;

    if(DIFFERSTR(who->querystr("family/master_id"), "yue buqun"))
          me->say(snprintf(msg, 255, "这位%s，来投我剑宗吧。", query_respect(who)));
    else
    {
        message_vision("成不喜一见$N就大怒：我最讨厌伪君子的徒弟了。", who);
        me->kill_ob(who);
    }

    return;
}

NPC_END;
