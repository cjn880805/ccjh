//lamb.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_lamb);

virtual void create()
{
		set_name("Ұ����","lamb");

        set("long","һֻҰ��������ͷ����س��Ųݡ�");
        set("race", "Ұ��");
        set("age", 5);
        set("int", 30);
        set("ridable", "1");
        set("hp", 300);
        set("max_hp", 900);
        
        set("combat_exp",500);
        set("attitude", "peaceful");

//        set("limbs", ({ "ͷ��", "����", "β��","����","ǰ��" }) );
//        set("verbs", ({ "bite","hoof" }) );
		CVector v;

		v.append("bite");
		v.append("hoof");
		set("verbs", v);

        set_temp("apply/attack", 10);
        set_temp("apply/armor", 5);
        set_temp("apply/damage", 15);
	
};

NPC_END;
