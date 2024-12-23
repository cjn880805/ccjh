// wudang_maliu.c 马六

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_maliu);

virtual void create()
{
	set_name("王斌","ma liu");
	set("long","他大约二十多岁，精明能干，总是阴沉着脸。但却嫉恶如仇，性如烈火。 ");
	set("gender", "男性");
	set("age", 25);
        set("icon",young_man2);

	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 35);
	set("con", 27);
	set("dex", 28);
	
	set_inquiry("here","这里当然就是侠客岛啦");
	set_inquiry("侠客行","往南面走，进山后就明白了");
	set_inquiry("腊八粥"," 去找龙岛主看看你的缘分吧。 ");

	set("max_hp", 6000);
	set("hp", 2000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 100);
	set("combat_exp", 3000000);
	set("score", 60000);
	
	set_skill("force", 150);
	set_skill("taiji_shengong", 150);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 150);
	set_skill("taiji_quan", 200);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("taiji_jian", 200);
	set_skill("taoism", 100);
	set_skill("literate", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
	create_family("侠客岛", 2, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("white_robe")->wear();
}

NPC_END;