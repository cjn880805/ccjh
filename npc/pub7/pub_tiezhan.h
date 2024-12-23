//pub_tiezhan.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_tiezhan);

void create()
{
	set_name("ÌúÕ¼", "tie zhan");

	set("title", "¿ñÊ¨");

	set("icon", 16);
	set("gender", "ÄÐÐÔ");
	set("level", 157);
	set("age", 35);
	set("shen_type", -1);

	set("max_hp", 20000+random(20000));
	set("max_mp", 10000);
	set("mp", 15000);
	set("mp_factor", 90);

	set("combat_exp", 48000000+random(10000000));
	set("score", 6000);

	set("chat_chance_combat", 30);

	set("str", 40);
	set("con", 30);
	set("int", 30);
	set("dex", 40);
	set("per", 16);

	set_skill("xue_dao", 358);
	set_skill("blade", 350);
	set_skill("huoyan_dao", 359);
	set_skill("strike", 355);
	set_skill("meinv_quan", 349);
	set_skill("parry", 340);
	set_skill("xianyun_bufa", 338);
	set_skill("dodge", 354);
	set_skill("longxiang", 380);
	set_skill("force", 366);
	set_skill("mizong_xinfa", 376);


	map_skill("blade", "xue_dao");
	map_skill("strike", "huoyan_dao");
	map_skill("parry", "meinv_quan");
	map_skill("dodge", "xianyun_bufa");
	map_skill("force", "longxiang");


	prepare_skill("strike", "huoyan_dao");

	set("apply/armor", 450);
	set("apply/damage", 90);

//	create_family("¹ÅÄ¹ÅÉ", 2, "ÆúÍ½");

	carry_object("gangdao")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 0:
		perform_action("blade jixue", 1);
		break;
	case 1:
		perform_action("strike fen", 1);
		break;
	case 2:
		perform_action("force fanchang", 1);
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
