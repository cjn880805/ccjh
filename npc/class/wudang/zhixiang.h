//zhixiang.h
//code by zwb
//12-16
//inherit F_UNIQUE;
//inherit F_MASTER;

NPC_BEGIN(CNwudang_zhixiang);

virtual void create()
{

	set_name("制香道长","zhixiang daozhang");
	set("long","他是武当山的制香道长, 兼在这里出售香烛。");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("icon",taoist);	
	set("foolid",134);
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_hp", 900);
	set("mp", 300);
	set("max_mp", 300);

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("taiji_jian", 20);
	set_skill("taoism", 20);

	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");

	create_family("武当派", 4, "弟子");

	carry_object("changjian")->wield();
}

NPC_END;