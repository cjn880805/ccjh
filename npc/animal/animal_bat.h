//bat.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_bat);

virtual void create()
{
		set_name("����","bat");

        set("race", "Ұ��");
        set("age", 8);
        set("long", "����һֻ�����������ڶ�����\n");

        set("str", 40);
        set("dex", 50);

//        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
//        set("verbs", ({ "bite", "poke" }) );
		CVector v;

		v.append("bite");
		v.append("poke");
		set("verbs", v);

        set_temp("apply/attack", 33);
        set_temp("apply/armor", 20);
};


NPC_END;
