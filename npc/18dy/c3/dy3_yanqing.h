//dy3_yanqing.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_yanqing);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("—‡«Â", "naihe_yanqing");

	set("icon", young_man3);
	set("gender", "ƒ––‘");
	set("level", 87);

	set("max_hp", 17400);
	set("max_mp", 4350);
	set("mp_factor", 97);

	set("combat_exp", 3276800);

	set("chat_chance_combat", 20);
	

	set("str", 41);
	set("con", 46);
	set("int", 45);
	set("dex", 33);

	set_skill("tiangang_zhi", 301);
	set_skill("finger", 301);
	set_skill("jinding_zhang", 301);
	set_skill("strike", 301);
	set_skill("zhutian_bu", 301);
	set_skill("dodge", 301);
	set_skill("linji_zhuang", 301);
	set_skill("force", 301);

	map_skill("finger", "tiangang_zhi");
	map_skill("strike", "jinding_zhang");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("finger", "tiangang_zhi");
	prepare_skill("strike", "jinding_zhang");

	set("apply/armor", 174);
	set("apply/damage", 204);

	create_family("∂Î·“≈…", 3, "µ‹◊”");


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