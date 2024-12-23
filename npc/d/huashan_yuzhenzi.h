// huashan_yuzhenzi.c

//code by Fisho
//date:2000-12-21
//inherit F_UNIQUE;

NPC_BEGIN(CNhuashan_yuzhenzi);

virtual void create()
{
	set_name("遇真子", "yuzhen zi");
	set("gender", "男性");
	set("title", "铁剑门掌门人");
	set("nickname", "护国真人");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一位颇有仙风道骨的潇洒道士，手握长剑，目视前方。他就是木神道人的师弟，在西藏寻得本门古铜剑，成为掌门，尽管如此，他的行止确十分不端。");
	set("combat_exp", 900000);
	set("score", 10000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("hp", 3000);
	set("max_hp", 9000);
 	set("icon",young_man4);
	
	set_skill("sword", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("huashan_sword", 150);
//	set_skill("shenxing_baibian", 150);
	map_skill("whip",  "huashan_sword");
	map_skill("parry", "huashan_sword");
//	map_skill("dodge", "shenxing_baibian");
	
	set("mp", 1500); 
	set("max_mp", 1500);
	set("mp_factor", 100);
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	add_money( 2000);
}

NPC_END;