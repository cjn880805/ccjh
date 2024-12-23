//dy3_shiyong.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_shiyong);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("ʯ��", "naihe_shiyong");

	set("icon", cateran);
	set("gender", "����");
	set("level", 84);

	set("max_hp", 16800);
	set("max_mp", 4200);
	set("mp_factor", 94);

	set("combat_exp", 2921800);

	set("chat_chance_combat", 20);
	

	set("str", 46);
	set("con", 39);
	set("int", 33);
	set("dex", 30);

	set_skill("yanxing_dao", 290);
	set_skill("blade", 290);
	set_skill("jiuyin_zhua", 290);
	set_skill("claw", 290);
	set_skill("zhutian_bu", 290);
	set_skill("dodge", 290);
	set_skill("linji_zhuang", 290);
	set_skill("force", 290);

	map_skill("blade", "yanxing_dao");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 168);
	set("apply/damage", 198);

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