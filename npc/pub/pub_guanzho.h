NPC_BEGIN(CNpub_guanzho);

virtual void create()
{

	set_name("¹ÛÖÚ","guanzho");

	set("icon", taoist);
	set("gender", "ÄÐÐÔ");
	set("age", 15+random(70));

	set("combat_exp", 5000+random(10000));
    set_skill("unarmed", 10+random(50));
    set_skill("force", 10+random(50));
    set_skill("dodge", 10+random(50));
    set_temp("apply/attack", 5+random(50));
    set_temp("apply/defense", 5+random(50));
	

	carry_object("cloth")->wear();
	carry_object("meihualing");
	add_money(1 + random(20));


};


NPC_END;
