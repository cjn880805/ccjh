//youke.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_youke);

virtual void create()
{
	set_name("ÓÎ¿Í","youke");

	set("icon", young_man5);
	set("gender", "ÄÐÐÔ");
	set("age", 20 + random(30));

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", 1750);
	set("shen_type", 1);

	add_money(500);

};



NPC_END;
