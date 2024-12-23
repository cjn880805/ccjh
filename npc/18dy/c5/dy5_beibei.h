//dy5_beibei.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_beibei);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("����", "dy5_beibei");

	set("icon", young_man2);
	set("gender", "����");
	set("level", 105);

	set("max_hp", 21000);
	set("max_mp", 5250);
	set("mp_factor", 115);

	set("combat_exp", 6023600);

	set("chat_chance_combat", 20);
	

	set("str", 42);
	set("con", 50);
	set("int", 53);
	set("dex", 51);

	set_skill("xianglong_zhang", 364);
	set_skill("strike", 364);
	set_skill("xiaoyaoyou", 364);
	set_skill("dodge", 364);
	set_skill("huntian_qigong", 364);
	set_skill("force", 364);

	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 210);
	set("apply/damage", 240);

	create_family("ؤ��", 2, "����");


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