//dy4_simasan.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_simasan);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("司马三", "gueimen_simasan");

	set("icon", young_nun);
	set("gender", "女性");
	set("level", 95);

	set("max_hp", 19000);
	set("max_mp", 4750);
	set("mp_factor", 105);

	set("combat_exp", 4361400);

	set("chat_chance_combat", 20);
	

	set("str", 33);
	set("con", 37);
	set("int", 44);
	set("dex", 39);

	set_skill("feifeng_whip", 329);
	set_skill("whip", 329);
	set_skill("jinyu_quan", 329);
	set_skill("cuff", 329);
	set_skill("qingdie_shenfa", 329);
	set_skill("dodge", 329);
	set_skill("kurong_changong", 329);
	set_skill("force", 329);

	map_skill("whip", "feifeng_whip");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "qingdie_shenfa");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 190);
	set("apply/damage", 220);

	create_family("大理段家", 3, "弟子");

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