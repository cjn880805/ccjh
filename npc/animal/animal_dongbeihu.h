//dongbeihu.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_dongbeihu);

virtual void create()
{
		set_name("东北虎","dongbeihu");
	set("icon", tiger);

	set("animal", tiger);

        set("race", "野兽");
        set("age", 20);
        set("long","一只矫捷的斑斓猛虎，形体巨大，状极威猛，雄伟极了。");
        set("attitude", "aggressive");
        set("shen_type", -1);

//        set("limbs", ({ "虎头", "虎身", "前爪", "后爪", "尾巴" }) );
//        set("verbs", ({ "bite", "claw" }) );

		CVector v;

		v.append("bite");
		v.append("claw");
		set("verbs", v);

        set("combat_exp", 50000);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 300);
        set_temp("apply/armor", 100);
};

virtual void init(CChar * player)
{
	call_out(start_kill_ob, 5, player->object_id());
}

static void start_kill_ob(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * player = (CChar *)(me->environment())->Present(param1);

	if(!player) return;

	if (player->query_dex()<30 && ! me->query_temp("owner"))
	{
		message_vision( "只见发起一阵狂风。只听得乱树背後扑地一声响，跳出一只吊睛白额大虫来。那大虫又饿，又渴，把两只爪在地上略按一按，和身望你一扑，从半空里撺将下来。\n$N这一下没有躲开，为虎所伤晕了过去。",player);
		player->receive_wound("hp",30);
		player->receive_damage("hp",30);
		player->start_busy(2);
		me->kill_ob(player);
	}
}

NPC_END;
