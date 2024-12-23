//bear.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_bear);

virtual void create()
{
		set_name("����","bear");

		set("icon", boar);

        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ���͵ĺ��ܣ�����˶���������С�\n");
        set("attitude", "aggressive");
        set("shen_type", -1);

		CVector v;

		v.append("bite");
		v.append("claw");
		v.append("knock");
		set("verbs", v);

		set("max_hp",15000);

        set("combat_exp", 320000+random(100000));
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 250);
        set_temp("apply/armor", 200);
		set_temp("apply/damage", 400);
		set_temp("apply/dodge", 200);
		set_temp("apply/parry", 200);
};

virtual void die()
{
	CContainer * ob = 0, * corpse = 0;

	message_vision("$N���춯��һ���Һ�������ί���ڵأ����ˣ�", this);
	if(querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr("owner"));

		CContainer * xiaoyaonv;
		xiaoyaonv=env->present("xiao yao nv");
		if(me && xiaoyaonv)
		{
			me->add_temp("xy/renwu3_2",1);//����ңŮɱ���ܣ�ɱ��һֻ����ɱ����ֻ��
			if(me->query_temp("xy/renwu3_2")==4)
				xiaoyaonv->set_temp("���",me->id(1));
		}
	}
	if((corpse =CCorpse::MakeCorpse(this, NULL)) )
	ob = load_item("xiongdan");
	ob->move(corpse);
	corpse->move(environment());
	DESTRUCT_OB(this, "animal_bear::die");
}

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

NPC_END;
