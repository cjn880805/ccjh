//dy4_zhangquan.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_zhangquan);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("张拳", "gueimen_zhangquan");

	set("icon", taoist_with_sword);
	set("gender", "男性");
	set("level", 91);

	set("max_hp", 18200);
	set("max_mp", 4550);
	set("mp_factor", 101);

	set("combat_exp", 3793300);

	set("chat_chance_combat", 20);
	

	set("str", 35);
	set("con", 33);
	set("int", 34);
	set("dex", 35);

	set_skill("feifeng_whip", 315);
	set_skill("whip", 315);
	set_skill("jinyu_quan", 315);
	set_skill("cuff", 315);
	set_skill("qingdie_shenfa", 315);
	set_skill("dodge", 315);
	set_skill("kurong_changong", 315);
	set_skill("force", 315);

	map_skill("whip", "feifeng_whip");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "qingdie_shenfa");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 182);
	set("apply/damage", 212);

	create_family("大理段家", 4, "弟子");

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