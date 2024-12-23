//pub_jinshezunzhe.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_jinshezunzhe);

void create()
{
	set_name("金蛇尊者", "jinshezunzhe");

//	set("title", "影·大剑师");

	set("icon", 17);
	set("gender", "男性");
	set("level", 157);
	set("age", 35);

	set("max_hp", 30000+random(10000));
	set("max_mp", 10000);
	set("mp", 10000);
	set("mp_factor", 55);

	set("combat_exp", 52000000);
	set("score", 6000);

	set("chat_chance_combat", 40);

	set("str", 50);
	set("con", 30);
	set("int", 30);
	set("dex", 38);
	set("per", 27);

	set_skill("jinshe_jian", 350);
	set_skill("sword", 350);
	set_skill("kongming_quan", 349);
	set_skill("unarmed", 315);
	set_skill("jinshe_zhang", 360);
	set_skill("strike", 362);
	set_skill("shedao_qigong", 333);
	set_skill("parry", 310);
	set_skill("xianyun_bufa", 358);
	set_skill("dodge", 354);
	set_skill("seaforce", 399);
	set_skill("force", 366);


	map_skill("sword", "jinshe_jian");
	map_skill("unarmed", "kongming_quan");
	map_skill("strike", "jinshe_zhang");
	map_skill("parry", "shedao_qigong");
	map_skill("dodge", "xianyun_bufa");
	map_skill("force", "seaforce");


	prepare_skill("unarmed", "kongming_quan");

	set("apply/armor", 450);
	set("apply/damage", 105);

//	create_family("古墓派", 2, "弃徒");

	carry_object("sword_2")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("force flood", 1);
		break;
	case 1:
		perform_action("strike fugu", 1);
		break;
	case 2:
		perform_action("parry chang1", 1);
		break;
	case 3:
		perform_action("parry chang3", 1);
		break;
	}

	return 0;
}


NPC_END;
