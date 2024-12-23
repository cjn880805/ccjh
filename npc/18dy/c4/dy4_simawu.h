//dy4_simawu.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_simawu);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("司马五", "gueimen_simawu");

	set("icon", young_man6);
	set("gender", "男性");
	set("level", 95);

	set("max_hp", 19000);
	set("max_mp", 4750);
	set("mp_factor", 105);

	set("combat_exp", 4361400);

	set("chat_chance_combat", 20);
	

	set("str", 40);
	set("con", 36);
	set("int", 33);
	set("dex", 50);

	set_skill("duanjia_sword", 329);
	set_skill("sword", 329);
	set_skill("jinyu_quan", 329);
	set_skill("cuff", 329);
	set_skill("tiannan_step", 329);
	set_skill("dodge", 329);
	set_skill("kurong_changong", 329);
	set_skill("force", 329);

	map_skill("sword", "duanjia_sword");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 190);
	set("apply/damage", 220);

	create_family("大理段家", 6, "弟子");

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