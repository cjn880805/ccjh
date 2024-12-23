//pub_beggarking.h
//zcoya 2002-07-23

NPC_BEGIN(CNpub_beggarking);

void create()
{
	set_name("黔之农", "qianzhinong");

	set("title", "丐王");

	set("icon", young_man1);
	set("gender", "男性");
	set("level", 157);
	set("age", 35);

	set("max_hp", 35000);
	set("max_mp", 13000);
	set("mp", 13000);
	set("mp_factor", 130);

	set("combat_exp", 73000000);
	set("score", 6000);

	set("chat_chance_combat", 30);

	set("str", 50);
	set("con", 33);
	set("int", 20);
	set("dex", 30);
	set("per", 26);

	set_skill("dagou_bang", 400);
	set_skill("staff", 400);
	set_skill("xianglong_zhang", 350);
	set_skill("unarmed", 350);
	set_skill("huagu_mianzhang", 332);
	set_skill("strike", 344);
	set_skill("shaolin_shenfa", 328);
	set_skill("dodge", 300);
	set_skill("huntian_qigong", 323);
	set_skill("yijinjing", 281);
	set_skill("force", 342);
	set_skill("shedao_qigong", 333);
	set_skill("parry", 300);

	map_skill("staff", "dagou_bang");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("force", "huntian_qigong");

	prepare_skill("unarmed", "xianglong_zhang");
	prepare_skill("strike", "huagu_mianzhang");

	set("apply/armor", 300);
	set("apply/damage", 100);

//	create_family("白驼山派", 5, "弟子");

	carry_object("gangzhang")->wield();

}

virtual char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("staff zhuang", 1);
		break;
	case 1:
		perform_action("unarmed leiting", 1);
		break;
	case 2:
		perform_action("force powerup", 0);
		break;
	case 3:
		perform_action("parry chang3", 1);
		break;
	case 4:
		perform_action("force shengang", 0);
		break;
	case 5:
		perform_action("force recover", 0);
		break;
	case 6:
		perform_action("unarmed xianglong", 1);
		break;
	case 7:
		perform_action("strike hua", 1);
		break;
	case 8:
		perform_action("parry chang", 1);
		break;
	case 9:
		perform_action("parry chang3", 1);
		break;
	}

	return 0;
}

NPC_END;