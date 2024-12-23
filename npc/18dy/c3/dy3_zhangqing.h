//dy3_zhangqing.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_zhangqing);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("张清", "naihe_zhangqing");

	set("icon", young_man4);
	set("gender", "男性");
	set("level", 81);

	set("max_hp", 16200);
	set("max_mp", 4050);
	set("mp_factor", 91);

	set("combat_exp", 2593400);

	set("chat_chance_combat", 20);
	

	set("str", 33);
	set("con", 40);
	set("int", 32);
	set("dex", 34);

	set_skill("yanxing_dao", 280);
	set_skill("blade", 280);
	set_skill("jiuyin_zhua", 280);
	set_skill("claw", 280);
	set_skill("zhutian_bu", 280);
	set_skill("dodge", 280);
	set_skill("linji_zhuang", 280);
	set_skill("force", 280);

	map_skill("blade", "yanxing_dao");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 162);
	set("apply/damage", 192);

	create_family("峨嵋派", 4, "弟子");

	carry_object("caidao")->wield();

}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("blade huanying", 1);
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