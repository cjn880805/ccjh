//xinjian.h
//code by zwb
//12-25

NPC_BEGIN(CNHongHua_xinjian);

virtual void create()
{

	set_name("心剑","xin jian");

	set("title", "红花会书僮" );
	set("long","他是红花会总舵主陈居阳的贴身书僮。");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 15);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man6);
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 100000);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("whip", 60);
	set_skill("claw", 60);
	set_skill("hand", 60);
	set_skill("yunlong_shengong", 60);
	set_skill("yunlong_bian", 60);
	set_skill("yunlong_jian", 60);
	set_skill("yunlong_shenfa", 50);
	set_skill("yunlong_shou", 50);
	set_skill("yunlong_zhua", 50);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_bian");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	set("env/wimpy", 60);

	carry_object("cloth")->wear();
	carry_object("changbian")->wield();
}

NPC_END;