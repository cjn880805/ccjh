//dy5_duamuqing.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_duamuqing);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("¶ËÄ¾Çå", "dy5_duamuqing");

	set("icon", young_man1);
	set("gender", "ÄÐÐÔ");
	set("level", 108);

	set("max_hp", 21600);
	set("max_mp", 5400);
	set("mp_factor", 118);

	set("combat_exp", 6593900);

	set("chat_chance_combat", 20);
	

	set("str", 38);
	set("con", 53);
	set("int", 55);
	set("dex", 49);

	set_skill("dagou_bang", 374);
	set_skill("staff", 374);
	set_skill("xianglong_zhang", 374);
	set_skill("strike", 374);
	set_skill("xiaoyaoyou", 374);
	set_skill("dodge", 374);
	set_skill("huntian_qigong", 374);
	set_skill("force", 374);

	map_skill("staff", "dagou_bang");
	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 216);
	set("apply/damage", 246);

	create_family("Ø¤°ï", 2, "µÜ×Ó");

	carry_object("shuzhi2")->wield();

}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("staff zhuang", 1);
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