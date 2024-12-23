//eagle.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_eagle);

virtual void create()
{
	set_name("秃鹰","eagle");
	
	set("race", "野兽");
	set("age", 3);
	set("long", "一只黑色的秃鹰，秃头黑羽，好吃腐尸，看起来讨厌极了。\n");
	set("attitude", "peaceful");

	CVector v;
	
	v.append("bite");
	v.append("claw");
	set("verbs", v);
	
	set("max_hp",8000);
	
	set("combat_exp", 250000+random(100000));
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 220);
	set_temp("apply/damage", 200);
	set_temp("apply/dodge", 300);
	set_temp("apply/parry", 220);
}

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

NPC_END;
