//dandinghe.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_dandinghe);

virtual void create()
{
		set_name("������","danding he");

        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻȫ���׵ĵ����ף����������˳��û���߷��ˡ�");
        set("attitude", "peaceful");

//        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
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
