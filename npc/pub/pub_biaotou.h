NPC_BEGIN(CNpub_biaotou);

virtual void create()
{
	set_name( "ïÚÍ·");

	set("icon", triggerman1);
	set("gender", "ÄÐÐÔ");
	set("age", 35);

	set("combat_exp", 5000);
	set("shen_type", 1);

	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	carry_object("gangdao")->Do_Action(DO_WIELD);
	carry_object("cloth")->Do_Action(DO_WIELD);

};

NPC_END;




