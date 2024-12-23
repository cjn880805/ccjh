//dy5_feng.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_feng);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("风", "dy5_feng");

	set("icon", young_woman4);
	set("gender", "女性");
	set("level", 104);

	set("max_hp", 20800);
	set("max_mp", 5200);
	set("mp_factor", 114);

	set("combat_exp", 5841100);

	set("chat_chance_combat", 20);
	

	set("str", 46);
	set("con", 51);
	set("int", 43);
	set("dex", 39);

	set_skill("dagou_bang", 360);
	set_skill("staff", 360);
	set_skill("xianglong_zhang", 360);
	set_skill("strike", 360);
	set_skill("xiaoyaoyou", 360);
	set_skill("dodge", 360);
	set_skill("huntian_qigong", 360);
	set_skill("force", 360);

	map_skill("staff", "dagou_bang");
	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 208);
	set("apply/damage", 238);

	create_family("丐帮", 3, "弟子");

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