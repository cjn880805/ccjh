//dy3_luozhishen.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_luozhishen);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("³ֱ��", "naihe_luozhishen");

	set("icon", old_man1);
	set("gender", "����");
	set("level", 90);

	set("max_hp", 18000);
	set("max_mp", 4500);
	set("mp_factor", 100);

	set("combat_exp", 3659400);

	set("chat_chance_combat", 20);
	

	set("str", 43);
	set("con", 39);
	set("int", 48);
	set("dex", 33);

	set_skill("yanxing_dao", 311);
	set_skill("blade", 311);
	set_skill("jiuyin_zhua", 311);
	set_skill("claw", 311);
	set_skill("zhutian_bu", 311);
	set_skill("dodge", 311);
	set_skill("linji_zhuang", 311);
	set_skill("force", 311);

	map_skill("blade", "yanxing_dao");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 180);
	set("apply/damage", 210);

	create_family("������", 6, "����");

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