//dy2_lijc.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_lijc);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("李建城", "huangquan_lijc");

	set("icon", general);
	set("gender", "男性");
	set("level", 74);

	set("max_hp", 14800);
	set("max_mp", 3700);
	set("mp_factor", 84);

	set("combat_exp", 1924800);

	set("chat_chance_combat", 20);
	

	set("str", 30);
	set("con", 31);
	set("int", 42);
	set("dex", 41);

	set_skill("shexing_diaoshou", 255);
	set_skill("hand", 255);
	set_skill("chanchu_bufa", 255);
	set_skill("dodge", 255);
	set_skill("hamagong", 255);
	set_skill("force", 255);

	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 148);
	set("apply/damage", 178);

	create_family("白驼山派", 2, "弟子");


}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("hand wugu", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force reserver", 1);
		break;
	case 3:
		perform_action("force recover", 0);
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