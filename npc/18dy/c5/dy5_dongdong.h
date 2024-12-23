//dy5_dongdong.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_dongdong);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("东东", "dy5_dongdong");

	set("icon", young_man2);
	set("gender", "男性");
	set("level", 105);

	set("max_hp", 21000);
	set("max_mp", 5250);
	set("mp_factor", 115);

	set("combat_exp", 6023600);

	set("chat_chance_combat", 20);
	

	set("str", 48);
	set("con", 45);
	set("int", 54);
	set("dex", 44);

	set_skill("dagou_bang", 364);
	set_skill("staff", 364);
	set_skill("xianglong_zhang", 364);
	set_skill("strike", 364);
	set_skill("xiaoyaoyou", 364);
	set_skill("dodge", 364);
	set_skill("huntian_qigong", 364);
	set_skill("force", 364);

	map_skill("staff", "dagou_bang");
	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 210);
	set("apply/damage", 240);

	create_family("丐帮", 2, "弟子");

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