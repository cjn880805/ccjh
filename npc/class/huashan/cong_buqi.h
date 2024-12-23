//cong_buqi.h
//Lanwood 2000-01-08

NPC_BEGIN(CNhuashan_cong_buqi);

virtual void create()
{
		set_name("丛不放", "cong bufang");
        set("gender", "男性");
        set("class", "swordsman");
        set("title", "华山剑宗第十三代弟子");
        set("age", 52);
        set("long",  "丛不放是华山剑宗高手。");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set("icon",old_man1);

        set("mp", 4000);
        set("max_mp", 2400);
        set("mp_factor", 30);
        set("max_hp",6000);
        
        set("combat_exp", 1000000);
        set("repute", -200000);
        set("apprentice_available", 3);

        set("chat_chance_combat", 80);
        
        set_skill("unarmed", 80);
        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("literate", 100);
        set_skill("huashan_sword", 150);
        set_skill("zixia_shengong", 130);
        set_skill("huashan_ken", 80);
        set_skill("huashan_zhangfa", 80);
        set_skill("huashan_shenfa", 140);

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
	say("老夫不想收徒。", me);
	SendMenu(me);
}

NPC_END;
