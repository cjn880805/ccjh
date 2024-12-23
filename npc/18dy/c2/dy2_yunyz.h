//dy2_yunyz.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_yunyz);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("ÔÆÓñÕä", "huangquan_yunyz");

	set("icon", young_woman3);
	set("gender", "ÄÐÐÔ");
	set("level", 70);

	set("max_hp", 14000);
	set("max_mp", 3500);
	set("mp_factor", 80);

	set("combat_exp", 1600300);

	set("chat_chance_combat", 20);
	

	set("str", 37);
	set("con", 36);
	set("int", 38);
	set("dex", 33);

	set_skill("shexing_diaoshou", 241);
	set_skill("hand", 241);
	set_skill("chanchu_bufa", 241);
	set_skill("dodge", 241);
	set_skill("hamagong", 241);
	set_skill("force", 241);

	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 140);
	set("apply/damage", 170);

	create_family("°×ÍÕÉ½ÅÉ", 6, "µÜ×Ó");


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