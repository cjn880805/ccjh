//dy3_kongming.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_kongming);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("¿×Ãû", "naihe_kongming");

	set("icon", tipstaff);
	set("gender", "ÄÐÐÔ");
	set("level", 85);

	set("max_hp", 17000);
	set("max_mp", 4250);
	set("mp_factor", 95);

	set("combat_exp", 3037100);

	set("chat_chance_combat", 20);
	

	set("str", 32);
	set("con", 36);
	set("int", 34);
	set("dex", 32);

	set_skill("huifeng_qijue", 294);
	set_skill("sword", 294);
	set_skill("jiuyin_zhua", 294);
	set_skill("claw", 294);
	set_skill("zhutian_bu", 294);
	set_skill("dodge", 294);
	set_skill("linji_zhuang", 294);
	set_skill("force", 294);

	map_skill("sword", "huifeng_qijue");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 170);
	set("apply/damage", 200);

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