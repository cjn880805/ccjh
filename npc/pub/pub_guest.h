NPC_BEGIN(CNpub_guest);

virtual void create()
{
	int age;
	age = 20 + random(40);

	set_name("½øÏã¿Í","guest");

	set("icon", young_man3);
    set("gender", "ÄĞĞÔ");
    set("age", age);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", 150+age*10);
	set("shen_type", 1);

	add_money(30 + age);
};


NPC_END;
