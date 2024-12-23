//dushe.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_dushe);

virtual void create()
{
	set_name("����","du she");
	set("icon", snake);

	set("animal", "snake");

	set("long",	"һ֧�������ŵĶ�������������ض����㡣\n");

	set("race", "Ұ��");
	set("age", 3);
	set("attitude", "peaceful");
	
	set("max_hp", 240);

	set("str", 10);
	set("cor", 50);

//	set("limbs", ({ "ͷ��", "����", "β��" }) );
//	set("verbs", ({ "bite" }) );
	CVector v;

	v.append("bite");
	set("verbs", v);

	set_temp("apply/attack", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	set("combat_exp", 1000);
	
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
	ob =load_item("jindan");
	ob->move(environment());

	CNpc::die();
}

virtual const char * hit_ob(CChar * me, CChar * player, LONG damage)
{
	if (player->query_combat_exp() > 10000) return 0;
	if( random(damage) > player->query_temp("apply/armor") && player->query_condition("snake_poison") < 10 )
	{
		player->apply_condition("snake_poison", 20);
        tell_object(player, "����ñ�ҧ�еĵط�һ����ľ��");
	}
	return 0;
}

NPC_END;
