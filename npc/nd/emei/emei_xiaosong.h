// xiaosong.c 宋青书
//code by sound
//12-16

NPC_BEGIN(CNemei_xiaosong);

virtual void create()
{
 	set("icon",taoist_with_sword);
	set_name("宋青山", "song qingshu");
	set("long",
		"他就是宋远桥的儿子宋青山。\n"
		"他今年二十岁，乃是武当第三代中出类拔萃的人物。\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "aggressive");
	set("shen_type", -1);
	set("shen", -100000);
	set("str", 25);
	set("int", 28);
	set("con", 25);
	set("dex", 25);

        set_inquiry("宋远桥", "我爹做不成武当掌门了，哈哈。我却可以做峨嵋掌门的老公，哈哈哈！");
/*
	set("inquiry",([
		"宋夫人"  : (: ask_for_song :),
		"周芷若"  : (: ask_for_zhou :),
		"掌门人"  : (: ask_for_emei :),
        ]));
*/
	set("hp", 1000);
	set("max_hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("jiali", 30);
	set("combat_exp", 80000);
	set("score", 10000);
	
	set_skill("force", 60);
	set_skill("taiji_shengong", 40);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 40);
	set_skill("unarmed", 70);
	set_skill("taiji_quan", 50);
	set_skill("parry", 70);
	set_skill("sword", 70);
	set_skill("taiji_jian", 50);
	set_skill("liangyi_jian", 60);
	set_skill("taoism", 30);
	set_skill("literate", 40);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "liangyi_jian");
	
	create_family("武当派", 3, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}
/*
string ask_for_zhou()
{
    object ob;
    ob = this_player();
    command("heng");
    command("say " + ob->query("name") + "！你是什么东西？敢直呼芷若的名字？你找死！\n");
    command("kkkil " + ob->query("id"));
    kill_ob(this_player());
    return "你去死吧！\n";
}

string ask_for_song()
{
    object ob;
    ob = this_player();
    command("xixi");
    command("say " + ob->query("name") + "，内子正在里面，你找她去吧！\n");
    message_vision("宋青书酸溜溜地看着$N走进寝宫。\n\n",ob);
    ob->move("/d/emei/qinggong");
    return "又一个癞蛤蟆，嘿嘿。\n";
}

string ask_for_emei()
{
    object ob;
    ob = this_player();
    ob->set_temp("marks/宋夫人",1);
    command("say " + ob->query("name") + "，内子脾气不好，你自己保重吧！\n");
    message_vision("宋青书不怀好意地看着$N走进寝宫。\n\n",ob);
    ob->move("/d/emei/qinggong");
    return "进去就完了。\n";
}
*/
NPC_END;