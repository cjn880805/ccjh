//dy2_yuwenhg.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_yuwenhg);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("���Ļ���", "huangquan_yuwenhg");

	set("icon", young_man6);
	set("gender", "����");
	set("level", 73);

	set("max_hp", 14600);
	set("max_mp", 3650);
	set("mp_factor", 83);

	set("combat_exp", 1839900);

	set("chat_chance_combat", 20);
	

	set("str", 36);
	set("con", 30);
	set("int", 34);
	set("dex", 28);

	set_skill("lingshe_zhangfa", 252);
	set_skill("staff", 252);
	set_skill("shexing_diaoshou", 252);
	set_skill("hand", 252);
	set_skill("chanchu_bufa", 252);
	set_skill("dodge", 252);
	set_skill("hamagong", 252);
	set_skill("force", 252);

	map_skill("staff", "lingshe_zhangfa");
	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 146);
	set("apply/damage", 176);

	create_family("����ɽ��", 2, "����");

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