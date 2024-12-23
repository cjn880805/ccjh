//dy4_sunche.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_sunche);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("�ﳵ", "gueimen_sunche");

	set("icon", young_man3);
	set("gender", "����");
	set("level", 98);

	set("max_hp", 19600);
	set("max_mp", 4900);
	set("mp_factor", 108);

	set("combat_exp", 4822800);

	set("chat_chance_combat", 20);
	

	set("str", 48);
	set("con", 38);
	set("int", 50);
	set("dex", 42);

	set_skill("duanjia_sword", 339);
	set_skill("sword", 339);
	set_skill("jinyu_quan", 339);
	set_skill("cuff", 339);
	set_skill("tiannan_step", 339);
	set_skill("dodge", 339);
	set_skill("kurong_changong", 339);
	set_skill("force", 339);

	map_skill("sword", "duanjia_sword");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 196);
	set("apply/damage", 226);

	create_family("�����μ�", 3, "����");

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