//yuanwai.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yuanwai);

virtual void create()
{
	set_name("侯员外","yuan wai");

	set("icon", pawnshop_boss);
	set("long","侯员外据说是这长安镇上的首富，谁也不知道他到底有多少家财。他大约五十出头，长的富富态态。");
	set("gender", "男性");
	set("age", 52);
	
	set("combat_exp", 12000);
	set_skill("unarmed", 45);
	set_skill("force", 42);
	set_skill("dodge", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/defense", 42);
	
	carry_object("jinduan")->wear();
	add_money(120);
	
};



NPC_END;
