//xudixuan.h
//code by zwb
//12-25

NPC_BEGIN(CNHongHua_xudixuan);

virtual void create()
{

	set_name("徐地玄","xu di xuan");

	set("title", "红花会七当家" );
	set("nickname",  "智温侯" );
	set("long","其人身材异常魁梧，却足智多谋，是红花会的智囊军师，武功也颇不弱，冷静持重。");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 19);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man3);
	
	set("max_hp", 5400);
	set("mp", 1100);
	set("max_mp", 1100);
	set("mp_factor", 100);
	set("combat_exp", 350000);

	set_skill("literate", 100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("blade", 100);
	set_skill("hand", 100);
	set_skill("claw", 100);
	set_skill("yunlong_shengong", 100);
	set_skill("wuhuduanmendao", 100);
	set_skill("yunlong_shenfa", 100);
	set_skill("yunlong_shou", 100);
	set_skill("yunlong_zhua", 100);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("blade", "wuhuduanmendao");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "wuhuduanmendao");
	map_skill("claw", "yunlong_zhua");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 20);

	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();
}

NPC_END;