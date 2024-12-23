//dy3_lujunyi.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_lujunyi);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("Â¬¾ýÒå", "naihe_lujunyi");

	set("icon", young_man5);
	set("gender", "ÄÐÐÔ");
	set("level", 80);

	set("max_hp", 16000);
	set("max_mp", 4000);
	set("mp_factor", 90);

	set("combat_exp", 2489700);

	set("chat_chance_combat", 20);
	

	set("str", 45);
	set("con", 39);
	set("int", 40);
	set("dex", 30);

	set_skill("tiangang_zhi", 276);
	set_skill("finger", 276);
	set_skill("jinding_zhang", 276);
	set_skill("strike", 276);
	set_skill("zhutian_bu", 276);
	set_skill("dodge", 276);
	set_skill("linji_zhuang", 276);
	set_skill("force", 276);

	map_skill("finger", "tiangang_zhi");
	map_skill("strike", "jinding_zhang");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("finger", "tiangang_zhi");
	prepare_skill("strike", "jinding_zhang");

	set("apply/armor", 160);
	set("apply/damage", 190);

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