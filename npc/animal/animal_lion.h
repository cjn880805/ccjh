//lion.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_lion);

virtual void create()
{
	set_name("��ʨ","lion");

        set("race", "Ұ��");
        set("age", 15);
        set("long", "һֻ�ý�����ʨ��ʮ�����硣\n");
        set("attitude", "peace");
        set("shen_type", -1);

//       set("limbs", ({ "ʨͷ", "ʨ��", "ǰצ", "��ץ", "β��" }) );
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
