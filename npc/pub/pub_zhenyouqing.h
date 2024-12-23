//zhenyouqing.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_zhenyouqing);

virtual void create()
{
	set_name("甄有庆","zhen youqing");

	set("icon", officer);
	set("title", "知府师爷");
	set("gender", "男性");
	set("age", 57);

	set("combat_exp", 30000);
	set_skill("unarmed", 50);
	set_skill("dodge", 60);
	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);
	

	carry_object("qingyi")->wear();
};

NPC_END;
