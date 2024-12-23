//dy4_huaxiong.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_huaxiong);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("华熊", "gueimen_huaxiong");

	set("icon", old_monk);
	set("gender", "男性");
	set("level", 92);

	set("max_hp", 18400);
	set("max_mp", 4600);
	set("mp_factor", 102);

	set("combat_exp", 3930400);

	set("chat_chance_combat", 20);
	

	set("str", 37);
	set("con", 30);
	set("int", 45);
	set("dex", 46);

	set_skill("sun_finger", 318);
	set_skill("finger", 318);
	set_skill("tiannan_step", 318);
	set_skill("dodge", 318);
	set_skill("kurong_changong", 318);
	set_skill("force", 318);

	map_skill("finger", "sun_finger");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("finger", "sun_finger");

	set("apply/armor", 184);
	set("apply/damage", 214);

	create_family("大理段家", 3, "弟子");


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