//dy4_guanyu.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_guanyu);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("关雨", "gueimen_guanyu");

	set("icon", young_man1);
	set("gender", "男性");
	set("level", 100);

	set("max_hp", 20000);
	set("max_mp", 5000);
	set("mp_factor", 110);

	set("combat_exp", 5147800);

	set("chat_chance_combat", 20);
	

	set("str", 43);
	set("con", 33);
	set("int", 47);
	set("dex", 50);

	set_skill("sun_finger", 346);
	set_skill("finger", 346);
	set_skill("tiannan_step", 346);
	set_skill("dodge", 346);
	set_skill("kurong_changong", 346);
	set_skill("force", 346);

	map_skill("finger", "sun_finger");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("finger", "sun_finger");

	set("apply/armor", 200);
	set("apply/damage", 230);

	create_family("大理段家", 5, "弟子");


}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("finger qiankun", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force recover", 0);
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