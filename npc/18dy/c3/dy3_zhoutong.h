//dy3_zhoutong.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_zhoutong);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("÷‹Õ≠", "naihe_zhoutong");

	set("icon", banditi);
	set("gender", "ƒ––‘");
	set("level", 83);

	set("max_hp", 16600);
	set("max_mp", 4150);
	set("mp_factor", 93);

	set("combat_exp", 2809400);

	set("chat_chance_combat", 20);
	

	set("str", 33);
	set("con", 41);
	set("int", 30);
	set("dex", 36);

	set_skill("tiangang_zhi", 287);
	set_skill("finger", 287);
	set_skill("jinding_zhang", 287);
	set_skill("strike", 287);
	set_skill("zhutian_bu", 287);
	set_skill("dodge", 287);
	set_skill("linji_zhuang", 287);
	set_skill("force", 287);

	map_skill("finger", "tiangang_zhi");
	map_skill("strike", "jinding_zhang");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("finger", "tiangang_zhi");
	prepare_skill("strike", "jinding_zhang");

	set("apply/armor", 166);
	set("apply/damage", 196);

	create_family("∂Î·“≈…", 4, "µ‹◊”");


}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("finger lingkong", 1);
		break;
	case 1:
		perform_action("strike bashi", 1);
		break;
	case 2:
		perform_action("force powerup", 0);
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