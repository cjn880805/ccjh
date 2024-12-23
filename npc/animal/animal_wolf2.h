//wolf2.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_wolf2);

virtual void create()
{
	set_name("狼","wolf");

	set("icon", dog);

	set("animal", "wolf");

	set("race", "野兽");
	set("age", 5);
	set("long", "一匹昂首直立，两眼放着绿光的狼。");
	set("attitude", "aggressive");

	set("str", 26);
	set("cor", 30);

	set("combat_exp", 5000);

	CVector v;

	v.append("bite");
	v.append("claw"); 
	set("verbs", v);

    set("chat_chance",50);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",20);
};


NPC_END;
