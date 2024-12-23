// fengxifan.c
//sound 2001-07-18

NPC_BEGIN(CNguanwai_fengxifan);

virtual void create()
{
	set_name("冯铁范", "feng xifan");
	set("nickname", "一剑无血");
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 45);
	set("long", "冯铁范是延平王府卫队长，武夷派第一高手，一张白湛湛的面皮。");
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("icon",young_man5);	
	
	set("mp", 2400);
	set("max_mp", 2400);
	set("mp_factor", 30);
	set("hp",2000);
	set("max_hp",2000);
	set("hp",2000);
	
	set("combat_exp", 1000000);
	set("shen_type", -1);
//	set("apprentice_available", 3);
	
	set_skill("unarmed", 180);
	set_skill("sword", 160);
	set_skill("force", 160);
	set_skill("parry", 160);
	set_skill("dodge", 160);
	set_skill("literate", 100);
	set_skill("huashan_sword", 180);
	set_skill("kuangfeng_jian", 180);
	set_skill("zixia_shengong", 160);
	set_skill("poyu_quan", 170);
	set_skill("hunyuan_zhang", 170);
	set_skill("huashan_shenfa", 170);
	
	map_skill("sword", "kuangfeng_jian");
	map_skill("parry", "kuangfeng_jian");
	map_skill("force", "zixia_shengong");
	map_skill("unarmed", "hunyuan_zhang");
	map_skill("dodge", "huashan_shenfa");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}
NPC_END;