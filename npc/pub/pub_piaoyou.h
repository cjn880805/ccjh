NPC_BEGIN(CNPub_piaoyou);

virtual void create()
{
	set_name("Æ±ÓÑ","piaoyou");

	set("icon", young_man2);
	set("gender", "ÄÐÐÔ");
	set("age", 15+random(70));

	set("combat_exp", 5000+random(10000));
    set_skill("unarmed", 10+random(50));
    set_skill("force", 10+random(50));
    set_skill("dodge", 10+random(50));
    set_temp("apply/attack", 5+random(50));
    set_temp("apply/defense", 5+random(50));
	

	carry_object("male6_cloth")->wear();
	add_money(random(20));
};


NPC_END;
