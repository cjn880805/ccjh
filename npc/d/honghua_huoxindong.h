//huoxindong.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_huoxindong);

virtual void create()
{

	set_name("霍星东","huo xin dong");

	set("long", "这女郎看来来自回疆，美貌如花，英气逼人，头上插着一根翠绿的羽毛，身穿黄衣。");
	set("nickname", "翠羽黄衫");
	set("gender", "女性");
	set("class", "swordsman");
	set("age", 18);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man2);
	
	set("max_hp", 6000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 600000);

	set_skill("literate", 120);
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("hand", 120);
	set_skill("claw", 120);
	set_skill("yunlong_xinfa", 120);
	set_skill("yunlong_shengong", 120);
	set_skill("yunlong_jian", 120);
	set_skill("yunlong_shenfa", 120);
	set_skill("yunlong_shou", 120);
	set_skill("yunlong_zhua", 120);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	set("env/wimpy", 60);
	set_temp("is_riding", "青骢马");
	set("env/wimpy", 40);

	carry_object("cuiyu")->wear();
	carry_object("huangshan")->wear();
	carry_object("shortsword")->wield();
//	carry_object("horse");
}

NPC_END;