//dy5_ximenfu.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_ximenfu);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("西门浮", "dy5_ximenfu");

	set("icon", young_man3);
	set("gender", "男性");
	set("level", 108);

	set("max_hp", 21600);
	set("max_mp", 5400);
	set("mp_factor", 118);

	set("combat_exp", 6593900);

	set("chat_chance_combat", 20);
	

	set("str", 37);
	set("con", 49);
	set("int", 37);
	set("dex", 41);

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

	create_family("丐帮", 3, "弟子");


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