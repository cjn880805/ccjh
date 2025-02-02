//dy2_duguc.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_duguc);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("���²�", "huangquan_duguc");

	set("icon", old_man1);
	set("gender", "����");
	set("level", 77);

	set("max_hp", 15400);
	set("max_mp", 3850);
	set("mp_factor", 87);

	set("combat_exp", 2195200);

	set("chat_chance_combat", 20);
	

	set("str", 44);
	set("con", 42);
	set("int", 29);
	set("dex", 32);

	set_skill("lingshe_zhangfa", 266);
	set_skill("staff", 266);
	set_skill("shexing_diaoshou", 266);
	set_skill("hand", 266);
	set_skill("chanchu_bufa", 266);
	set_skill("dodge", 266);
	set_skill("hamagong", 266);
	set_skill("force", 266);

	map_skill("staff", "lingshe_zhangfa");
	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 154);
	set("apply/damage", 184);

	create_family("����ɽ��", 3, "����");

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