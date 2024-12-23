//dy4_dongming.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy4_dongming);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	set_name("董冥", "gueimen_dongming");

	set("icon", old_man2);
	set("gender", "男性");
	set("level", 92);

	set("max_hp", 18400);
	set("max_mp", 4600);
	set("mp_factor", 102);

	set("combat_exp", 3930400);

	set("chat_chance_combat", 20);
	

	set("str", 30);
	set("con", 33);
	set("int", 33);
	set("dex", 48);

	set_skill("jinyu_quan", 318);
	set_skill("cuff", 318);
	set_skill("wuluo_zhang", 318);
	set_skill("strike", 318);
	set_skill("qingdie_shenfa", 318);
	set_skill("dodge", 318);
	set_skill("kurong_changong", 318);
	set_skill("force", 318);

	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("dodge", "qingdie_shenfa");
	map_skill("force", "kurong_changong");

	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

	set("apply/armor", 184);
	set("apply/damage", 214);

	create_family("大理段家", 2, "弟子");


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