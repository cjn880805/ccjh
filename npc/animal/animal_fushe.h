//fushe.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_fushe);

virtual void create()
{
	set_name("����","fu she");
	set("icon", snake);

	set("animal", "snake");

	set("race", "Ұ��");
	set("age", 2);
	set("long", "ֻ����ȫ��Ѫ�죬ͷ�����ǣ��������£��������졣");
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
	//CContainer * ob;
	
	message_vision("$N���ڵ��ϣ����ˣ�", this);
	//ob =load_item("/d/baituo/obj/jindan");
	//ob->move(npc->environment());
	DESTRUCT_OB(this, "animal_fushe::die");
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
