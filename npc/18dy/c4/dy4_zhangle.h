//dy4_zhangle.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_zhangle);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("����", "gueimen_zhangle");

	set("icon", taoist_with_sword);
	set("gender", "����");
	set("level", 91);

	set("max_hp", 18200);
	set("max_mp", 4550);
	set("mp_factor", 101);

	set("combat_exp", 3793300);

	set("chat_chance_combat", 20);
	

	set("str", 33);
	set("con", 45);
	set("int", 36);
	set("dex", 48);

	set_skill("sun_finger", 315);
	set_skill("finger", 315);
	set_skill("tiannan_step", 315);
	set_skill("dodge", 315);
	set_skill("kurong_changong", 315);
	set_skill("force", 315);

	map_skill("finger", "sun_finger");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("finger", "sun_finger");

	set("apply/armor", 182);
	set("apply/damage", 212);

	create_family("����μ�", 2, "����");


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