//pub_swordmaster.h
//zcoya 2002-07-23

NPC_BEGIN(CNpub_swordmaster);

void create()
{
	set_name("京", "king");

	set("title", "大剑师");

	set("icon", young_woman1);
	set("gender", "女性");
	set("level", 157);
	set("age", 17);

	set("max_hp", 160000);
	set("max_mp", 2000);
	set("mp", 4000);
	set("mp_factor", 0l);

	set("combat_exp", 70000000);
	set("score", 6000);

	set("chat_chance_combat", 60);

	set("str", 42);
	set("con", 50);
	set("int", 30);
	set("dex", 25);
	set("per", 23);

	set_skill("vivien_sword", 299);
	set_skill("sword", 601);
	set_skill("fengyu_wuqingzhi", 359);
	set_skill("unarmed", 365);
	set_skill("jiuyin_zhua", 350);
	set_skill("claw", 352);
	set_skill("qiankun_danuoyi", 389);
	set_skill("parry", 410);
	set_skill("lingboweibu", 390);
	set_skill("dodge", 357);
	set_skill("beiming_shengong", 139);
	set_skill("force", 212);
	set_skill("taoism", 416);


	map_skill("sword", "vivien_sword");
	map_skill("unarmed", "fengyu_wuqingzhi");
	map_skill("claw", "jiuyin_zhuag");
	map_skill("parry", "qiankun_danuoyi");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");


	prepare_skill("unarmed", "fengyu_wuqingzhi");
	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 350);
	set("apply/damage", 555);

	create_family("古墓派", 2, "弃徒");

	carry_object("cyjian")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 0:
		perform_action("sword freeze", 1);
		break;
	case 1:
		perform_action("force shield", 0);
		break;
	case 2:
		perform_action("force maxsuck", 1);
		break;
	case 3:
		perform_action("force neilisuck", 1);
		break;
	case 4:
		perform_action("force neilisuck", 1);
		break;
	}

	return 0;
}


NPC_END;
