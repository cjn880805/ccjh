//dy2_lijing.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_lijing);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("�", "huangquan_lijing");

	set("icon", general);
	set("gender", "����");
	set("level", 76);

	set("max_hp", 15200);
	set("max_mp", 3800);
	set("mp_factor", 86);

	set("combat_exp", 2102400);

	set("chat_chance_combat", 20);
	

	set("str", 36);
	set("con", 35);
	set("int", 40);
	set("dex", 39);

	set_skill("lingshe_zhangfa", 262);
	set_skill("staff", 262);
	set_skill("shexing_diaoshou", 262);
	set_skill("hand", 262);
	set_skill("chanchu_bufa", 262);
	set_skill("dodge", 262);
	set_skill("hamagong", 262);
	set_skill("force", 262);

	map_skill("staff", "lingshe_zhangfa");
	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 152);
	set("apply/damage", 182);

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