//pub_likuozui.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_likuozui);

void create()
{
	set_name("ÀîÀ«×ì", "li kuozui");

	set("title", "²»³ÔÈËÍ·");

	set("icon", 9);
	set("gender", "ÄÐÐÔ");
	set("level", 157);
	set("age", 35);
	set("shen_type", -1);

	set("max_hp", 30000+random(20000));
	set("max_mp", 10000);
	set("mp", 20000);
	set("mp_factor", 50);

	set("combat_exp", 42000000+random(10000000));
	set("score", 6000);

	set("chat_chance_combat", 40);

	set("str", 35);
	set("con", 30);
	set("int", 30);
	set("dex", 40);
	set("per", 16);

	set_skill("xuedao", 348);
	set_skill("blade", 340);
	set_skill("sanyin_wugongzhao", 349);
	set_skill("claw", 345);
	set_skill("xingxiu_duzhang", 349);
	set_skill("strike", 345);
	set_skill("meinv_quan", 349);
	set_skill("parry", 340);
	set_skill("xianyun_bufa", 358);
	set_skill("dodge", 354);
	set_skill("huagong_dafa", 380);
	set_skill("force", 366);
	set_skill("poison", 400);


	map_skill("claw", "sanyin_wugongzhao");
	map_skill("strike", "xingxiu_duzhang");
	map_skill("parry", "meinv_quan");
	map_skill("dodge", "xianyun_bufa");
	map_skill("force", "huagong_dafa");

	prepare_skill("claw", "sanyin_wugongzhao");
	prepare_skill("strike", "xingxiu_duzhang");

	set("apply/armor", 450);
	set("apply/damage", 30);

	create_family("ÐÇËÞÅÉ", 2, "ÆúÍ½");

//	carry_object("gangdao")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 0:
		perform_action("force mpsuck", 1);
		break;
	case 1:
		perform_action("force maxsuck", 1);
		break;
	case 2:
		perform_action("force hpsuck", 1);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	case 4:
		perform_action("force powerup", 0);
		break;
	}

	return 0;
}


NPC_END;
