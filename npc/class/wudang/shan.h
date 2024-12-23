//shan.h
//code by zwb
//12-16

NPC_BEGIN(CNwudang_shan);

virtual void create()
{
	set_name("张翠山", "zhang cuishan");
	set("long","他就是张三丰的最聪明的弟子、武当七侠之五的张翠山。身穿一件干干净净的青布长衫。不过二十出头年纪，潇洒英俊，一副白马王子派头。");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	set("icon",taoist_with_sword);	
	set("foolid",120);
	set("max_hp", 6000);
	set("mp", 1500);
	set("max_mp", 2000);
	set("mp_force", 50);
	set("combat_exp", 500000);
	set("score", 60000);
	set("chat_chance_combat", 60);
	
	set_skill("force", 100);
	set_skill("taiji_shengong", 100);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 100);
	set_skill("unarmed", 100);
	set_skill("taiji_quan", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("liangyi_jian", 160);
	set_skill("taiji_jian", 100);
	set_skill("literate", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "liangyi_jian");
	map_skill("sword", "liangyi_jian");
	
	create_family("武当派", 2, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("bluecloth")->wear();
}

virtual char * chat_msg_combat()
{
	perform_action("sword ren",1);
	return 0;
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "张翠山恶狠狠地说道：没有两把刷子，我敢来解剑岩？";
	case 1:
		return "张翠山仰天叹道：哪个巫师帮我找到素素，我请鸭庄一顿。";
	}
	return 0;
}
/*
void greeting(object ob)
{
        if ((int)ob->query("shen") < 0)
        {
            say(CYN"\n\n张翠山脸现怒容：“邪魔外道，吃了豹子胆了，敢强闯武当！”\n\n");
            message_vision("张翠山居高临下，起手一掌，$N只得硬接，身子晃了一下。\n",ob);
            message_vision("对方右手长剑随即递出，$N无法招架，退了一步。\n\n\n"NOR,ob);
            ob->move("/d/wudang/slxl2");
        }
}  */

virtual void attempt_apprentice(CChar * player)
{
		char msg[255];

		//暂时不要守山门的任务。此段注释掉。lanwood 2001-02-24
		/*
        if (player->query("guarded") < 1) 
	{
			say("你对我武当派尽了多少心力，有几分忠心呢？",player);
			SendMenu(player);
            return;
        }
		*/
        if (player->query_int() < 30)
        {
			say("你的资质将来到不了铁划银钩的境界，收你也是白搭。",player);
			SendMenu(player);
            return;
        }
        if (player->query("repute") < 0)
		{
			say(" 我武当乃是堂堂名门正派，对弟子要求极严。",player);
            say(" 在德行方面你做得不够？",player);
            SendMenu(player);
            return;
        }
        say(" 好吧，我就收下你了。");
        command(snprintf(msg,255,"recruit %ld",player->object_id()));
}

NPC_END;