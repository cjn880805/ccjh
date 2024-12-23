//fox.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_fox);

virtual void create()
{
		set_name("狐狸","fox");

        set("race", "野兽");
        set("age", 4);
        set("long", "一只多疑成性的狐狸。");
        set("attitude", "peace");
        set("shen_type", -1);

//        set("limbs", ({ "狐头", "狐身", "前爪", "后抓", "尾巴" }) );
//        set("verbs", ({ "bite", "claw" }) );
		CVector v;

		v.append("bite");
		v.append("claw");
		set("verbs", v);

        set("combat_exp", 10000);

        set_temp("apply/attack", 1000);
        set_temp("apply/defense", 2000);
        set_temp("apply/armor", 300);
}



NPC_END;
