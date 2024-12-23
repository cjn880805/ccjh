//pub_yuanziyi.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_yuanziyi);

void create()
{
	set_name("Ô¬×ÏÒÀ", "yuan ziyi");

	set("icon", 2);
	set("gender", "Å®ÐÔ");
	set("level", 157);
	set("age", 23);

	set("max_hp", 40000);
	set("max_mp", 8000);
	set("mp", 14000);
	set("mp_factor", 1);

	set("combat_exp", 43000000);
	set("score", 6000);

	set("chat_chance_combat", 30);

	set("str", 35);
	set("con", 30);
	set("int", 30);
	set("dex", 35);
	set("per", 40);

	set_skill("huifeng_qijue", 351);
	set_skill("sword", 351);
	set_skill("jinding_zhang", 349);
	set_skill("unarmed", 365);
	set_skill("jiuyin_zhua", 350);
	set_skill("claw", 352);
	set_skill("tiangang_zhi", 369);
	set_skill("parry", 310);
	set_skill("zhutian_bu", 360);
	set_skill("dodge", 357);
	set_skill("linji_zhuang", 339);
	set_skill("force", 292);
	set_skill("persuading", 416);


	map_skill("sword", "huifeng_qijue");
	map_skill("unarmed", "jinding_zhang");
	map_skill("claw", "jiuyin_zhuag");
	map_skill("parry", "tiangang_zhi");
	map_skill("dodge", "lzhutian_bu");
	map_skill("force", "linji_zhuang");


	prepare_skill("unarmed", "jinding_zhang");
	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 450);
	set("apply/damage", 10);

//	create_family("¹ÅÄ¹ÅÉ", 2, "ÆúÍ½");

	carry_object("changjian")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(7))
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
		perform_action("parry lingkong", 1);
		break;
	case 4:
		perform_action("parry lingkong", 1);
		break;
	case 5:
		perform_action("unarmed bashi", 1);
		break;
	case 6:
		perform_action("claw zhua", 1);
		break;
	}

	return 0;
}


NPC_END;
