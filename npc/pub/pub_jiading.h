NPC_BEGIN(CNPub_jiading);

virtual void create()
{
	set_name( "家丁");

	set("icon", young_man5);
	set("gender", "男性");
	set("age", 35);

	set("long", "郭府家丁。");
	set("combat_exp", 4000);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_temp("apply/attack",  10);
	set_temp("apply/defense", 10);
	set("shen_type", 1);
	add_money(300);
	carry_object("cloth")->Do_Action(DO_WIELD);
};

NPC_END;
