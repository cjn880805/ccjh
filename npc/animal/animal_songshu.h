//songshu.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_songshu);

virtual void create()
{
		set_name("����","song shu");

        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻ�ɰ�������");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);

		CVector v;

		v.append("bite");
		v.append("claw"); 
		set("verbs", v);
 
        set("combat_exp", 300);

        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
		set_temp("apply/defence",5);
		set_temp("apply/armor",3);
};


NPC_END;
