//buck.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_buck);

virtual void create()
{
		set_name("÷����¹","buck");

        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ��ѱ��÷����¹�����ڵ�ͷ�Բݡ�");
        set("attitude", "peace");
        set("shen_type", -1);

//        set("limbs", ({ "¹ͷ", "¹��", "ǰ��", "����", "�β�" }) );
//        set("verbs", ({ "hoof" }) );
		CVector v;

		v.append("hoof");
		set("verbs", v);

        set("combat_exp", 2000);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 10);
}



NPC_END;
