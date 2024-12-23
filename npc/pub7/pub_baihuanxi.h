//pub_baihuanxi.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_baihuanxi);

void create()
{
	set_name("°×»¶Ï²", "bai huanxi");

	set("title", "ËðÈË²»ÀûÒÑ");

	set("icon", 1);
	set("gender", "ÄÐÐÔ");
	set("level", 157);
	set("age", 35);
	set("shen_type", -1);

	set("max_hp", 30000+random(10000));
	set("max_mp", 9000);
	set("mp", 18000);
	set("mp_factor", 100);

	set("combat_exp", 38000000+random(10000000));
	set("score", 6000);

	set("chat_chance_combat", 40);

	set("str", 35);
	set("con", 30);
	set("int", 30);
	set("dex", 40);
	set("per", 10);

	set_skill("lingshe_zhangfa", 368);
	set_skill("staff", 350);
	set_skill("xianglong_zhang", 368);
	set_skill("unarmed", 350);
	set_skill("shexing_diaoshou", 349);
	set_skill("hand", 355);
	set_skill("yunlong_bian", 349);
	set_skill("parry", 340);
	set_skill("chanchu_bufa", 358);
	set_skill("dodge", 354);
	set_skill("hamagong", 350);
	set_skill("force", 366);

	map_skill("staff", "lingshe_zhangfa");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "meinv_quan");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("unarmed", "xianglong_zhang");
	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 450);
	set("apply/damage", 30);

//	create_family("ÐÇËÞÅÉ", 2, "ÆúÍ½");

	carry_object("shezhang")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 0:
		perform_action("staff pili", 1);
		break;
	case 1:
		perform_action("hand wugu", 1);
		break;
	case 2:
		perform_action("force powerup", 0);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	case 4:
		perform_action("force reserve", 0);
		break;
	}

	return 0;
}


NPC_END;
