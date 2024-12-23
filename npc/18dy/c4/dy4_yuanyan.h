//dy4_yuanyan.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_yuanyan);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("袁言", "gueimen_yuanyan");

	set("icon", young_woman11);
	set("gender", "女性");
	set("level", 93);

	set("max_hp", 18600);
	set("max_mp", 4650);
	set("mp_factor", 103);

	set("combat_exp", 4070700);

	set("chat_chance_combat", 20);
	

	set("str", 47);
	set("con", 47);
	set("int", 42);
	set("dex", 38);

	set_skill("feifeng_whip", 322);
	set_skill("whip", 322);
	set_skill("jinyu_quan", 322);
	set_skill("cuff", 322);
	set_skill("qingdie_shenfa", 322);
	set_skill("dodge", 322);
	set_skill("kurong_changong", 322);
	set_skill("force", 322);

	map_skill("whip", "feifeng_whip");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "qingdie_shenfa");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 186);
	set("apply/damage", 216);

	create_family("大理段家", 6, "弟子");

	carry_object("yangbian")->wield();

}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("force powerup", 0);
		break;
	case 1:
		perform_action("force recover", 0);
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