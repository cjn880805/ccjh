//shanyang.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_shanyang);

virtual void create()
{
		set_name("ɽ��","shan yang");

        set("long","һͷ�̽�ɽ�򣬴�����������ļ���");
        set("race", "Ұ��");
        set("age", 5);
        set("int", 30);
        set("hp", 300);
        set("max_hp", 900);
        
        set("combat_exp",50000);
        set("attitude", "peaceful");

		CVector v;

		v.append("hoof");
		v.append("bite");
		set("verbs", v);

        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

};


NPC_END;
