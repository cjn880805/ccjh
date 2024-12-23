// wudang_wuchen.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_wuchen);

virtual void create()
{
	set_name("出尘道长", "wuchen daozhang");
	set("title", "红花会""二当家");
	set("nickname",  "追魂夺命剑"  );
	set("gender", "男性");
	set("age", 52);
        set("icon",old_man1);
	
	set("long", "他就是无尘道人。关于他的故事……唉，多情自古空余恨……。 ");
	set("attitude", "peaceful");
	set("class", "taoist");
	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	
	set("hp", 2000);
	set("max_hp", 6000);
	set("mp", 2500);
	set("max_mp", 2500);
	set("mp_factor", 100);
	
	set("book_count", 1);
	set("combat_exp", 1000000);
	
	
	set_skill("force", 200);
	set_skill("bibo_shengong", 200);
	set_skill("unarmed", 200);
	set_skill("xuanfeng_leg", 200);
	set_skill("dodge", 200);
	set_skill("damo_jian", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	
	map_skill("force"  , "bibo_shengong");
	map_skill("unarmed", "xuanfeng_leg");
	map_skill("dodge"  , "anying_fuxiang");
	map_skill("parry"  , "damo_jian");
	map_skill("sword"  , "damo_jian");
	set("chat_chance_combat", 10);
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
    
}

/*   set("chat_msg_combat", ({
(: perform_action, "sword.sanjue" :),
(: perform_action, "unarmed.kuangfeng" :),
(: exert_function, "powerup" :),
(: exert_function, "recover" :),
}) );
*/	

virtual char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("sword sanjue", 1);
		break;
	case 1:
		perform_action("unarmed kuangfeng", 1);
		break;
	case 2:
		perform_action("force powerup", 0);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

NPC_END;