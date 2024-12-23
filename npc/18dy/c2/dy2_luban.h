//dy2_luban.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_luban);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("Â³°à", "huangquan_luban");

	set("icon", old_man1);
	set("gender", "ÄÐÐÔ");
	set("level", 78);

	set("max_hp", 15600);
	set("max_mp", 3900);
	set("mp_factor", 88);

	set("combat_exp", 2290600);

	set("chat_chance_combat", 20);
	

	set("str", 34);
	set("con", 30);
	set("int", 33);
	set("dex", 41);

	set_skill("shexing_diaoshou", 269);
	set_skill("hand", 269);
	set_skill("chanchu_bufa", 269);
	set_skill("dodge", 269);
	set_skill("hamagong", 269);
	set_skill("force", 269);

	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 156);
	set("apply/damage", 186);

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