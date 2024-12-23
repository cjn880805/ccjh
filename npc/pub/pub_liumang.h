//liumang.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_liumang);

virtual void create()
{
	set_name("流氓","liumang");

	set("icon", cateran);
	set("gender", "男性");
	set("age", 19);
	set("long", "他是一个成天游手好闲的流氓，长得倒是白白胖胖的，也许以前有过钱。");
	
	set("combat_exp", 1000);
	set("shen_type", -1);
	set("score", -20);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	carry_object("cloth")->wear();
	add_money(20);


};

NPC_END;
