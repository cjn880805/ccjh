//shouyuan.h
//code by zwb
//12-16

NPC_BEGIN(CNwudang_shouyuan);

virtual void create()
{
	set_name("守园道长","shouyuan daozhang");
	set("long","他是武当山的守园道长。");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("icon",taoist);	
	set("foolid",137);
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_hp", 600);
	set("mp", 300);
	set("max_mp", 300);

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("taiji_dao", 25);
	set_skill("taoism", 20);

	set_skill("blade", 40);
	set_skill("taiji_dao", 25);
	map_skill("blade", "taiji_dao");
	create_family("武当派", 4, "弟子");

	carry_object("gangdao")->wield();
}

NPC_END;