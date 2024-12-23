//pub_chenlingsu.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_chenlingsu);

void create()
{
	set_name("³ÂÁéËØ", "chen lingsu");

	set("icon", 7);
	set("gender", "Å®ÐÔ");
	set("level", 157);
	set("age", 18);

	set("max_hp", 40000+random(10000));
	set("max_mp", 8000);
	set("mp", 16000);
	set("mp_factor", 100);

	set("combat_exp", 43000000);
	set("score", 6000);

	set("chat_chance_combat", 50);

	set("str", 35);
	set("con", 30);
	set("int", 30);
	set("dex", 35);
	set("per", 26);

	set_skill("luoying_shenzhang", 349);
	set_skill("strike", 365);
	set_skill("tanzhi_shentong", 350);
	set_skill("finger", 352);
	set_skill("xuanfeng_leg", 359);
	set_skill("unarmed", 365);
	set_skill("lanhua_shou", 350);
	set_skill("hand", 352);
	set_skill("jiuyin_zhua", 369);
	set_skill("parry", 310);
	set_skill("anying_fuxiang", 360);
	set_skill("dodge", 357);
	set_skill("bibo_shengong", 369);
	set_skill("force", 362);


	map_skill("strike", "luoying_shenzhang");
	map_skill("finger", "tanzhi_shentong");
	map_skill("unarmed", "xuanfeng_leg");
	map_skill("hand", "lanhua_shou");
	map_skill("parry", "jiuyin_zhua");
	map_skill("dodge", "anying_fuxiang");
	map_skill("force", "bibo_shengong");


	prepare_skill("unarmed", "xuanfeng_leg");
	prepare_skill("strike", "luoying_shenzhang");

	set("apply/armor", 450);
	set("apply/damage", 105);

//	create_family("¹ÅÄ¹ÅÉ", 2, "ÆúÍ½");

//	carry_object("changjian")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(8))
	{
	case 0:
		perform_action("strike xuan", 1);
		break;
	case 1:
		perform_action("finger hui", 1);
		break;
	case 2:
		perform_action("finger jinglei", 1);
		break;
	case 3:
		perform_action("unarmed kuangfeng", 1);
		break;
	case 4:
		perform_action("hand fuxue", 1);
		break;
	case 5:
		perform_action("parry zhua", 1);
		break;
	case 6:
		perform_action("force powerup", 0);
		break;
	case 7:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}


NPC_END;
