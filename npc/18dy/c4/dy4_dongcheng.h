//dy4_dongcheng.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_dongcheng);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("董成", "gueimen_dongcheng");

	set("icon", young_man3);
	set("gender", "男性");
	set("level", 92);

	set("max_hp", 18400);
	set("max_mp", 4600);
	set("mp_factor", 102);

	set("combat_exp", 3930400);

	set("chat_chance_combat", 20);
	

	set("str", 30);
	set("con", 49);
	set("int", 36);
	set("dex", 47);

	set_skill("duanjia_sword", 318);
	set_skill("sword", 318);
	set_skill("jinyu_quan", 318);
	set_skill("cuff", 318);
	set_skill("tiannan_step", 318);
	set_skill("dodge", 318);
	set_skill("kurong_changong", 318);
	set_skill("force", 318);

	map_skill("sword", "duanjia_sword");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 184);
	set("apply/damage", 214);

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