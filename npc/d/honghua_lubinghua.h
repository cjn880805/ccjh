//lubinghua.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_lubinghua);

virtual void create()
{

	set_name("鲁冰花","lu bing hua");

	set("title", "红花会十一当家" );
	set("nickname",  "鸳鸯刀" );
	set("long","她是一个秀美的少妇。一手短刀，一手握着一柄长刀。");
	set("gender", "女性");
	set("class", "fighter");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 28);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_woman4);
	
	set("max_hp", 5200);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 150000);

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
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	set("env/wimpy", 20);

	carry_object("jinduan")->wear();
	carry_object("gangdao")->wield();
}


NPC_END;