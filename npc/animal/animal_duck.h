//duck.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_duck);

virtual void create()
{
	set_name("ҰѼ","duck");

        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻҰѼ��");

//        set("limbs", ({ "ͷ��", "����", "β��" }) );
//        set("verbs", ({ "bite" }) );

		CVector v;

		v.append("bite");
		set("verbs", v);

        set_skill("dodge", 50);
        set("combat_exp", 500);
};





NPC_END;
