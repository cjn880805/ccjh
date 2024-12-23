//wudang_tongbw.c
//code by Fisho
//date:2000-12-22
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNwudang_tongbw);

virtual void create()
{
	set_name("童千牛","tongbai xiong" );
	set("gender", "男性" );
	set("age", 75);
        set("icon",old_man1);

	set("title", "日月神教风雷堂长老");
	set("long", "他白发披散, 银髯戟张, 脸上的肌肉牵动, 圆睁双眼, 身上的鲜血已然凝结, 神情甚是可怖。 ");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	
	set("max_hp", 3000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 200);
	set("combat_exp", 350000);
	set("score", 30000);
	
	set_skill("force", 100);
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
	create_family("日月神教",2,"弟子 风雷堂长老");
	
	set("chat_chance", 3);
	
	carry_object("zijinchui")->wield();
	carry_object("cloth")->wear();
	carry_object("card1")->wear();
	
}

virtual char * chat_msg()
{
	switch (random(2))
	{
	case 0:
		return "童千牛道：“我没错, 我没有叛教! 东方兄弟你不能冤枉我呀! ” ";
	case 1:
		return "童千牛道：“我和东方兄弟出生入死, 共历患难的时候, 你们还没生下来哪!” ";
	}
	return "";
}


virtual void attempt_apprentice(CChar * ob)
{
	say("我是患难之身, 怎么能收徒呢。壮士还是请回吧! ", ob);
	SendMenu(ob);
}

NPC_END;