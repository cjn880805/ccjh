// cui.c
//sound 2001-07-18

NPC_BEGIN(CNfuzhou_cui);

virtual void create()
{
	set_name("´ÞïÚÍ·", "cui biaotou");
	set("gender", "ÄÐÐÔ");
	set("age", 35);
	set("icon",triggerman1);
	
	set("combat_exp", 5000);
	set("shen_type", 1);
	
	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}

NPC_END;