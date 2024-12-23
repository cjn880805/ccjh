//dy3gongsunshen.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3gongsunshen);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("公孙神", "naihe_gongsunshen");

	set("icon", taoist_with_sword);
	set("gender", "男性");
	set("level", 90);

	set("max_hp", 18000);
	set("max_mp", 4500);
	set("mp_factor", 100);

	set("combat_exp", 3659400);

	set("chat_chance_combat", 20);
	

	set("str", 47);
	set("con", 32);
	set("int", 42);
	set("dex", 42);

	set_skill("huifeng_qijue", 311);
	set_skill("sword", 311);
	set_skill("jiuyin_zhua", 311);
	set_skill("claw", 311);
	set_skill("zhutian_bu", 311);
	set_skill("dodge", 311);
	set_skill("linji_zhuang", 311);
	set_skill("force", 311);

	map_skill("sword", "huifeng_qijue");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 180);
	set("apply/damage", 210);

	create_family("峨嵋派", 4, "弟子");

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