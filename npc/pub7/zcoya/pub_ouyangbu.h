//pub_ouyangbu.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_ouyangbu);

void create()
{
	set_name("Å·Ñô²»³Ô¿÷", "ouyang");

	set("title", "ÄþËÀ²»³Ô¿÷");

	set("icon", 17);
	set("gender", "ÄÐÐÔ");
	set("level", 157);
	set("age", 35);
	set("shen_type", -1);

	set("max_hp", 25000+random(20000));
	set("max_mp", 10000);
	set("mp", 20000);
	set("mp_factor", 80);

	set("combat_exp", 42000000+random(10000000));
	set("score", 6000);

	set("chat_chance_combat", 40);

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 48);
	set("per", 16);

	set_skill("smithsword", 370);
	set_skill("sword", 360);
	set_skill("anranxiaohun_zhang", 359);
	set_skill("unarmed", 355);
	set_skill("meinv_quan", 349);
	set_skill("parry", 350);
	set_skill("xianyun_bufa", 358);
	set_skill("dodge", 354);
	set_skill("yunv_xinjing", 400);
	set_skill("yunv_xinfa", 400);
	set_skill("seaforce", 400);
	set_skill("force", 366);
	set_skill("tianluo_diwang", 376);


	map_skill("sword", "smithsword");
	map_skill("unarmed", "anranxiaohun_zhang");
	map_skill("parry", "meinv_quan");
	map_skill("dodge", "xianyun_bufa");
	map_skill("force", "seaforce");


	prepare_skill("unarmed", "anranxiaohun_zhang");

	set("apply/armor", 450);
	set("apply/damage", 100);

//	create_family("¹ÅÄ¹ÅÉ", 2, "ÆúÍ½");

	carry_object("changjian")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 0:
		perform_action("sword flood", 1);
		break;
	case 1:
		perform_action("force flood", 1);
		break;
	case 2:
		perform_action("parry you", 1);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	case 4:
		perform_action("force flood", 1);
		break;
	}

	return 0;
}


NPC_END;
