//pub_sword_master.h
//zcoya 2002-07-27

NPC_BEGIN(CNpub_sword_master);

void create()
{
	set_name("ÍõËïê±", "wangsun ou");

	set("title", "Ó°¡¤´ó½£Ê¦");

	set("icon", young_man3);
	set("gender", "ÄÐÐÔ");
	set("level", 157);
	set("age", 29);

	set("max_hp", 130000);
	set("max_mp", 3000);
	set("mp", 6000);
	set("mp_factor", 0l);

	set("combat_exp", 75000000);
	set("score", 6000);

	set("chat_chance_combat", 70);

	set("str", 40);
	set("con", 50);
	set("int", 40);
	set("dex", 18);
	set("per", 15);

	set_skill("lingxiao_kuaijian", 430);
	set_skill("sword", 420);
	set_skill("kongming_quan", 389);
	set_skill("unarmed", 315);
	set_skill("jinshe_zhang", 300);
	set_skill("strike", 452);
	set_skill("jinshe_jian", 379);
	set_skill("parry", 410);
	set_skill("xianyun_bufa", 358);
	set_skill("dodge", 354);
	set_skill("xixing_dafa", 401);
	set_skill("beiming_shengong", 139);
	set_skill("force", 366);


	map_skill("sword", "lingxiao_kuaijian");
	map_skill("unarmed", "kongming_quan");
	map_skill("strike", "jinshe_zhang");
	map_skill("parry", "jinshe_jian");
	map_skill("dodge", "xianyun_bufa");
	map_skill("force", "xixing_dafa");


	prepare_skill("unarmed", "kongming_quan");
	prepare_skill("claw", "jinshe_zhang");

	set("apply/armor", 450);
	set("apply/damage", 400);

//	create_family("¹ÅÄ¹ÅÉ", 2, "ÆúÍ½");

	carry_object("jinshe_jian")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(7))
	{
	case 0:
		perform_action("sword mixhit", 1);
		break;
	case 1:
		perform_action("force mpsuck", 1);
		break;
	case 2:
		perform_action("force maxsuck", 1);
		break;
	case 3:
		perform_action("force mpsucks", 1);
		break;
	case 4:
		perform_action("force suck", 1);
		break;
	case 5:
		perform_action("parry suo", 1);
		break;
	case 6:
		perform_action("strike fugu", 1);
		break;
	}

	return 0;
}


NPC_END;
