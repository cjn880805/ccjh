//cow.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_cow);

virtual void create()
{
		set_name("大黄牛","cow");

        set("long","一头大黄牛。");
        set("race", "野兽");
        set("age", 5);
        set("int", 30);
        set("ridable", "1");
        set("hp", 300);
        set("max_hp", 900);
        set("shen_type", 0l);
        set("combat_exp",50000);
        set("attitude", "peaceful");

//        set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
//        set("verbs", ({ "bite","hoof" }) );
		CVector v;

		v.append("bite");
		v.append("hoof");
		set("verbs", v);

        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);
};


NPC_END;
