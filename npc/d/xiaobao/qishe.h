//qishe.h
//code by zwb
//12-16

NPC_BEGIN(CNqishe);

virtual void create()
{
	set_name("蕲蛇","qi she");
	set("icon", snake);

	set("animal", "snake");

	set("race", "野兽");
	set("age", 2);
	set("long", "只见它全身血红，头呈三角，长蛇吞吐，嗤嗤做响。");
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 20);
	
	CVector v;

	v.append("bite");
	set("verbs", v);

	set("combat_exp", 30000+random(50000));

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",15);
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

void die()
{
	CContainer * ob = 0, * corpse = 0;
	message_vision("$N倒在地上，死了！", this);
	if(querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr("owner"));

		if(me)
		{
			if(me->query_temp("wei/renwu4_5"))
				me->set_temp("wei/renwu4_6",1);//杀死蕲蛇，可以获得蕲蛇胆
		}
	}
	if((corpse =CCorpse::MakeCorpse(this, NULL)) )
	ob = load_item("shedan");
	ob->set_name("蕲蛇胆","qishe dan");
	ob->set("long","这是一枚火红的蕲蛇胆。");
	ob->move(corpse);
	corpse->move(environment());
	DESTRUCT_OB(this, "qishe::die");
}

virtual const char * hit_ob(CChar * me, CChar * player, LONG damage)
{
	if (player->query_combat_exp() > 10000) return 0;
	if( random(damage) > player->query_temp("apply/armor") && player->query_condition("snake_poison") < 10 )
	{
		player->apply_condition("snake_poison", 20);
        tell_object(player, "你觉得被咬中的地方一阵麻木！");
	}
	return 0;
}

NPC_END;
