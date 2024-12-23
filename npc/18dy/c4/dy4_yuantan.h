//dy4_yuantan.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_yuantan);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("袁谈", "gueimen_yuantan");

	set("icon", young_man2);
	set("gender", "男性");
	set("level", 93);

	set("max_hp", 18600);
	set("max_mp", 4650);
	set("mp_factor", 103);

	set("combat_exp", 4070700);

	set("chat_chance_combat", 20);
	

	set("str", 31);
	set("con", 35);
	set("int", 46);
	set("dex", 32);

	set_skill("duanjia_sword", 322);
	set_skill("sword", 322);
	set_skill("jinyu_quan", 322);
	set_skill("cuff", 322);
	set_skill("tiannan_step", 322);
	set_skill("dodge", 322);
	set_skill("kurong_changong", 322);
	set_skill("force", 322);

	map_skill("sword", "duanjia_sword");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 186);
	set("apply/damage", 216);

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