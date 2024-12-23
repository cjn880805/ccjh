// yuelingshan.c
//code by sound
//date:2001-07-19

NPC_BEGIN(CNhuashan_yuelingshan);

virtual void create()
{
	set("icon",young_woman1);
	set_name("岳林珊", "yue lingshan");
	set("nickname", "小师妹");
	set("gender", "女性" );
	set("age", 17);
	set("per", 29);
	set("str", 16);
	set("con", 24);
	set("dex", 30);
	set("int", 27);
	
	set("attitude", "friendly");
	
	set("hp",800);
	set("max_hp",800);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 80);
	set("combat_exp", 100000);
	
	set("long", "岳林珊是华山派掌门岳不群的独生女儿。");
	
	create_family("华山派", 14, "弟子");
	
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("force", 60);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("literate", 70);
	
	set_skill("huashan_sword", 50);
	set_skill("yunv_swords", 80);
	set_skill("hunyuan_zhang", 50);
	set_skill("feiyan_huixiang", 50);
	
	map_skill("sword", "yunv_swords");
	map_skill("parry", "yunv_swords");
	map_skill("force", "zixia_shengong");
	map_skill("unarmed", "hunyuan_zhang");
	map_skill("dodge", "feiyan_huixiang");
	
//	carry_object("green_water_sword")->wield();
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	
}
/*
int accept_fight(object me)
{
	command("say 小女子怎会是你的对手?");
	return 0;
}
*/
NPC_END;