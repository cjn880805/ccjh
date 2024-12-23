//xiezi.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_xiezi);

virtual void create()
{
	set_name("蝎子","xie zi");

    set("long", "一只蝎子正虎视眈眈地盯著你。");

    set("race", "野兽");
    set("age", 3);
    set("attitude", "peaceful");

    set("max_hp", 240);
    set("str", 10);
    set("cor", 50);

	CVector v;

	v.append("bite");
	v.append("poke");
	set("verbs", v);


	set("max_hp",8000);
	
	set("combat_exp", 200000+random(100000));
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 2050);
	set_temp("apply/armor", 180);
	set_temp("apply/damage", 100);
	set_temp("apply/dodge", 2500);
	set_temp("apply/parry", 100);
};

virtual void init(CChar * player)
{
	kill_ob(player);
}

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

virtual const char * hit_ob(CChar * npc, CChar * victim, LONG damage)
{
    if (victim->query_combat_exp() > 10000) return 0 ;
    if( random(damage) > victim->query_temp("apply/armor")  &&  victim->query_condition("scorpion_poison") < 10 )
    {
        victim->apply_condition("scorpion_poison", 20);
        tell_object(victim, "你开始感到身体变得冰凉。！");
    }

	return 0;
}

NPC_END;
