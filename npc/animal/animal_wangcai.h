
NPC_BEGIN(CNAnimal_wangcai);

virtual void create()
{
		set_name("旺财","doggie");
	set("icon", dog);

        set("race", "野兽");
        set("age", 20);
        set("attitude", "aggressive");
        set("shen_type", -1);

		set("animal", "dog");

		CVector v;

		v.append("bite");
		v.append("claw");
		set("verbs", v);

		set("chat_chance", 5);

        set("combat_exp", 10000);

        set_temp("apply/attack", 400);
        set_temp("apply/defense", 400);
        set_temp("apply/armor", 200);
		set("no_huan",1);
};

virtual void init(CChar * player)
{
	call_out(start_kill_ob, 2, player->object_id());
}

static void start_kill_ob(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * player = (CChar *)(me->environment())->Present(param1);

	if(!player) return;

	if (player->query_dex()<30 && ! me->query_temp("owner"))
	{
		message_vision( "只见发起一阵狂风。只听得乱树背後扑地一声响，跳出一只哈巴狗来。那狗又饿，又渴，把两只爪在地上略按一按，和身望你一扑，从半空里撺将下来！",player);
		player->receive_wound("hp",40);
		player->receive_damage("hp",40);
		player->start_busy(2);
		me->kill_ob(player);
	}
}

char * chat_msg()
{
	//检查是否该逃走了。
	if(! random(10))
	{
		message_vision("$N跳入草丛消失了！", this);
		DESTRUCT_OB(this, "animal_wangcai::chat_msg");
	}

	return 0;	
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	int i;
	int o;

	if (ob->query("is_task")==4)
	{
		i=ob->query("valued");
		o=random(i)+1;
		o=random(i)+1;

		if (who->query("repute")==0)
			o=0;
		if (who->query("repute")<0)
			o=-o;
		snprintf(msg, 255, "%s完成了情书的任务，获得%d点经验，%d点声望！", who->name(1),i,o);

		g_Channel.do_channel(&g_Channel, 0, "sys", msg);

		tell_object(who,msg);

		who->add("combat_exp",i);
		who->add("repute", o);

		DESTRUCT_OB(ob, "animal_wangcai::accept_object");
		return 1;
	}

return 0;
}


NPC_END;
