// wudang_xiaosong.c 宋青书

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_xiaosong);

virtual void create()
{
	set_name("宋青云","song qingshu");
	set("long","他就是宋远桥的儿子宋青云。他今年二十岁，乃是武当第三代中出类拔萃的人物。 ");
	set("gender", "男性");
	set("age", 20);
        set("icon",young_man1);

	set("attitude", "aggressive");
	
	set("repute", -100000);
	set("str", 25);
	set("int", 28);
	set("con", 25);
	set("dex", 25);
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 30);
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
    say(" " + ob->query("name") + "！你是什么东西？敢直呼芷若的名字？你找死！ ");
    command("kkkil " + ob->object_id());
    kill_ob(this_player());
    return "你去死吧！ ";
}

string ask_for_song()
{
    object ob;
    ob = this_player();
    command("xixi");
    say(" " + ob->query("name") + "，内子正在里面，你找她去吧！ ");
    message_vision("宋青书酸溜溜地看着$N走进寝宫。  ",ob);
    ob->move("/d/emei/qinggong");
    return "又一个癞蛤蟆，嘿嘿。 ";
}

string ask_for_emei()
{
    object ob;
    ob = this_player();
    ob->set_temp("marks/宋夫人",1);
    say(" " + ob->query("name") + "，内子脾气不好，你自己保重吧！ ");
    message_vision("宋青书不怀好意地看着$N走进寝宫。  ",ob);
    ob->move("/d/emei/qinggong");
    return "进去就完了。 ";
}
*/
NPC_END;