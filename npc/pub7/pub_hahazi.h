//pub_hahazi.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_hahazi);

void create()
{
	set_name("¹þ¹þ×Ó", "hahazi");

	set("title", "Ð¦Àï²Øµ¶Ð¦ÃÖÍÓ");

	set("icon", 9);
	set("gender", "ÄÐÐÔ");
	set("level", 157);
	set("age", 35);
	set("shen_type", -1);

	set("max_hp", 40000+random(10000));
	set("max_mp", 10000);
	set("mp", 20000);
	set("mp_factor", 80);

	set("combat_exp", 46000000+random(20000000));
	set("score", 6000);

	set("chat_chance_combat", 40);

	set("str", 35);
	set("con", 30);
	set("int", 30);
	set("dex", 40);
	set("per", 8);

	set_skill("xianglong_zhang", 368);
	set_skill("unarmed", 350);
	set_skill("shexing_diaoshou", 349);
	set_skill("hand", 355);
	set_skill("meinv_quan", 349);
	set_skill("parry", 340);
	set_skill("xianyun_bufa", 358);
	set_skill("dodge", 354);
	set_skill("huntian_qigong", 350);
	set_skill("force", 366);


	map_skill("unarmed", "xianglong_zhang");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "meinv_quan");
	map_skill("dodge", "xianyun_bufa");
	map_skill("force", "huntian_qigong");

	prepare_skill("unarmed", "xianglong_zhang");
	prepare_skill("hand", "shexing_diaoshou");

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
		perform_action("unarmed leiting", 1);
		break;
	case 1:
		perform_action("unarmed shenlong", 1);
		break;
	case 2:
		perform_action("force shengang", 0);
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
