//dy3_caozhen.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_caozhen);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("����", "naihe_caozhen");

	set("icon", young_man5);
	set("gender", "����");
	set("level", 85);

	set("max_hp", 17000);
	set("max_mp", 4250);
	set("mp_factor", 95);

	set("combat_exp", 3037100);

	set("chat_chance_combat", 20);
	

	set("str", 34);
	set("con", 43);
	set("int", 34);
	set("dex", 41);

	set_skill("jiuyin_zhua", 294);
	set_skill("claw", 294);
	set_skill("zhutian_bu", 294);
	set_skill("dodge", 294);
	set_skill("linji_zhuang", 294);
	set_skill("force", 294);

	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 170);
	set("apply/damage", 200);

	create_family("������", 6, "����");


}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("claw zhua", 1);
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