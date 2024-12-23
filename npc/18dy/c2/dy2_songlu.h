//dy2_songlu.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_songlu);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("宋路", "huangquan_songlu");

	set("icon", old_man2);
	set("gender", "男性");
	set("level", 73);

	set("max_hp", 14600);
	set("max_mp", 3650);
	set("mp_factor", 83);

	set("combat_exp", 1839900);

	set("chat_chance_combat", 20);
	

	set("str", 35);
	set("con", 35);
	set("int", 30);
	set("dex", 31);

	set_skill("shexing_diaoshou", 252);
	set_skill("hand", 252);
	set_skill("chanchu_bufa", 252);
	set_skill("dodge", 252);
	set_skill("hamagong", 252);
	set_skill("force", 252);

	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 146);
	set("apply/damage", 176);

	create_family("白驼山派", 3, "弟子");


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