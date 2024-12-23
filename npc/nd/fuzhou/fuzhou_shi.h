// shi.c
//sound 2001-07-18

NPC_BEGIN(CNfuzhou_shi);

virtual void create()
{
	set_name("Ê·ïÚÍ·", "shi biaotou");
	set("gender", "ÄÐÐÔ");
	set("age", 45);
	set("icon",triggerman2);
	
	set("combat_exp", 7000);
	set("shen_type", 1);
	
	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}
NPC_END;