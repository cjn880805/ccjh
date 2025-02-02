//dy3_wangdingqi.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_wangdingqi);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("������", "naihe_wangdingqi");

	set("icon", triggerman1);
	set("gender", "����");
	set("level", 82);

	set("max_hp", 16400);
	set("max_mp", 4100);
	set("mp_factor", 92);

	set("combat_exp", 2700000);

	set("chat_chance_combat", 20);
	

	set("str", 40);
	set("con", 34);
	set("int", 37);
	set("dex", 27);

	set_skill("yanxing_dao", 283);
	set_skill("blade", 283);
	set_skill("jiuyin_zhua", 283);
	set_skill("claw", 283);
	set_skill("zhutian_bu", 283);
	set_skill("dodge", 283);
	set_skill("linji_zhuang", 283);
	set_skill("force", 283);

	map_skill("blade", "yanxing_dao");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 164);
	set("apply/damage", 194);

	create_family("������", 2, "����");

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