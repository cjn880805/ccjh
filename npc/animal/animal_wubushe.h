//wubushe.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_wubushe);

virtual void create()
{
	set_name("五步蛇","wu bu she");

	set("long",	"五步蛇是福建地方毒蛇，相传中毒行路五步即行倒毙。");

	set("animal", "snake");

	set("race", "野兽");
	set("age", 3);
	set("attitude", "peaceful");

	set("max_hp", 240);

	set("str", 10);
	set("cor", 50);

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

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

static void start_kill_ob(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * player = (CChar *)(me->environment())->Present(param1);

	if(player)
		me->kill_ob(player);
}

virtual const char * hit_ob(CChar * npc, CChar * victim, LONG damage)
{
    if (victim->query_combat_exp() > 10000) return 0;
	if( random(damage) > victim->query_temp("apply/armor") 	&&	victim->query_condition("snake_poison") < 10 ) 
	{
		victim->apply_condition("snake_poison", 40);
        tell_object(victim, "你开始感到身体变得冰凉。！");
	}
	return 0;
}

NPC_END;
