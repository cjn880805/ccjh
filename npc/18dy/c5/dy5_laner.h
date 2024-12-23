//dy5_laner.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_laner);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("À¼¶ù", "dy5_laner");

	set("icon", young_woman8);
	set("gender", "Å®ÐÔ");
	set("level", 109);

	set("max_hp", 21800);
	set("max_mp", 5450);
	set("mp_factor", 119);

	set("combat_exp", 6791700);

	set("chat_chance_combat", 20);
	

	set("str", 41);
	set("con", 43);
	set("int", 40);
	set("dex", 47);

	set_skill("xianglong_zhang", 378);
	set_skill("strike", 378);
	set_skill("xiaoyaoyou", 378);
	set_skill("dodge", 378);
	set_skill("huntian_qigong", 378);
	set_skill("force", 378);

	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 218);
	set("apply/damage", 248);

	create_family("Ø¤°ï", 2, "µÜ×Ó");


}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("strike leiting", 1);
		break;
	case 1:
		perform_action("force poweruop", 1);
		break;
	case 2:
		perform_action("force shengang", 1);
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