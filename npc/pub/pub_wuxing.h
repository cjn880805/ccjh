//pub_wuxing.h
//wuqing 2002-2-10 

NPC_BEGIN(CNpub_wuxing);

virtual void create()
{
	set_name("武兴","wu xing");
	set("nickname", "" );
	set("long", "他身配一把不起眼的长剑，眼中却流落不世的傲气。");
	set("gender", "男性");
	set("age", 80);
	
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",young_man1);	
	set("title","绝世傲剑");
	set("max_hp", 30000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_force", 300);
	set("combat_exp", 6000000);
	set("score", 1200000);

	set_skill("force", 350);
	set_skill("taiji_shengong", 350);
	set_skill("dodge", 350);
	set_skill("tiyunzong", 350);
	set_skill("unarmed", 350);
	set_skill("taiji_quan", 350);
	set_skill("parry", 350);
	set_skill("sword", 330);
	set_skill("taiji_jian", 350);
	set_skill("blade", 350);
	set_skill("taiji_dao", 350);
	set_skill("taoism", 350);
	set_skill("literate", 300);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");

	
	set("class", "taoist");
        
    set("apply/armor", 340);
	set("apply/damage", 400);
	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}

	return 0;
}

NPC_END;



