//wuya.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_wuya);

virtual void create()
{
		set_name("乌鸦","wu ya");

        set("race", "野兽");
        set("age", 3);
        set("long", "一只黑色的乌鸦，丑陋极了。");
        set("attitude", "peaceful");

//        set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
//        set("verbs", ({ "bite", "claw" }) );
		CVector v;

		v.append("bite");
		v.append("claw"); 
		set("verbs", v);

        set("combat_exp", 300);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);
};



NPC_END;
