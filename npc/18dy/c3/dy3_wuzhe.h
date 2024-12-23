//dy3_wuzhe.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_wuzhe);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("ÎäÕß", "naihe_wuzhe");

	set("icon", young_man2);
	set("gender", "ÄÐÐÔ");
	set("level", 89);

	set("max_hp", 17800);
	set("max_mp", 4450);
	set("mp_factor", 99);

	set("combat_exp", 3528700);

	set("chat_chance_combat", 20);
	

	set("str", 36);
	set("con", 37);
	set("int", 48);
	set("dex", 29);

	set_skill("huifeng_qijue", 308);
	set_skill("sword", 308);
	set_skill("jiuyin_zhua", 308);
	set_skill("claw", 308);
	set_skill("zhutian_bu", 308);
	set_skill("dodge", 308);
	set_skill("linji_zhuang", 308);
	set_skill("force", 308);

	map_skill("sword", "huifeng_qijue");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 178);
	set("apply/damage", 208);

	create_family("¶ëáÒÅÉ", 4, "µÜ×Ó");

	carry_object("mujian")->wield();

}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("sword mixhit", 1);
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