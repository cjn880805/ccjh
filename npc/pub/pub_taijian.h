//taijian.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_taijian);

virtual void create()
{
	set_name("Ì«¼à","taijian");

	set("icon", young_man6);
	set("gender", "ÎÞÐÔ");
	set("age", 15+random(60));

	set("combat_exp", 5000);
	

	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	add_money(random(10) + 5);
	carry_object("cloth")->wear();



};

NPC_END;
