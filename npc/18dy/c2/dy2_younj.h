//dy2_younj.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_younj);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("ÓÐÄñ¾í", "huangquan_younj");

	set("icon", banditi);
	set("gender", "ÄÐÐÔ");
	set("level", 74);

	set("max_hp", 14800);
	set("max_mp", 3700);
	set("mp_factor", 84);

	set("combat_exp", 1924800);

	set("chat_chance_combat", 20);
	

	set("str", 25);
	set("con", 33);
	set("int", 31);
	set("dex", 27);

	set_skill("lingshe_zhangfa", 255);
	set_skill("staff", 255);
	set_skill("shexing_diaoshou", 255);
	set_skill("hand", 255);
	set_skill("chanchu_bufa", 255);
	set_skill("dodge", 255);
	set_skill("hamagong", 255);
	set_skill("force", 255);

	map_skill("staff", "lingshe_zhangfa");
	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 148);
	set("apply/damage", 178);

	create_family("°×ÍÕÉ½ÅÉ", 6, "µÜ×Ó");

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