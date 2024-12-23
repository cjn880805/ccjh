NPC_BEGIN(CNPub_nanpu);

virtual void create()
{
	set_name("ÄÐÆÍ","nanpu");
	
	set("icon", waiter);
	set("gender", "ÄÐÐÔ");
	set("age", 25);
	
	set("combat_exp", 4000);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_temp("apply/attack",  10);
	set_temp("apply/defense", 10);
	set("shen_type", -1);
	
	add_money(3);
	carry_object("cloth")->wear();
};


NPC_END;
