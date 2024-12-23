//dandinghe.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_dandinghe);

virtual void create()
{
		set_name("丹顶鹤","danding he");

        set("race", "野兽");
        set("age", 3);
        set("long", "一只全身洁白的丹顶鹤，看来是修了翅膀，没法高飞了。");
        set("attitude", "peaceful");

//        set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
//        set("verbs", ({ "bite", "claw" }) );
		CVector v;

		v.append("bite");
		v.append("claw");
		set("verbs", v);

        set("combat_exp", 300);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 7);
        set_temp("apply/armor", 7);
};



NPC_END;
