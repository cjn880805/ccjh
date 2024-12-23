//dy4_zhangfei.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_zhangfei);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("张非", "gueimen_zhangfei");

	set("icon", young_man3);
	set("gender", "男性");
	set("level", 100);

	set("max_hp", 20000);
	set("max_mp", 5000);
	set("mp_factor", 110);

	set("combat_exp", 5147800);

	set("chat_chance_combat", 20);
	

	set("str", 52);
	set("con", 51);
	set("int", 33);
	set("dex", 41);

	set_skill("jinyu_quan", 346);
	set_skill("cuff", 346);
	set_skill("wuluo_zhang", 346);
	set_skill("strike", 346);
	set_skill("qingdie_shenfa", 346);
	set_skill("dodge", 346);
	set_skill("kurong_changong", 346);
	set_skill("force", 346);

	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("dodge", "qingdie_shenfa");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

	set("apply/armor", 200);
	set("apply/damage", 230);

	create_family("大理段家", 6, "弟子");


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