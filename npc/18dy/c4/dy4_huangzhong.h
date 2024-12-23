//dy4_huangzhong.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_huangzhong);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("黄中", "gueimen_huangzhong");

	set("icon", old_man1);
	set("gender", "男性");
	set("level", 100);

	set("max_hp", 20000);
	set("max_mp", 5000);
	set("mp_factor", 110);

	set("combat_exp", 5147800);

	set("chat_chance_combat", 20);
	

	set("str", 50);
	set("con", 37);
	set("int", 41);
	set("dex", 52);

	set_skill("feifeng_whip", 346);
	set_skill("whip", 346);
	set_skill("jinyu_quan", 346);
	set_skill("cuff", 346);
	set_skill("qingdie_shenfa", 346);
	set_skill("dodge", 346);
	set_skill("kurong_changong", 346);
	set_skill("force", 346);

	map_skill("whip", "feifeng_whip");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "qingdie_shenfa");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 200);
	set("apply/damage", 230);

	create_family("大理段家", 5, "弟子");

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