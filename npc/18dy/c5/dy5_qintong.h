//dy5_qintong.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_qintong);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("ÇÙÍ¯", "dy5_qintong");

	set("icon", young_man1);
	set("gender", "ÄÐÐÔ");
	set("level", 106);

	set("max_hp", 21200);
	set("max_mp", 5300);
	set("mp_factor", 116);

	set("combat_exp", 6209900);

	set("chat_chance_combat", 20);
	

	set("str", 48);
	set("con", 35);
	set("int", 40);
	set("dex", 48);

	set_skill("dagou_bang", 367);
	set_skill("staff", 367);
	set_skill("xianglong_zhang", 367);
	set_skill("strike", 367);
	set_skill("xiaoyaoyou", 367);
	set_skill("dodge", 367);
	set_skill("huntian_qigong", 367);
	set_skill("force", 367);

	map_skill("staff", "dagou_bang");
	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 212);
	set("apply/damage", 242);

	create_family("Ø¤°ï", 3, "µÜ×Ó");

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