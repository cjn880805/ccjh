//yufeng.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_yufeng);

virtual void create()
{
		set_name("���","yu feng");

        set("race", "Ұ��");
        set("age", 8);
        set("long", "����һֻ��ɫ���۷䣬��ͷ����ͨ�۷��ö࣬����ϱ����ü�������֡�");

        set("str", 40);
        set("dex", 50);

//        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
//        set("verbs", ({ "bite", "poke" }) );

		CVector v;

		v.append("bite");
		v.append("poke"); 
		set("verbs", v);

        set_temp("apply/attack", 35);
        set_temp("apply/armor", 25);
};

NPC_END;
