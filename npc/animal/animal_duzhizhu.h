//duzhizhu.h
//code by zwb
//12-16
//inherit F_UNIQUE;

NPC_BEGIN(CNAnimal_duzhizhu);

virtual void create()
{
	set_name("��֩��","du zhizhu");

    set("long", "һֻ�޴��֩�룬������ʰ��,������֮���������㡣���ֱ����������һ���ж���");

    set("race", "Ұ��");
    set("age", 3);
    set("attitude", "peaceful");

    set("max_hp", 100000);
    set("str", 40);
    set("cor", 50);
	set("level",160);

	CVector v;

	v.append("bite");
	set("verbs", v);

    set_temp("apply/attack", 10);
    set_temp("apply/damage", 10);
    set_temp("apply/armor", 10);
	set_temp("apply/dodge", 200);

    set("combat_exp", 1000000);
};


virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

virtual void die()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",query("owner"));
		me=find_online(msg);
		if(me)
		{
			tell_object(me, "\n$HICֻ����ɽ������Ӱ���ɣ�ɲ�Ǽ��ѻ��������Ʒ磬����֩�룬��֩��������˳�ȥ����Ȼ������\n");
			tell_object(me, snprintf(msg, 255, "%s���ˡ�", name(1)));
			tell_object(me,"\n$HIC��������л�������ٴλ��ι�ȥ��\n");
			me->unconcious();
			me->set("hp",me->query("eff_hp"));
			me->set_temp("xy/renwu2_2",1);//һ����ң�Ⱦ���֩�붾�����͵���ң��С��
			me->move(load_room("��ң��С��"));
			
			CContainer * env = load_room("��ң��С��");
			CContainer * Xy_Npc=env->present("tong lao");
			if(!Xy_Npc)
			{
				CChar * XyNpc= load_npc("xy_tielao");
				XyNpc->move(load_room("��ң��С��"));
			}
		}
	}
	CNpc::die();
}
NPC_END;
