//qingshe.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_qingshe);

virtual void create()
{
	set_name("��Ҷ����","qing she");
	set("icon", snake);

	set("animal", "snake");

	set("race", "Ұ��");
	set("age", 2);
	set("long", "һֻ���˿�����Ƥ������Ҷ���ߡ�");
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 20);

	CVector v;

	v.append("bite");
	set("verbs", v);

	set("combat_exp", 3000+random(300));

	set_temp("apply/attack", 18);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 12);
	set_temp("apply/defence",16);
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
	load_item("qingdan")->move(environment());
	
	CNpc::die();
}

virtual LONG hit_ob(CChar * player , LONG damage)
{
	if (player->query_combat_exp() > 10000) return 1 ;
	if( random(damage) > player->query_temp("apply/armor")	&& player->query_condition("snake_poison") < 10 )
	{
		player->apply_condition("snake_poison", 20);
		message_vision( "����ñ�ҧ�еĵط�һ����ľ��",player );
	}
	return 0;
}

NPC_END;
