//zhangjin.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_zhangjin);

virtual void create()
{

	set_name("张进","zhang jin");

	set("title",  "红花会十当家" );
	set("nickname",  "石敢当" );
	set("long", "他是个驼子，千万不要在他面前提驼字。");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 12);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man5);
	
	set("max_hp", 3600);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 120000);

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("staff", 70);
	set_skill("hand", 70);
	set_skill("claw", 70);
	set_skill("yunlong_shengong", 70);
	set_skill("wuchang_zhang", 70);
	set_skill("yunlong_shenfa", 70);
	set_skill("yunlong_shou", 70);
	set_skill("yunlong_zhua", 70);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("staff", "wuchang_zhang");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "wuchang_zhang");
	map_skill("claw", "yunlong_zhua");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	set("env/wimpy", 20);

	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();

}

NPC_END;