//wukueilai.h
//code by zwb
//12-25

NPC_BEGIN(CNHongHua_wukueilai);

virtual void create()
{

	set_name("武魁来","wu kuei lai");

	set("title", "红花会四当家" );
	set("nickname",  "飞虹手" );
	set("long", "武魁来号称“飞虹手”，十五岁起浪荡江湖，铁爪下不知抓死过多少神奸巨憝、凶徒恶霸。");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 32);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 24);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man5);
	
	set("max_hp", 6000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	set("combat_exp", 700000);

	set_skill("literate", 100);
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand", 150);
	set_skill("claw", 150);
	set_skill("yunlong_shengong", 150);
	set_skill("yunlong_shenfa", 150);
	set_skill("yunlong_shou", 150);
	set_skill("yunlong_zhua", 150);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	set("env/wimpy", 20);

	carry_object("cloth")->wear();
}

NPC_END;