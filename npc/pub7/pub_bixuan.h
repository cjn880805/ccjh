//dy2_bixuan.h
//lanwood 2001-11-04

NPC_BEGIN(CNpub_bixuan);

void create()
{
	set_name("龙地北", "longdi bei");

	set("title", "佛山恶霸");

	set("icon", old_man2);
	set("gender", "男性");
	set("level", 157);
	set("age", 40);

	set("max_hp", 40000);
	set("max_mp", 10000);
	set("mp_factor", 80);

	set("combat_exp", 60000000);
	set("score", 6000);

	set("chat_chance_combat", 30);

	set("str", 42);
	set("con", 33);
	set("int", 35);
	set("dex", 43);

	set_skill("lingshe_zhangfa", 350);
	set_skill("staff", 350);
	set_skill("shexing_diaoshou", 350);
	set_skill("hand", 350);
	set_skill("chanchu_bufa", 350);
	set_skill("dodge", 350);
	set_skill("hamagong", 350);
	set_skill("force", 350);

	map_skill("staff", "lingshe_zhangfa");
	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 160);
	set("apply/damage", 30);

//	create_family("白驼山派", 5, "弟子");

	carry_object("shuzhi2")->wield();

}

virtual char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("staff pili", 1);
		break;
	case 1:
		perform_action("hand wugu", 1);
		break;
	case 2:
		perform_action("force powerup", 1);
		break;
	case 3:
		perform_action("force reserver", 1);
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

NPC_END;