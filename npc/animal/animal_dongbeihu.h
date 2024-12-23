//dongbeihu.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_dongbeihu);

virtual void create()
{
		set_name("������","dongbeihu");
	set("icon", tiger);

	set("animal", tiger);

        set("race", "Ұ��");
        set("age", 20);
        set("long","һֻ�ýݵİ���ͻ�������޴�״�����ͣ���ΰ���ˡ�");
        set("attitude", "aggressive");
        set("shen_type", -1);

//        set("limbs", ({ "��ͷ", "����", "ǰצ", "��צ", "β��" }) );
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
		message_vision( "ֻ������һ���硣ֻ�������������˵�һ���죬����һֻ�����׶��������Ǵ���ֶ����ֿʣ�����ֻצ�ڵ����԰�һ������������һ�ˣ��Ӱ����ߥ��������\n$N��һ��û�ж㿪��Ϊ���������˹�ȥ��",player);
		player->receive_wound("hp",30);
		player->receive_damage("hp",30);
		player->start_busy(2);
		me->kill_ob(player);
	}
}

NPC_END;
