// wei_nixiang.h ����
// �ز�	2002��12��25

NPC_BEGIN(CNwei_nixiang);

virtual void create()
{
	set_name("����","ni xiang");
	set("icon", officer);

	set("gender", "����");
	set("age", 1000);

	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);

	set("max_hp",1000);
	set("hp",1000);
	set("eff_hp",1000);

	set_weight(900000000);
	
	set("combat_exp", 3000+random(5000));

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",15);

	call_out(do_die, 900);	
	set("no_kill",1);

};

virtual int do_look(CChar * me)
{
	say("������ȥ����������۴��綷���������࣬������������ģ����", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "look") == 0) 
		return CNpc::handle_action(comm, me, arg);

	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )
	{
		tell_object(me,"\n$HIC����ҡ���˼��£�һ����ָֻ���ƽ����");
		return 1;
	}
	if(me->query_temp("wei/renwu8_4") && !me->query_temp("wei/renwu8_5"))
	{
		CContainer * jian=me->present("taomujian");
		if(jian)
		{
			tell_object(me,"\n$HIC�������̽���������ħ���䣬���ܻ�Ұ���ʱ����Ǻ�������ϴ���������Ц�������Ƕ��������ɣ�");
			tell_object(me,"$HIC������������ʲô����㣬ҡ���˼��£���Ȼ���£�¶���˱����һ��������\n");
			me->set_temp("wei/renwu8_5",1);//ʹ����ľ����������

			CContainer * env = load_room("���ݻ���ص�");
			CContainer * nixiang=env->present("nixiang");
			if(!nixiang)
			{
				nixiang=load_item("nixiang");
				nixiang->move(env);
			}
			move(load_room("temp_nixiang"));
			if(jian->query("count")>=5)
				destruct(jian);
			else
				jian->add("count",1);
		}
		else
		{
			tell_object(me,"\n$HIC����ҡ���˼��£�һ����ָֻ���ƽ����");
		}
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	npc->move(load_room("mf"));
}

NPC_END;




