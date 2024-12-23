// laodenuo.c
//code by sound
//date:2001-07-19

NPC_BEGIN(CNhuashan_laodenuo);

virtual void create()
{
	set("icon",old_man1);
	set_name("劳德伪", "lao denuo");
	set("nickname", "老好人");
	set("gender", "男性");
	set("age", 61);
	set("long", "劳德伪是岳不群的二弟子。");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("mp", 500);
	set("max_mp", 500);
	
	set("combat_exp", 50000);
	set("shen_type", -1);
	set("score", 20000);
/*
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
*/
	set_skill("unarmed", 60);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("literate", 40);
	
	set_skill("huashan_sword", 60);
	set_skill("zixia_shengong", 60);
//	set_skill("hunyuan_zhang", 60);
	set_skill("feiyan_huixiang", 60);
	
	map_skill("sword", "huashan_sword");
	map_skill("parry", "huashan_sword");
	map_skill("force", "zixia_shengong");
//	map_skill("unarmed", "hunyuan_zhang");
	map_skill("dodge", "feiyan_huixiang");
	
	create_family("华山派", 14, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}

NPC_END;