//dy3_duajingzhu.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_duajingzhu);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("¶Î¾°×¡", "naihe_duajingzhu");

	set("icon", triggerman1);
	set("gender", "ÄÐÐÔ");
	set("level", 82);

	set("max_hp", 16400);
	set("max_mp", 4100);
	set("mp_factor", 92);

	set("combat_exp", 2700000);

	set("chat_chance_combat", 20);
	

	set("str", 31);
	set("con", 34);
	set("int", 34);
	set("dex", 30);

	set_skill("tiangang_zhi", 283);
	set_skill("finger", 283);
	set_skill("jinding_zhang", 283);
	set_skill("strike", 283);
	set_skill("zhutian_bu", 283);
	set_skill("dodge", 283);
	set_skill("linji_zhuang", 283);
	set_skill("force", 283);

	map_skill("finger", "tiangang_zhi");
	map_skill("strike", "jinding_zhang");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("finger", "tiangang_zhi");
	prepare_skill("strike", "jinding_zhang");

	set("apply/armor", 164);
	set("apply/damage", 194);

	create_family("¶ëáÒÅÉ", 4, "µÜ×Ó");


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