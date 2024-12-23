//heimuya_wangcheng.h 王诚
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_wangcheng);

virtual void create()
{
	set_name("王城", "wang cheng");
	set("gender", "男性" );
	set("title", "日月神教风雷堂旗主");
	set("age", 65);
	set("long", "此人身材矮胖，满脸堆笑，其实为人十分狠毒。");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	set("icon",old_man1);
	
	set("hp", 1000);
	set("max_hp", 1000);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 150);
	set("combat_exp", 350000);
	
	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("sword",100);
	set_skill("taiji_shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji_jian", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
	create_family("日月神教",2,"弟子 风雷堂旗主");
	
	carry_object("gangjian")->wield();
	carry_object("cloth")->wear();
}

virtual void attempt_apprentice(CChar * me)
{
	say("我是患难之身, 怎么能收徒呢。壮士还是请回吧!", me);
	SendMenu(me);
}

NPC_END;