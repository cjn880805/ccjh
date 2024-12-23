//dy3_dingdesun.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_dingdesun);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("������", "naihe_dingdesun");

	set("icon", young_man4);
	set("gender", "����");
	set("level", 83);

	set("max_hp", 16600);
	set("max_mp", 4150);
	set("mp_factor", 93);

	set("combat_exp", 2809400);

	set("chat_chance_combat", 20);
	

	set("str", 27);
	set("con", 34);
	set("int", 29);
	set("dex", 45);

	set_skill("yanxing_dao", 287);
	set_skill("blade", 287);
	set_skill("jiuyin_zhua", 287);
	set_skill("claw", 287);
	set_skill("zhutian_bu", 287);
	set_skill("dodge", 287);
	set_skill("linji_zhuang", 287);
	set_skill("force", 287);

	map_skill("blade", "yanxing_dao");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 166);
	set("apply/damage", 196);

	create_family("������", 4, "����");

	carry_object("caidao")->wield();

}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("blade huanying", 1);
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