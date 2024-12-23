//qingxu.h
//code by zwb
//12-16

NPC_BEGIN(CNwudang_qingxu);

virtual void create()
{
	set_name("清虚道长", "qingxu daozhang");
	set("long","他就是俞莲舟的弟子清虚道长。他今年二十多岁，主管复真观的杂事。专门在这里看守本派的各种道经");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("foolid",125);	set("dex", 25);
	set("icon",taoist);	
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_force", 30);

	set("combat_exp", 70000);
	set("score", 8500);

	set_skill("force", 60);
	set_skill("taiji_shengong", 40);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 50);
	set_skill("unarmed", 60);
	set_skill("taiji_quan", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji_jian", 60);
	set_skill("taoism", 60);
  	set_skill("literate", 80);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");

	create_family("武当派", 3, "弟子");
	set("class", "taoist");

	set_inquiry("道德经",ask_me);
                                
	set("book_count", 1);
	carry_object("changjian")->wield();
}

static char * ask_me(CNpc * npc , CChar * player)
{
	CContainer * ob;
	if (DIFFERSTR(player->querystr("family/family_name"), "武当派"))
		return "你与本派素无来往，不知此话从何谈起？";
    if (npc->query("book_count") < 1)
		return "你来晚了，本派的道德真经不在此处。";
    npc->add("book_count", -1);
    ob = load_item("daodejing_ii");
    ob->move(player);
    return "好吧，这本「道德经」你拿回去好好钻研。";
}

NPC_END;