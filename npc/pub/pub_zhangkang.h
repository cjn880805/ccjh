//zhangkang.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_zhangkang);

virtual void create()
{
	set_name("张康","zhangkang");

	set("icon", young_man5);
	set("gender", "男性");
	set("age", 25);
	set("per", 20);
	set("long", "这是个老实巴交的汉子，是张朝唐的从人。");
	set("combat_exp", 2000);
    set_skill("dodge", 20);
    set_skill("unarmed", 20);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 10);
	set("shen_type", 1);

	add_money(3);
	carry_object("cloth")->wear();


};


NPC_END;
