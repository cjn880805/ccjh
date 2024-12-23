//jiabaoyu.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNHeiMUYa_jiabaoyu);

virtual void create()
{

	set_name("贾宝玉","jia bao yu");

	set("gender", "男性" );
	set("age", 45);
	set("title", "日月神教青龙堂长老");
	set("long", "他蜡黄瘦脸，蓬头垢面，看见他就明白为什么男人是泥做的");
	set("attitude", "friendly");
	set("shen_type", -1);
 	set("icon",old_man1);

	set("per", 15);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);

	set("max_hp", 3000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("combat_exp", 350000);
	set("score", 30000);
	set("mp_factor", 200);
	set_skill("force", 140);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("blade",100);
	set_skill("taiji_shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji_dao", 100);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	
	map_skill("parry", "taiji_dao");
	map_skill("blade", "taiji_dao");
	create_family("日月神教",2,"弟子 青龙堂长老");

	set("chat_chance", 2);

    carry_object("dadao")->wield();
    carry_object("cloth")->wear();
}

virtual char *chat_msg(CChar * player)
{
	return "“攘外必先安内，堂中令牌被盗若是被东方妹妹知道，我命休矣。”";
}

virtual void attempt_apprentice(CChar * player)
{
	say(" 我这点皮毛，不敢，不敢!",player);
	SendMenu(player);
}



NPC_END