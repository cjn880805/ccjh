//dy2_liyj.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_liyj);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("李元吉", "huangquan_liyj");

	set("icon", general);
	set("gender", "男性");
	set("level", 75);

	set("max_hp", 15000);
	set("max_mp", 3750);
	set("mp_factor", 85);

	set("combat_exp", 2012300);

	set("chat_chance_combat", 20);
	

	set("str", 40);
	set("con", 40);
	set("int", 28);
	set("dex", 31);

	set_skill("lingshe_zhangfa", 259);
	set_skill("staff", 259);
	set_skill("shexing_diaoshou", 259);
	set_skill("hand", 259);
	set_skill("chanchu_bufa", 259);
	set_skill("dodge", 259);
	set_skill("hamagong", 259);
	set_skill("force", 259);

	map_skill("staff", "lingshe_zhangfa");
	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 150);
	set("apply/damage", 180);

	create_family("白驼山派", 5, "弟子");

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