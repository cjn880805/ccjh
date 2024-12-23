//dy5_lei.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_lei);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("À×", "dy5_lei");

	set("icon", young_man1);
	set("gender", "ÄÐÐÔ");
	set("level", 104);

	set("max_hp", 20800);
	set("max_mp", 5200);
	set("mp_factor", 114);

	set("combat_exp", 5841100);

	set("chat_chance_combat", 20);
	

	set("str", 34);
	set("con", 37);
	set("int", 36);
	set("dex", 35);

	set_skill("xianglong_zhang", 360);
	set_skill("strike", 360);
	set_skill("xiaoyaoyou", 360);
	set_skill("dodge", 360);
	set_skill("huntian_qigong", 360);
	set_skill("force", 360);

	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 208);
	set("apply/damage", 238);

	create_family("Ø¤°ï", 6, "µÜ×Ó");


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