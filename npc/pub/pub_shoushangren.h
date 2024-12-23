//shoushangren.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shoushangren);

virtual void create()
{
	set_name("瘦商人","shangren");

	set("icon", pawnshop_boss);
	set("gender", "男性");
	set("age", 43);
	set("long", "他瘦兮兮的，一脸穷苦相。\n");
	set("combat_exp", 2000);
    set_skill("dodge", 20);
    set_skill("unarmed", 20);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 10);
	

	add_money(3);
	carry_object("magcloth")->wear();
};

NPC_END;
