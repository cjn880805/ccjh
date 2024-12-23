//dy3_yuanxiaoqi.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_yuanxiaoqi);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("元小七", "naihe_yuanxiaoqi");

	set("icon", young_man2);
	set("gender", "男性");
	set("level", 81);

	set("max_hp", 16200);
	set("max_mp", 4050);
	set("mp_factor", 91);

	set("combat_exp", 2593400);

	set("chat_chance_combat", 20);
	

	set("str", 32);
	set("con", 35);
	set("int", 29);
	set("dex", 29);

	set_skill("jiuyin_zhua", 280);
	set_skill("claw", 280);
	set_skill("zhutian_bu", 280);
	set_skill("dodge", 280);
	set_skill("linji_zhuang", 280);
	set_skill("force", 280);

	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 162);
	set("apply/damage", 192);

	create_family("峨嵋派", 5, "弟子");


}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("claw zhua", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
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