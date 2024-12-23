//dy3_songjiang.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_songjiang);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("ËÎ½«", "naihe_songjiang");

	set("icon", taoist_with_sword);
	set("gender", "ÄÐÐÔ");
	set("level", 80);

	set("max_hp", 16000);
	set("max_mp", 4000);
	set("mp_factor", 90);

	set("combat_exp", 2489700);

	set("chat_chance_combat", 20);
	

	set("str", 35);
	set("con", 29);
	set("int", 43);
	set("dex", 30);

	set_skill("huifeng_qijue", 276);
	set_skill("sword", 276);
	set_skill("jiuyin_zhua", 276);
	set_skill("claw", 276);
	set_skill("zhutian_bu", 276);
	set_skill("dodge", 276);
	set_skill("linji_zhuang", 276);
	set_skill("force", 276);

	map_skill("sword", "huifeng_qijue");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 160);
	set("apply/damage", 190);

	create_family("¶ëáÒÅÉ", 5, "µÜ×Ó");

	carry_object("mujian")->wield();

}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("sword mixhit", 1);
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