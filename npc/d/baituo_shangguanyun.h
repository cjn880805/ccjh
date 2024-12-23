//shangguanyun.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNBaiTuo_shangguanyun);

virtual void create()
{
	set_name("筒长老","shangguan yun");

	set("gender", "男性" );
	set("age", 40);
	set("title" , "日月神教白虎堂长老");
	set("long", "他长手长脚, 双目精光灿然, 若有威势。");
	set("attitude", "friendly");
	set("shen_type", -1);
 	set("icon",old_man1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 30);

	set("max_hp", 2400);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 200);
	set("combat_exp", 360000);
	set("score", 30000);

	set_skill("force", 80);
	set_skill("dodge", 120);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("staff",100);
	set_skill("hamagong",70);
	set_skill("chanchu_bufa", 120);
	set_skill("lingshe_zhangfa", 100);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");

	create_family("日月神教",2,"弟子 白虎堂长老");

	set("chat_chance", 3);
	
    carry_object("gangzhang")->wield();
    carry_object("cloth")->wear();
    carry_object("zhenzhu")->wear();
};

virtual void attempt_apprentice(CChar * me)
{
    say(" 我是患难之身, 怎么能收徒呢。壮士还是请回吧!", me);
	SendMenu(me);
}


NPC_END;
