//dy3_yangzhi.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_yangzhi);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("—Ó÷±", "naihe_yangzhi");

	set("icon", young_man2);
	set("gender", "ƒ––‘");
	set("level", 89);

	set("max_hp", 17800);
	set("max_mp", 4450);
	set("mp_factor", 99);

	set("combat_exp", 3528700);

	set("chat_chance_combat", 20);
	

	set("str", 43);
	set("con", 33);
	set("int", 33);
	set("dex", 46);

	set_skill("tiangang_zhi", 308);
	set_skill("finger", 308);
	set_skill("jinding_zhang", 308);
	set_skill("strike", 308);
	set_skill("zhutian_bu", 308);
	set_skill("dodge", 308);
	set_skill("linji_zhuang", 308);
	set_skill("force", 308);

	map_skill("finger", "tiangang_zhi");
	map_skill("strike", "jinding_zhang");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("finger", "tiangang_zhi");
	prepare_skill("strike", "jinding_zhang");

	set("apply/armor", 178);
	set("apply/damage", 208);

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