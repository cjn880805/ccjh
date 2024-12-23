//dy2_bixuan.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_bixuan);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("±ÏìÅ", "huangquan_bixuan");

	set("icon", old_man2);
	set("gender", "ÄÐÐÔ");
	set("level", 80);

	set("max_hp", 16000);
	set("max_mp", 4000);
	set("mp_factor", 90);

	set("combat_exp", 2489700);

	set("chat_chance_combat", 20);
	

	set("str", 42);
	set("con", 33);
	set("int", 35);
	set("dex", 43);

	set_skill("lingshe_zhangfa", 276);
	set_skill("staff", 276);
	set_skill("shexing_diaoshou", 276);
	set_skill("hand", 276);
	set_skill("chanchu_bufa", 276);
	set_skill("dodge", 276);
	set_skill("hamagong", 276);
	set_skill("force", 276);

	map_skill("staff", "lingshe_zhangfa");
	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 160);
	set("apply/damage", 190);

	create_family("°×ÍÕÉ½ÅÉ", 5, "µÜ×Ó");

	carry_object("shuzhi2")->wield();

}

char * chat_msg_combat()
{
	switch(random(9))
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
		perform_action("force reserver", 1);
		break;
	case 4:
		perform_action("force recover", 0);
		break;
	case 5:
		perform_action("force recover", 0);
		break;
	case 6:
		perform_action("force recover", 0);
		break;
	case 7:
		perform_action("force recover", 0);
		break;
	case 8:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

MONSTER_END;