//dy3_weidingguo.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy3_weidingguo);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	set_name("κ����", "naihe_weidingguo");

	set("icon", general);
	set("gender", "����");
	set("level", 86);

	set("max_hp", 17200);
	set("max_mp", 4300);
	set("mp_factor", 96);

	set("combat_exp", 3155400);

	set("chat_chance_combat", 20);
	

	set("str", 39);
	set("con", 45);
	set("int", 31);
	set("dex", 44);

	set_skill("jiuyin_zhua", 297);
	set_skill("claw", 297);
	set_skill("zhutian_bu", 297);
	set_skill("dodge", 297);
	set_skill("linji_zhuang", 297);
	set_skill("force", 297);

	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 172);
	set("apply/damage", 202);

	create_family("������", 6, "����");


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