//wuya.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_wuya);

virtual void create()
{
		set_name("��ѻ","wu ya");

        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻ��ɫ����ѻ����ª���ˡ�");
        set("attitude", "peaceful");

//        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
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
