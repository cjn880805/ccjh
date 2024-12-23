//dy4_yuanshu.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_yuanshu);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("袁输", "gueimen_yuanshu");

	set("icon", old_monk);
	set("gender", "男性");
	set("level", 93);

	set("max_hp", 18600);
	set("max_mp", 4650);
	set("mp_factor", 103);

	set("combat_exp", 4070700);

	set("chat_chance_combat", 20);
	

	set("str", 33);
	set("con", 32);
	set("int", 43);
	set("dex", 33);

	set_skill("sun_finger", 322);
	set_skill("finger", 322);
	set_skill("tiannan_step", 322);
	set_skill("dodge", 322);
	set_skill("kurong_changong", 322);
	set_skill("force", 322);

	map_skill("finger", "sun_finger");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("finger", "sun_finger");

	set("apply/armor", 186);
	set("apply/damage", 216);

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