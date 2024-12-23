//wolfdog.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_wolfdog);

virtual void create()
{
		set_name("���ǹ�","wolf dog");

		set("animal", "wolf");

        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ����ͦ�أ����ų���ͷ�Ĵ��ǹ������ǲ����������ĳ��\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("combat_exp", 1000);

		CVector v;

		v.append("bite");
		v.append("claw"); 
		set("verbs", v);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);
};


virtual void init(CChar * player)
{
	call_out(start_kill_ob, 5, player->object_id());
}

static void start_kill_ob(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * player = (CChar *)(me->environment())->Present(param1);

	if(player)
		me->kill_ob(player);
}

virtual void die()
{
		CContainer * ob;
		
        message_vision("$N�Ľ�һ�ţ����ˣ�", this);
        ob =load_item("goupi");
        ob->move(environment());
        DESTRUCT_OB(this, "animal_wolfdog::die");
}

NPC_END;
