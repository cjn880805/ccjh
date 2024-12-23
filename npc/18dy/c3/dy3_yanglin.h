//dy3_yanglin.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_yanglin);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("—Ó¡‹", "naihe_yanglin");

	set("icon", triggerman1);
	set("gender", "ƒ––‘");
	set("level", 86);

	set("max_hp", 17200);
	set("max_mp", 4300);
	set("mp_factor", 96);

	set("combat_exp", 3155400);

	set("chat_chance_combat", 20);
	

	set("str", 31);
	set("con", 39);
	set("int", 30);
	set("dex", 42);

	set_skill("tiangang_zhi", 297);
	set_skill("finger", 297);
	set_skill("jinding_zhang", 297);
	set_skill("strike", 297);
	set_skill("zhutian_bu", 297);
	set_skill("dodge", 297);
	set_skill("linji_zhuang", 297);
	set_skill("force", 297);

	map_skill("finger", "tiangang_zhi");
	map_skill("strike", "jinding_zhang");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("finger", "tiangang_zhi");
	prepare_skill("strike", "jinding_zhang");

	set("apply/armor", 172);
	set("apply/damage", 202);

	create_family("∂Î·“≈…", 6, "µ‹◊”");


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