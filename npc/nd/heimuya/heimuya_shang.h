//heimuya_shang 桑三娘
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_shang);

virtual void create()
{
	set_name("桑四嫂", "shang sanniang");
	set("gender", "女性" );
	set("age", 45);
	set("title", "日月神教天香堂长老");
	set("long", "身情古怪，面无丝毫微笑，面容却相当清秀。");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 24);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);
 	set("icon",young_woman12);

	set("max_hp", 1000);
	set("hp",1000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("combat_exp", 350000);
	set("score", 30000);
	set("mp_factor", 200);
	set_skill("force", 140);
	set_skill("dodge", 130);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("taiji_shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji_jian", 100);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	
	map_skill("parry", "taiji_jian");
	map_skill("blade", "taiji_jian");
	create_family("日月神教",2,"弟子 天香堂长老");

	set("chat_chance", 3);
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}

NPC_END;
