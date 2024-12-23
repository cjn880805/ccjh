//dy5_wulv.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_wulv);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("ÎéÂÁ", "dy5_wulv");

	set("icon", young_man2);
	set("gender", "ÄÐÐÔ");
	set("level", 101);

	set("max_hp", 20200);
	set("max_mp", 5050);
	set("mp_factor", 111);

	set("combat_exp", 5315700);

	set("chat_chance_combat", 20);
	

	set("str", 46);
	set("con", 40);
	set("int", 39);
	set("dex", 38);

	set_skill("dagou_bang", 350);
	set_skill("staff", 350);
	set_skill("xianglong_zhang", 350);
	set_skill("strike", 350);
	set_skill("xiaoyaoyou", 350);
	set_skill("dodge", 350);
	set_skill("huntian_qigong", 350);
	set_skill("force", 350);

	map_skill("staff", "dagou_bang");
	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 202);
	set("apply/damage", 232);

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