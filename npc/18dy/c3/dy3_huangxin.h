//dy3_huangxin.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_huangxin);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("»ÆÐÂ", "naihe_huangxin");

	set("icon", taoist_with_sword);
	set("gender", "ÄÐÐÔ");
	set("level", 87);

	set("max_hp", 17400);
	set("max_mp", 4350);
	set("mp_factor", 97);

	set("combat_exp", 3276800);

	set("chat_chance_combat", 20);
	

	set("str", 45);
	set("con", 41);
	set("int", 44);
	set("dex", 44);

	set_skill("yanxing_dao", 301);
	set_skill("blade", 301);
	set_skill("jiuyin_zhua", 301);
	set_skill("claw", 301);
	set_skill("zhutian_bu", 301);
	set_skill("dodge", 301);
	set_skill("linji_zhuang", 301);
	set_skill("force", 301);

	map_skill("blade", "yanxing_dao");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 174);
	set("apply/damage", 204);

	create_family("¶ëáÒÅÉ", 3, "µÜ×Ó");

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