//cow.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_cow);

virtual void create()
{
		set_name("���ţ","cow");

        set("long","һͷ���ţ��");
        set("race", "Ұ��");
        set("age", 5);
        set("int", 30);
        set("ridable", "1");
        set("hp", 300);
        set("max_hp", 900);
        set("shen_type", 0l);
        set("combat_exp",50000);
        set("attitude", "peaceful");

//        set("limbs", ({ "ͷ��", "����", "β��","����","ǰ��" }) );
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
