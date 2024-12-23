//duck.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_duck);

virtual void create()
{
	set_name("野鸭","duck");

        set("race", "野兽");
        set("age", 1);
        set("long", "一只野鸭。");

//        set("limbs", ({ "头部", "身体", "尾巴" }) );
//        set("verbs", ({ "bite" }) );

		CVector v;

		v.append("bite");
		set("verbs", v);

        set_skill("dodge", 50);
        set("combat_exp", 500);
};





NPC_END;
