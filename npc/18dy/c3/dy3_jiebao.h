//dy3_jiebao.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_jiebao);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("½â±¥", "naihe_jiebao");

	set("icon", young_man4);
	set("gender", "ÄÐÐÔ");
	set("level", 87);

	set("max_hp", 17400);
	set("max_mp", 4350);
	set("mp_factor", 97);

	set("combat_exp", 3276800);

	set("chat_chance_combat", 20);
	

	set("str", 45);
	set("con", 34);
	set("int", 42);
	set("dex", 34);

	set_skill("huifeng_qijue", 301);
	set_skill("sword", 301);
	set_skill("jiuyin_zhua", 301);
	set_skill("claw", 301);
	set_skill("zhutian_bu", 301);
	set_skill("dodge", 301);
	set_skill("linji_zhuang", 301);
	set_skill("force", 301);

	map_skill("sword", "huifeng_qijue");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 174);
	set("apply/damage", 204);

	create_family("¶ëáÒÅÉ", 3, "µÜ×Ó");

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