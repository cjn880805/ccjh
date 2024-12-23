//dy3_ligun.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_ligun);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("Àî¹ö", "naihe_ligun");

	set("icon", young_man4);
	set("gender", "ÄÐÐÔ");
	set("level", 84);

	set("max_hp", 16800);
	set("max_mp", 4200);
	set("mp_factor", 94);

	set("combat_exp", 2921800);

	set("chat_chance_combat", 20);
	

	set("str", 29);
	set("con", 47);
	set("int", 44);
	set("dex", 44);

	set_skill("tiangang_zhi", 290);
	set_skill("finger", 290);
	set_skill("jinding_zhang", 290);
	set_skill("strike", 290);
	set_skill("zhutian_bu", 290);
	set_skill("dodge", 290);
	set_skill("linji_zhuang", 290);
	set_skill("force", 290);

	map_skill("finger", "tiangang_zhi");
	map_skill("strike", "jinding_zhang");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("finger", "tiangang_zhi");
	prepare_skill("strike", "jinding_zhang");

	set("apply/armor", 168);
	set("apply/damage", 198);

	create_family("¶ëáÒÅÉ", 3, "µÜ×Ó");


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