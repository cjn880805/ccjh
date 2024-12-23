//pub_zhaojunzhu.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_zhaojunzhu);

void create()
{
	set_name("ÕÔ¿¤Ö÷", "zhao junzhu");

	set("icon", 6);
	set("gender", "Å®ÐÔ");
	set("level", 157);
	set("age", 23);

	set("max_hp", 40000+random(20000));
	set("max_mp", 10000);
	set("mp", 20000);
	set("mp_factor", 80);

	set("combat_exp", 43000000);
	set("score", 6000);

	set("chat_chance_combat", 30);

	set("str", 52);
	set("con", 30);
	set("int", 30);
	set("dex", 38);
	set("per", 36);

	set_skill("fengyu_wuqingzhi", 359);
	set_skill("unarmed", 355);
	set_skill("xuantian_zhi", 359);
	set_skill("finger", 355);
	set_skill("parry", 360);
	set_skill("qiankun_danuoyi", 400);
	set_skill("dodge", 367);
	set_skill("xuantian_shengong", 369);
	set_skill("force", 392);
	set_skill("persuading", 416);

	map_skill("unarmed", "fengyu_wuqingzhi");
	map_skill("finger", "xuantian_zhi");
	map_skill("parry", "qiankun_danuoyi");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("force", "xuantian_shengong");

	prepare_skill("unarmed", "fengyu_wuqingzhi");
	prepare_skill("finger", "xuantian_zhi");

	set("apply/armor", 450);
	set("apply/damage", 100);

//	create_family("¹ÅÄ¹ÅÉ", 2, "ÆúÍ½");

//	carry_object("changjian")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(7))
	{
	case 0:
		perform_action("force roar", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}


NPC_END;
