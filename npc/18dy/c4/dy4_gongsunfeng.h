//dy4_gongsunfeng.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_gongsunfeng);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("公孙凤", "gueimen_gongsunfeng");

	set("icon", young_woman3);
	set("gender", "女性");
	set("level", 94);

	set("max_hp", 18800);
	set("max_mp", 4700);
	set("mp_factor", 104);

	set("combat_exp", 4214400);

	set("chat_chance_combat", 20);
	

	set("str", 49);
	set("con", 40);
	set("int", 43);
	set("dex", 48);

	set_skill("jinyu_quan", 325);
	set_skill("cuff", 325);
	set_skill("wuluo_zhang", 325);
	set_skill("strike", 325);
	set_skill("qingdie_shenfa", 325);
	set_skill("dodge", 325);
	set_skill("kurong_changong", 325);
	set_skill("force", 325);

	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("dodge", "qingdie_shenfa");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

	set("apply/armor", 188);
	set("apply/damage", 218);

	create_family("大理段家", 4, "弟子");


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