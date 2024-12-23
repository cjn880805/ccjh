// shaolin_shi.c 木一雄

//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNshaolin_shi);

virtual void create()
{
	set_name("木一雄",  "shi shuangying");
	set("title",  "红花会十二当家" );
	set("nickname",  "鬼见愁" );
	set("long", "鬼见愁木一雄在会中坐第十二把交椅，执掌刑堂，铁面无私，心狠手辣，犯了规条的就是逃到天涯海角，他也必派人抓来处刑，是以红花会数万兄弟，提到鬼见愁时无不悚然。");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 26);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
        set("icon",young_man4);
	
	set("max_hp", 4500);
	set("hp", 1500);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 200000);
	
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("unarmed", 90);
	set_skill("parry", 90);
	set_skill("sword", 90);
	set_skill("taiji_quan", 95);
	set_skill("taiji_shengong", 90);
	set_skill("taiji_jian", 90);
	set_skill("tiyunzong", 90);
	
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji_shengong");
	map_skill("unarmed", "tianji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
	set("env/wimpy", 20);
	create_family("太极门",8, "弟子");
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}

NPC_END;