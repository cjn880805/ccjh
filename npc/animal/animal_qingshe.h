//qingshe.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_qingshe);

virtual void create()
{
	set_name("竹叶青蛇","qing she");
	set("icon", snake);

	set("animal", "snake");

	set("race", "野兽");
	set("age", 2);
	set("long", "一只让人看了起鸡皮疙瘩的竹叶青蛇。");
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
		message_vision( "你觉得被咬中的地方一阵麻木！",player );
	}
	return 0;
}

NPC_END;
