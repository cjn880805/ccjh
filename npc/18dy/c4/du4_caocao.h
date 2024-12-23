//du4_caocao.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdu4_caocao);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("曹槽", "du4_caocao");

	set("icon", old_man1);
	set("gender", "男性");
	set("level", 97);

	set("max_hp", 19400);
	set("max_mp", 4850);
	set("mp_factor", 107);

	set("combat_exp", 4665600);

	set("chat_chance_combat", 20);
	

	set("str", 45);
	set("con", 49);
	set("int", 34);
	set("dex", 39);

	set_skill("liumai_shenjian", 336);
	set_skill("finger", 336);
	set_skill("tiannan_step", 336);
	set_skill("dodge", 336);
	set_skill("kurong_changong", 336);
	set_skill("force", 336);

	map_skill("finger", "liumai_shenjian");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("finger", "liumai_shenjian");

	set("apply/armor", 194);
	set("apply/damage", 224);

	create_family("大理段家", 3, "弟子");


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