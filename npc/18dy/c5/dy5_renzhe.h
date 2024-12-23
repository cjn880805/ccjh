//dy5_renzhe.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_renzhe);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("ÈÌÕß", "dy5_renzhe");

	set("icon", masked_man);
	set("gender", "ÄÐÐÔ");
	set("level", 107);

	set("max_hp", 21400);
	set("max_mp", 5350);
	set("mp_factor", 117);

	set("combat_exp", 6400000);

	set("chat_chance_combat", 20);
	

	set("str", 47);
	set("con", 53);
	set("int", 38);
	set("dex", 53);

	set_skill("dagou_bang", 371);
	set_skill("staff", 371);
	set_skill("xianglong_zhang", 371);
	set_skill("strike", 371);
	set_skill("xiaoyaoyou", 371);
	set_skill("dodge", 371);
	set_skill("huntian_qigong", 371);
	set_skill("force", 371);

	map_skill("staff", "dagou_bang");
	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 214);
	set("apply/damage", 244);

	create_family("Ø¤°ï", 6, "µÜ×Ó");

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