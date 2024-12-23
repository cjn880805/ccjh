//dy4_simayi.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_simayi);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("司马一", "gueimen_simayi");

	set("icon", old_monk);
	set("gender", "男性");
	set("level", 95);

	set("max_hp", 19000);
	set("max_mp", 4750);
	set("mp_factor", 105);

	set("combat_exp", 4361400);

	set("chat_chance_combat", 20);
	

	set("str", 32);
	set("con", 37);
	set("int", 35);
	set("dex", 37);

	set_skill("liumai_shenjian", 329);
	set_skill("finger", 329);
	set_skill("tiannan_step", 329);
	set_skill("dodge", 329);
	set_skill("kurong_changong", 329);
	set_skill("force", 329);

	map_skill("finger", "liumai_shenjian");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("finger", "liumai_shenjian");

	set("apply/armor", 190);
	set("apply/damage", 220);

	create_family("大理段家", 2, "弟子");


}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("finger ci", 1);
		break;
	case 1:
		perform_action("finger feng", 1);
		break;
	case 2:
		perform_action("finger tan", 1);
		break;
	case 3:
		perform_action("force powerup", 0);
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