//dy2_shenly.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_shenly);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("ÉñÂäÑã", "huangquan_shenly");

	set("icon", young_woman2);
	set("gender", "ÄÐÐÔ");
	set("level", 71);

	set("max_hp", 14200);
	set("max_mp", 3550);
	set("mp_factor", 81);

	set("combat_exp", 1677700);

	set("chat_chance_combat", 20);
	

	set("str", 38);
	set("con", 34);
	set("int", 39);
	set("dex", 42);

	set_skill("shexing_diaoshou", 245);
	set_skill("hand", 245);
	set_skill("chanchu_bufa", 245);
	set_skill("dodge", 245);
	set_skill("hamagong", 245);
	set_skill("force", 245);

	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 142);
	set("apply/damage", 172);

	create_family("°×ÍÕÉ½ÅÉ", 2, "µÜ×Ó");


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