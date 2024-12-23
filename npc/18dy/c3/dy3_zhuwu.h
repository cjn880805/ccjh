//dy3_zhuwu.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_zhuwu);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("ÖìÎå", "naihe_zhuwu");

	set("icon", taoist);
	set("gender", "ÄÐÐÔ");
	set("level", 86);

	set("max_hp", 17200);
	set("max_mp", 4300);
	set("mp_factor", 96);

	set("combat_exp", 3155400);

	set("chat_chance_combat", 20);
	

	set("str", 33);
	set("con", 38);
	set("int", 39);
	set("dex", 35);

	set_skill("huifeng_qijue", 297);
	set_skill("sword", 297);
	set_skill("jiuyin_zhua", 297);
	set_skill("claw", 297);
	set_skill("zhutian_bu", 297);
	set_skill("dodge", 297);
	set_skill("linji_zhuang", 297);
	set_skill("force", 297);

	map_skill("sword", "huifeng_qijue");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 172);
	set("apply/damage", 202);

	create_family("¶ëáÒÅÉ", 4, "µÜ×Ó");

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