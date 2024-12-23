//dy4_gongsunlong.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_gongsunlong);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("公孙龙", "gueimen_gongsunlong");

	set("icon", young_man5);
	set("gender", "男性");
	set("level", 94);

	set("max_hp", 18800);
	set("max_mp", 4700);
	set("mp_factor", 104);

	set("combat_exp", 4214400);

	set("chat_chance_combat", 20);
	

	set("str", 48);
	set("con", 43);
	set("int", 47);
	set("dex", 35);

	set_skill("duanjia_sword", 325);
	set_skill("sword", 325);
	set_skill("jinyu_quan", 325);
	set_skill("cuff", 325);
	set_skill("tiannan_step", 325);
	set_skill("dodge", 325);
	set_skill("kurong_changong", 325);
	set_skill("force", 325);

	map_skill("sword", "duanjia_sword");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 188);
	set("apply/damage", 218);

	create_family("大理段家", 3, "弟子");

	carry_object("mujian")->wield();

}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("sword jingtian", 1);
		break;
	case 1:
		perform_action("sword fenglei", 1);
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