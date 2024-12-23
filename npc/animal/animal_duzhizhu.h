//duzhizhu.h
//code by zwb
//12-16
//inherit F_UNIQUE;

NPC_BEGIN(CNAnimal_duzhizhu);

virtual void create()
{
	set_name("毒蜘蛛","du zhizhu");

    set("long", "一只巨大的蜘蛛，浑身五彩斑斓,在三尺之外凝视着你。你的直觉告诉你它一定有毒。");

    set("race", "野兽");
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
			tell_object(me, "\n$HIC只见天山铁姥手影翻飞，刹那间已击出三股掌风，射向毒蜘蛛，毒蜘蛛仰天飞了出去，杳然不见。\n");
			tell_object(me, snprintf(msg, 255, "%s死了。", name(1)));
			tell_object(me,"\n$HIC你正待相谢，竟又再次昏晕过去。\n");
			me->unconcious();
			me->set("hp",me->query("eff_hp"));
			me->set_temp("xy/renwu2_2",1);//一入逍遥谷就中蜘蛛毒，被送到逍遥谷小屋
			me->move(load_room("逍遥谷小屋"));
			
			CContainer * env = load_room("逍遥谷小屋");
			CContainer * Xy_Npc=env->present("tong lao");
			if(!Xy_Npc)
			{
				CChar * XyNpc= load_npc("xy_tielao");
				XyNpc->move(load_room("逍遥谷小屋"));
			}
		}
	}
	CNpc::die();
}
NPC_END;
