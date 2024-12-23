// yuzhenzi.c
//sound 2001-07-18

NPC_BEGIN(CNguanwai_yuzhenzi);

virtual void create()
{
	set_name("玉阳子", "yuzhen zi");
	set("gender", "男性");
	set("title", "铁剑门掌门人");
	set("nickname", "护国真人");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("icon",taoist_with_sword);	
	set("long", 
		"这是一位颇有仙风道骨的潇洒全真，手握长剑，目视前方。\n"
		"他就是木藤道人的师弟，在西藏寻得本门铁剑，成为本门掌门，"
		"尽管如此，他的行止确十分不端。\n");
	set("combat_exp", 900000);
	set("score", 10000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("hp", 1000);
	set("max_hp", 1000);
	set("hp", 3000);
	set("max_hp", 3000);

	set_skill("sword", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("huashan_sword", 150);
	set_skill("shenxing_baibian", 150);
	map_skill("sword",  "huashan_sword");
	map_skill("parry", "huashan_sword");
	map_skill("dodge", "shenxing_baibian");

	set("mp", 1500); 
	set("max_mp", 1500);
	set("mp_factor", 100);

	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	add_money(2000);
}

NPC_END;
