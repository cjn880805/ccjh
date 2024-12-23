//dy5_ouyangxue.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_ouyangxue);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("Å·ÑôÑª", "dy5_ouyangxue");

	set("icon", young_woman4);
	set("gender", "Å®ÐÔ");
	set("level", 108);

	set("max_hp", 21600);
	set("max_mp", 5400);
	set("mp_factor", 118);

	set("combat_exp", 6593900);

	set("chat_chance_combat", 20);
	

	set("str", 50);
	set("con", 54);
	set("int", 55);
	set("dex", 55);

	set_skill("xianglong_zhang", 374);
	set_skill("strike", 374);
	set_skill("xiaoyaoyou", 374);
	set_skill("dodge", 374);
	set_skill("huntian_qigong", 374);
	set_skill("force", 374);

	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 216);
	set("apply/damage", 246);

	create_family("Ø¤°ï", 5, "µÜ×Ó");


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