//dy5_qishi.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_qishi);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("气使", "dy5_qishi");

	set("icon", young_man1);
	set("gender", "男性");
	set("level", 103);

	set("max_hp", 20600);
	set("max_mp", 5150);
	set("mp_factor", 113);

	set("combat_exp", 5662300);

	set("chat_chance_combat", 20);
	

	set("str", 45);
	set("con", 50);
	set("int", 34);
	set("dex", 41);

	set_skill("xianglong_zhang", 357);
	set_skill("strike", 357);
	set_skill("xiaoyaoyou", 357);
	set_skill("dodge", 357);
	set_skill("huntian_qigong", 357);
	set_skill("force", 357);

	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 206);
	set("apply/damage", 236);

	create_family("丐帮", 4, "弟子");


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