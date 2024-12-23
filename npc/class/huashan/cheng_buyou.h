//cheng_buyou.h
//Lanwood 2000-01-08

NPC_BEGIN(CNhuashan_cheng_buyou);

virtual void create()
{
		set_name("�ɲ�ϲ", "cheng buxi");
        set("gender", "����");
        set("class", "swordsman");
        set("title", "��ɽ���ڵ�ʮ��������");
        set("age", 41);
        set("long",  "һ���׾���Ƥ�İ��ӣ���Ҳ����С������");
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

        create_family("��ɽ�ɽ���", 13, "����");
        
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
	say("�Ϸ�Ӳ���ͽ�������ҷ�ʦ�ֺ��ˡ�", me);
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
          me->say(snprintf(msg, 255, "��λ%s����Ͷ�ҽ��ڰɡ�", query_respect(who)));
    else
    {
        message_vision("�ɲ�ϲһ��$N�ʹ�ŭ����������α���ӵ�ͽ���ˡ�", who);
        me->kill_ob(who);
    }

    return;
}

NPC_END;
