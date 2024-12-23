//pub_tuguaiguai.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_tuguaiguai);

void create()
{
	set_name("ÍÀ¹Ô¹Ô", "tu guaiguai");

	set("title", "²»ÄÐ²»Å®");

	set("icon", 4);
	set("gender", "ÎÞÐÔ");
	set("level", 157);
	set("age", 25);
	set("shen_type", -1);

	set("max_hp", 40000+random(10000));
	set("max_mp", 10000);
	set("mp", 20000);
	set("mp_factor", 70);

	set("combat_exp", 46000000+random(20000000));
	set("score", 6000);

	set("chat_chance_combat", 40);

	set("str", 35);
	set("con", 30);
	set("int", 30);
	set("dex", 40);
	set("per", 22);

	set_skill("pixie_jian", 388);
	set_skill("sword", 350);
	set_skill("fengyu_wuqingzhi", 349);
	set_skill("unarmed", 355);
	set_skill("meinv_quan", 349);
	set_skill("parry", 340);
	set_skill("xianyun_bufa", 358);
	set_skill("dodge", 364);
	set_skill("kuihua_xinfa", 350);
	set_skill("force", 366);


	map_skill("sword", "pixie_jian");
	map_skill("unarmed", "fengyu_wuqingzhi");
	map_skill("parry", "pixie_jian");
	map_skill("dodge", "pixie_jian");
	map_skill("force", "kuihua_xinfa");

	prepare_skill("unarmed", "fengyu_wuqingzhi");

	set("apply/armor", 450);
	set("apply/damage", 60);

//	create_family("ÐÇËÞÅÉ", 2, "ÆúÍ½");

	carry_object("changjian")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("sword cimu", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	}

	return 0;
}


NPC_END;
