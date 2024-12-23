//dy4_liuchan.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_liuchan);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("刘婵", "gueimen_liuchan");

	set("icon", young_woman3);
	set("gender", "女性");
	set("level", 99);

	set("max_hp", 19800);
	set("max_mp", 4950);
	set("mp_factor", 109);

	set("combat_exp", 4983600);

	set("chat_chance_combat", 20);
	

	set("str", 48);
	set("con", 51);
	set("int", 46);
	set("dex", 47);

	set_skill("feifeng_whip", 343);
	set_skill("whip", 343);
	set_skill("jinyu_quan", 343);
	set_skill("cuff", 343);
	set_skill("qingdie_shenfa", 343);
	set_skill("dodge", 343);
	set_skill("kurong_changong", 343);
	set_skill("force", 343);

	map_skill("whip", "feifeng_whip");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "qingdie_shenfa");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 198);
	set("apply/damage", 228);

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