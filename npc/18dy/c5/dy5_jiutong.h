//dy5_jiutong.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy5_jiutong);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	set_name("��ͯ", "dy5_jiutong");

	set("icon", young_man1);
	set("gender", "����");
	set("level", 107);

	set("max_hp", 21400);
	set("max_mp", 5350);
	set("mp_factor", 117);

	set("combat_exp", 6400000);

	set("chat_chance_combat", 20);
	

	set("str", 39);
	set("con", 35);
	set("int", 44);
	set("dex", 40);

	set_skill("dagou_bang", 371);
	set_skill("staff", 371);
	set_skill("xianglong_zhang", 371);
	set_skill("strike", 371);
	set_skill("xiaoyaoyou", 371);
	set_skill("dodge", 371);
	set_skill("huntian_qigong", 371);
	set_skill("force", 371);

	map_skill("staff", "dagou_bang");
	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 214);
	set("apply/damage", 244);

	create_family("ؤ��", 4, "����");

	carry_object("shuzhi2")->wield();

}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("staff zhuang", 1);
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