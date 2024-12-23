//dy4_caoyun.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_caoyun);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("曹云", "gueimen_caoyun");

	set("icon", young_woman2);
	set("gender", "女性");
	set("level", 97);

	set("max_hp", 19400);
	set("max_mp", 4850);
	set("mp_factor", 107);

	set("combat_exp", 4665600);

	set("chat_chance_combat", 20);
	

	set("str", 36);
	set("con", 42);
	set("int", 35);
	set("dex", 38);

	set_skill("feifeng_whip", 336);
	set_skill("whip", 336);
	set_skill("jinyu_quan", 336);
	set_skill("cuff", 336);
	set_skill("qingdie_shenfa", 336);
	set_skill("dodge", 336);
	set_skill("kurong_changong", 336);
	set_skill("force", 336);

	map_skill("whip", "feifeng_whip");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "qingdie_shenfa");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 194);
	set("apply/damage", 224);

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