//dy5_wuyuan.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_wuyuan);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("��Ԫ", "dy5_wuyuan");

	set("icon", young_woman3);
	set("gender", "Ů��");
	set("level", 102);

	set("max_hp", 20400);
	set("max_mp", 5100);
	set("mp_factor", 112);

	set("combat_exp", 5487200);

	set("chat_chance_combat", 20);
	

	set("str", 53);
	set("con", 42);
	set("int", 43);
	set("dex", 51);

	set_skill("xianglong_zhang", 353);
	set_skill("strike", 353);
	set_skill("xiaoyaoyou", 353);
	set_skill("dodge", 353);
	set_skill("huntian_qigong", 353);
	set_skill("force", 353);

	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 204);
	set("apply/damage", 234);

	create_family("ؤ��", 3, "����");


}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("strike leiting", 1);
		break;
	case 1:
		perform_action("force poweruop", 1);
		break;
	case 2:
		perform_action("force shengang", 1);
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