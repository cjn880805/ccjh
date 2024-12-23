//dy4_sunhao.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_sunhao);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("孙浩", "gueimen_sunhao");

	set("icon", young_man1);
	set("gender", "男性");
	set("level", 98);

	set("max_hp", 19600);
	set("max_mp", 4900);
	set("mp_factor", 108);

	set("combat_exp", 4822800);

	set("chat_chance_combat", 20);
	

	set("str", 51);
	set("con", 48);
	set("int", 39);
	set("dex", 44);

	set_skill("jinyu_quan", 339);
	set_skill("cuff", 339);
	set_skill("wuluo_zhang", 339);
	set_skill("strike", 339);
	set_skill("qingdie_shenfa", 339);
	set_skill("dodge", 339);
	set_skill("kurong_changong", 339);
	set_skill("force", 339);

	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("dodge", "qingdie_shenfa");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

	set("apply/armor", 196);
	set("apply/damage", 226);

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