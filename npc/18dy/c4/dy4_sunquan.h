//dy4_sunquan.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_sunquan);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("孙全", "gueimen_sunquan");

	set("icon", young_man1);
	set("gender", "男性");
	set("level", 98);

	set("max_hp", 19600);
	set("max_mp", 4900);
	set("mp_factor", 108);

	set("combat_exp", 4822800);

	set("chat_chance_combat", 20);
	

	set("str", 40);
	set("con", 47);
	set("int", 32);
	set("dex", 33);

	set_skill("liumai_shenjian", 339);
	set_skill("finger", 339);
	set_skill("tiannan_step", 339);
	set_skill("dodge", 339);
	set_skill("kurong_changong", 339);
	set_skill("force", 339);

	map_skill("finger", "liumai_shenjian");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("finger", "liumai_shenjian");

	set("apply/armor", 196);
	set("apply/damage", 226);

	create_family("大理段家", 4, "弟子");


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