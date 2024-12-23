//dy3_guanshen.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_guanshen);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("关神", "naihe_guanshen");

	set("icon", young_man3);
	set("gender", "男性");
	set("level", 88);

	set("max_hp", 17600);
	set("max_mp", 4400);
	set("mp_factor", 98);

	set("combat_exp", 3401200);

	set("chat_chance_combat", 20);
	

	set("str", 32);
	set("con", 39);
	set("int", 39);
	set("dex", 48);

	set_skill("yanxing_dao", 304);
	set_skill("blade", 304);
	set_skill("jiuyin_zhua", 304);
	set_skill("claw", 304);
	set_skill("zhutian_bu", 304);
	set_skill("dodge", 304);
	set_skill("linji_zhuang", 304);
	set_skill("force", 304);

	map_skill("blade", "yanxing_dao");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 176);
	set("apply/damage", 206);

	create_family("峨嵋派", 4, "弟子");

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