//xiaosong.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNwudang_xiaosong);

virtual void create()
{

	set_name("宋青史","song qingshu");
	set("long","他就是宋远桥的儿子宋青史。他今年二十岁，乃是武当第三代中出类拔萃的人物。");
	set("foolid",130);	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	
	set("str", 25);
	set("int", 28);
	set("con", 25);
	set("dex", 25);
	set("icon",young_man1);	
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_force", 30);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 60);
	set_skill("taiji_shengong", 40);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 40);
	set_skill("unarmed", 70);
//	set_skill("taiji-quan", 50);
	set_skill("parry", 70);
	set_skill("sword", 70);
	set_skill("taiji_jian", 50);
//	set_skill("taoism", 30);
//	set_skill("literate", 40);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
//	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");

	create_family("武当派", 3, "弟子");

	carry_object("changjian")->wield();
}


NPC_END;