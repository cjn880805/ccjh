//pub_yinjiuyou.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_yinjiuyou);

void create()
{
	set_name("Òõ¾Å»ê", "yin jiuyou");

	set("title", "°ëÈË°ë¹í");

	set("icon", 44);
	set("gender", "ÄÐÐÔ");
	set("level", 157);
	set("age", 35);
	set("shen_type", -1);

	set("max_hp", 20000+random(5000));
	set("max_mp", 10000);
	set("mp", 20000);
	set("mp_factor", 50);

	set("combat_exp", 32000000+random(20000000));
	set("score", 6000);

	set("chat_chance_combat", 40);

	set("str", 35);
	set("con", 30);
	set("int", 30);
	set("dex", 40);
	set("per", 8);

	set_skill("wudu_zhang", 348);
	set_skill("strike", 340);
	set_skill("jiuyin_zhua", 349);
	set_skill("claw", 345);
	set_skill("meinv_quan", 349);
	set_skill("parry", 340);
	set_skill("xianyun_bufa", 358);
	set_skill("dodge", 354);
	set_skill("huagong_dafa", 380);
	set_skill("force", 366);
	set_skill("poison", 400);

	map_skill("strike", "wudu_zhang");
	map_skill("claw", "jiuyin_zhua");
	map_skill("parry", "meinv_quan");
	map_skill("dodge", "xianyun_bufa");
	map_skill("force", "huagong_dafa");

	prepare_skill("claw", "jiuyin_zhua");
	prepare_skill("strike", "wudu_zhang");

	set("apply/armor", 450);
	set("apply/damage", 40);

//	create_family("ÐÇËÞÅÉ", 2, "ÆúÍ½");

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
