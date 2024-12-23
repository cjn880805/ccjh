//snake.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_snake);

virtual void create()
{
		set_name("¶¾Éß","snake");
		
		set("icon", snake);
	
		set("animal", "snake");

        set("race", "Ò°ÊÞ");
        set("age", 4);
        set("long", "Ò»Ö»ÓÐ×ÅÈý½ÇÐÎÄÔ´üµÄÉß£¬Î²°ÍÉ³É³×öÏì¡£");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

		CVector v;

		v.append("bite");
		set("verbs", v);

        set("combat_exp", 1000);

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


void die()
{
    load_item("shedan")->move(environment());    
	CNpc::die();
}
NPC_END;
