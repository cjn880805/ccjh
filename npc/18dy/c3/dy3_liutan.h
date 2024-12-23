//dy3_liutan.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_liutan);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("¡ıÃ√", "naihe_liutan");

	set("icon", cateran);
	set("gender", "ƒ––‘");
	set("level", 88);

	set("max_hp", 17600);
	set("max_mp", 4400);
	set("mp_factor", 98);

	set("combat_exp", 3401200);

	set("chat_chance_combat", 20);
	

	set("str", 48);
	set("con", 48);
	set("int", 38);
	set("dex", 44);

	set_skill("tiangang_zhi", 304);
	set_skill("finger", 304);
	set_skill("jinding_zhang", 304);
	set_skill("strike", 304);
	set_skill("zhutian_bu", 304);
	set_skill("dodge", 304);
	set_skill("linji_zhuang", 304);
	set_skill("force", 304);

	map_skill("finger", "tiangang_zhi");
	map_skill("strike", "jinding_zhang");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("finger", "tiangang_zhi");
	prepare_skill("strike", "jinding_zhang");

	set("apply/armor", 176);
	set("apply/damage", 206);

	create_family("∂Î·“≈…", 5, "µ‹◊”");


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