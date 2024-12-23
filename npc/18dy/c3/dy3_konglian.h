//dy3_konglian.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_konglian);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("¿×Á¹", "naihe_konglian");

	set("icon", taoist);
	set("gender", "ÄÐÐÔ");
	set("level", 85);

	set("max_hp", 17000);
	set("max_mp", 4250);
	set("mp_factor", 95);

	set("combat_exp", 3037100);

	set("chat_chance_combat", 20);
	

	set("str", 43);
	set("con", 42);
	set("int", 42);
	set("dex", 44);

	set_skill("tiangang_zhi", 294);
	set_skill("finger", 294);
	set_skill("jinding_zhang", 294);
	set_skill("strike", 294);
	set_skill("zhutian_bu", 294);
	set_skill("dodge", 294);
	set_skill("linji_zhuang", 294);
	set_skill("force", 294);

	map_skill("finger", "tiangang_zhi");
	map_skill("strike", "jinding_zhang");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("finger", "tiangang_zhi");
	prepare_skill("strike", "jinding_zhang");

	set("apply/armor", 170);
	set("apply/damage", 200);

	create_family("¶ëáÒÅÉ", 5, "µÜ×Ó");


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