//wugui.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_wugui);

virtual void create()
{
		set_name("�ڹ�","wu gui");

        set("race", "Ұ��");
        set("age", 10);
        set("long", "һֻ���ڹ꣬����������С�ˡ�");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("combat_exp", 1000);

		CVector v;

		v.append("bite");
		v.append("poke");
		set("verbs", v);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);
};

virtual void die()
{
        CContainer * ob;
	
        message_vision("$N��ת�����ˣ�", this);
        ob =load_item("guijia");
        ob->move(environment());
        DESTRUCT_OB(this, "animal_wugui::die");
}

NPC_END;
