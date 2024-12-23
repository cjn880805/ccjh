//doe.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_doe);

virtual void create()
{
		set_name("梅花雌鹿","doe");

        set("race", "野兽");
        set("age", 20);
        set("long", "一只温驯的梅花雌鹿，正在低头吃草。\n");
        set("attitude", "peace");
        set("shen_type", -1);

//        set("limbs", ({ "鹿头", "鹿身", "前腿", "后腿", "臀部" }) );
//        set("verbs", ({ "hoof" }) );
		CVector v;

		v.append("hoof");
		set("verbs", v);

        set("combat_exp", 2000);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 10);
}



NPC_END;
