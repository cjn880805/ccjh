// zheng.c
//sound 2001-07-18

NPC_BEGIN(CNfuzhou_zheng);

virtual void create()
{
	set_name("Ö£ïÚÍ·", "zheng biaotou");
	set("gender", "ÄÐÐÔ");
	set("age", 45);
	set("icon",triggerman2);
	
	set("combat_exp", 10000);
	set("shen_type", 1);
	
	set_skill("unarmed", 30);
	set_skill("blade", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/damage", 30);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}
NPC_END;