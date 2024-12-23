//huahuatong.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_huahuatong);

virtual void create()
{

	set_name("华花同","hua hua tong");

	set("title", "红花会十四当家" );
	set("nickname",  "虎剑秀才" );
	set("long", "一个长身玉立，眉清目秀，风流英俊的书生，但一看他眼神就知道他已经家破人亡，苦大仇深");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 27);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man5);
	
	set("max_hp", 9000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 150);
	set_skill("yunlong_xinfa", 200);
	set_skill("yunlong_shengong", 200);
	set_skill("wuhuduanmendao", 150);
	set_skill("yunlong_jian", 200);

	set_skill("yunlong_shenfa", 150);
	set_skill("yunlong_bian", 150);
	set_skill("yunlong_shou", 150);
	set_skill("yunlong_zhua", 150);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhuduanmendao");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	set("env/wimpy", 20);
	create_family("武当派", 18, "弟子");

	carry_object("jinduan")->wear();
	carry_object("yaodai")->wear();
	carry_object("changjian")->wield();

}

NPC_END;