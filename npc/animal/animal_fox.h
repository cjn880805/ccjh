//fox.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_fox);

virtual void create()
{
		set_name("����","fox");

        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ���ɳ��Եĺ��ꡣ");
        set("attitude", "peace");
        set("shen_type", -1);

//        set("limbs", ({ "��ͷ", "����", "ǰצ", "��ץ", "β��" }) );
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
