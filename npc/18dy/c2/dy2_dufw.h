//dy2_dufw.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_dufw);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("¶Å¸£Íþ", "huangquan_dufw");

	set("icon", old_man2);
	set("gender", "ÄÐÐÔ");
	set("level", 77);

	set("max_hp", 15400);
	set("max_mp", 3850);
	set("mp_factor", 87);

	set("combat_exp", 2195200);

	set("chat_chance_combat", 20);
	

	set("str", 28);
	set("con", 35);
	set("int", 43);
	set("dex", 35);

	set_skill("shexing_diaoshou", 266);
	set_skill("hand", 266);
	set_skill("chanchu_bufa", 266);
	set_skill("dodge", 266);
	set_skill("hamagong", 266);
	set_skill("force", 266);

	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 154);
	set("apply/damage", 184);

	create_family("°×ÍÕÉ½ÅÉ", 5, "µÜ×Ó");


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