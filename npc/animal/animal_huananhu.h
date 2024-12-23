//huananhu.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_huananhu);

virtual void create()
{
		set_name("���ϻ�","hua nan hu");
	set("icon", tiger);

	set("animal", tiger);

        set("race", "Ұ��");
        set("age", 20);
        set("long","һֻ�ý������ͻ�����ΰ���ˡ�");
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("combat_exp", 30000);
        set("mp",800);
        set("mp_factor",100);
        set("max_mp",800);
        set("hp",500);
        set("max_hp", 1500);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 300);
        set_temp("apply/armor", 100);

		CVector v;

		v.append("bite");
		v.append("claw");
		set("verbs", v);
	
};

virtual void init(CChar * player)
{
	call_out(start_kill_ob, 3, player->object_id());
}

static void start_kill_ob(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * player = (CChar *)(me->environment())->Present(param1);

	if(! player) return;

	if (player->query_dex()<20 && ! me->query_temp("owner") )
	{
		message_vision( "ֻ������һ����ֻ�������������˵�һ���죬����һֻ�����׶������Ǵ���ֶ����ֿʣ�����ֻצ�ڵ����԰�һ������������һ�ˣ��Ӱ����ߥ��������\n$N��һ��û�ж㿪��Ϊ���������˹�ȥ��",player);
		player->receive_wound("hp",20);
		player->start_busy(2);
		me->kill_ob(player);
	}
}

NPC_END;
