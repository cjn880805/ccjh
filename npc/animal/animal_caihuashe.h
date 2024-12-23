//caihuashe.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_caihuashe);

virtual void create()
{
		set_name("�˻���","caihuashe");
		set("icon", snake);

		set("animal", "snake");

        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ�����ĵĲ˻��ߣ�ͷ������Բ�Ρ�");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);


		CVector v;

		v.append("bite");
		set("verbs", v);

        set("combat_exp", 100+random(50));

        set_temp("apply/attack", 7);
        set_temp("apply/damage", 4);
		set_temp("apply/defence",6);
		set_temp("apply/armor",5);
};

virtual void die()
{
	CContainer * ob;
	
	message_vision("$N�鴤���£�$N���ˡ�", this);
	ob = load_item("sherou");
	ob->move(environment());
	DESTRUCT_OB(this, "animal_caihuashe::die");
}

NPC_END;
