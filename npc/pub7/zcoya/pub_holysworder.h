//pub_holysworder.h
//zcoya 2002-07-21

NPC_BEGIN(CNpub_holysworder);

void create()
{
	set_name("°×ÇïÓð", "bai qiuyu");

	set("title", "½£Ê¥");

	set("icon", young_man2);
	set("gender", "ÄÐÐÔ");
	set("level", 157);
	set("age", 28);

	set("max_hp", 50000);
	set("mp", 10000);
	set("max_mp", 10000);
	set("mp_factor", 1);

	set("combat_exp", 80000000);
	set("score", 6000);

	set("chat_chance_combat", 50);

	set("str", 35);
	set("con", 35);
	set("int", 30);
	set("dex", 50);
	set("per", 50);

	set_skill("doomsword", 400);
	set_skill("sword", 400);
	set_skill("jiuyin_zhua", 359);
	set_skill("unarmed", 365);
	set_skill("hunyuan_zhang", 350);
	set_skill("strike", 352);
	set_skill("poyu_quan", 350);
	set_skill("cuff", 351);
	set_skill("yunv_swords", 400);
	set_skill("parry", 203);
	set_skill("pixie_jian", 400);
	set_skill("dodge", 357);
	set_skill("zixia_shengong", 351);
	set_skill("force", 355);


	map_skill("sword", "doomsword");
	map_skill("unarmed", "jiuyin_zhua");
	map_skill("strike", "hunyuan_zhang");
	map_skill("cuff", "poyu_quan");
	map_skill("parry", "yunv_swords");
	map_skill("dodge", "pixie_jian");
	map_skill("force", "zixia_shengong");


	prepare_skill("strike", "hunyuan_zhang");
	prepare_skill("cuff", "poyu_quan");

	set("apply/armor", 302);
	set("apply/damage", 180);

//	create_family("°×ÍÕÉ½ÅÉ", 5, "µÜ×Ó");

	carry_object("sword_1")->wield();

}


virtual char * chat_msg_combat()
{
	switch(random(7))
	{
	case 0:
		perform_action("sword zhuang", 1);
		break;
	case 1:
		perform_action("unarmed zhua", 1);
		break;
	case 2:
		perform_action("strike wuji", 1);
		break;
	case 3:
		perform_action("cuff leidong", 0);
		break;
	case 4:
		perform_action("parry wushuang", 1);
		break;
	case 5:
		perform_action("force powerup", 0);
		break;
	case 6:
		perform_action("force recover",0);
		break;

	}

	return 0;
}


NPC_END;
