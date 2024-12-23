//dy4_zhugezhan.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_zhugezhan);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("诸葛盏", "gueimen_zhugezhan");

	set("icon", young_man1);
	set("gender", "男性");
	set("level", 96);

	set("max_hp", 19200);
	set("max_mp", 4800);
	set("mp_factor", 106);

	set("combat_exp", 4511800);

	set("chat_chance_combat", 20);
	

	set("str", 37);
	set("con", 37);
	set("int", 46);
	set("dex", 43);

	set_skill("duanjia_sword", 332);
	set_skill("sword", 332);
	set_skill("jinyu_quan", 332);
	set_skill("cuff", 332);
	set_skill("tiannan_step", 332);
	set_skill("dodge", 332);
	set_skill("kurong_changong", 332);
	set_skill("force", 332);

	map_skill("sword", "duanjia_sword");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 192);
	set("apply/damage", 222);

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