//pub_dusha.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_dusha);

void create()
{
	set_name("¶ÅÉ·", "du sha");

	set("title", "ÑªÊÖ");

	set("icon", 16);
	set("gender", "ÄÐÐÔ");
	set("level", 157);
	set("age", 45);
	set("shen_type", -1);

	set("max_hp", 30000+random(20000));
	set("max_mp", 10000);
	set("mp", 20000);
	set("mp_factor", 50);

	set("combat_exp", 48000000+random(20000000));
	set("score", 6000);

	set("chat_chance_combat", 40);

	set("str", 38);
	set("con", 30);
	set("int", 30);
	set("dex", 40);
	set("per", 18);

	set_skill("riyue_lun", 368);
	set_skill("hammer", 360);
	set_skill("dashou_yin", 359);
	set_skill("hand", 355);
	set_skill("huoyan_dao", 369);
	set_skill("strike", 345);
	set_skill("meinv_quan", 349);
	set_skill("parry", 340);
	set_skill("shenkong_xing", 358);
	set_skill("dodge", 364);
	set_skill("xiaowuxiang", 380);
	set_skill("force", 366);
	set_skill("mizong_xinfa", 396);

	map_skill("hammer", "riyue_lun");
	map_skill("hand", "dashou_yin");
	map_skill("strike", "huoyan_dao");
	map_skill("parry", "meinv_quan");
	map_skill("dodge", "shenkong_xing");
	map_skill("force", "xiaowuxiang");

	prepare_skill("hand", "dashou_yin");
	prepare_skill("strike", "huoyan_dao");

	set("apply/armor", 450);
	set("apply/damage", 80);

	create_family("ÐÇËÞÅÉ", 2, "ÆúÍ½");

	carry_object("tongren")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 0:
		perform_action("strike fen", 1);
		break;
	case 1:
		perform_action("force shield", 0);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}


NPC_END;
