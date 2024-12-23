//lion.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_lion);

virtual void create()
{
	set_name("雄狮","lion");

        set("race", "野兽");
        set("age", 15);
        set("long", "一只矫健的雄狮，十分威风。\n");
        set("attitude", "peace");
        set("shen_type", -1);

//       set("limbs", ({ "狮头", "狮身", "前爪", "后抓", "尾巴" }) );
//        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 40000);
        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 30000);
        set_temp("apply/armor", 800);

		CVector v;

		v.append("bite");
		v.append("claw");
		set("verbs", v);
	
};

NPC_END;
