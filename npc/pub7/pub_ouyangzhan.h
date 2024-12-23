//pub_ouyangzhan.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_ouyangzhan);

void create()
{
	set_name("Å·ÑôÕ¼±ãÒË", "ouyang");

	set("title", "Æ´ÃüÕ¼±ãÒË");

	set("icon", 17);
	set("gender", "ÄÐÐÔ");
	set("level", 157);
	set("age", 35);
	set("shen_type", -1);

	set("max_hp", 25000+random(20000));
	set("max_mp", 10000);
	set("mp", 20000);
	set("mp_factor", 80);

	set("combat_exp", 42000000+random(10000000));
	set("score", 6000);

	set("chat_chance_combat", 40);

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 48);
	set("per", 16);

	set_skill("yinsuo_jinling", 360);
	set_skill("whip", 350);
	set_skill("wudu_shenzhang", 359);
	set_skill("unarmed", 355);
	set_skill("meinv_quan", 349);
	set_skill("parry", 380);
	set_skill("xianyun_bufa", 358);
	set_skill("dodge", 354);
	set_skill("yunv_xinjing", 400);
	set_skill("yunv_xinfa", 400);
	set_skill("wudu_xinfa", 400);
	set_skill("force", 366);
	set_skill("tianluo_diwang", 376);


	map_skill("whip", "yinsuo_jinling");
	map_skill("unarmed", "wudu_shenzhang");
	map_skill("parry", "meinv_quan");
	map_skill("dodge", "xianyun_bufa");
	map_skill("force", "yunv_xinjing");


	prepare_skill("unarmed", "wudu_shenzhang");

	set("apply/armor", 450);
	set("apply/damage", 100);

//	create_family("¹ÅÄ¹ÅÉ", 2, "ÆúÍ½");

	carry_object("changbian")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 1:
		perform_action("parry you", 1);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	case 3:
		perform_action("force powerup", 0);
		break;
	}

	return 0;
}


NPC_END;
