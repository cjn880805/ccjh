ITEM_BEGIN(CIwas_mache);

virtual void create(int nFlag = 0)		
{
	set_name( "������");	
	set("no_get", "");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("����һ������ʮ�˵Ĵ�������", me);
	CContainer * menpiao=me->present("guan guang piao");
	if(wizardp(me)||
		(me->query_temp("was/renwu2_2") && menpiao && EQUALSTR(menpiao->querystr("owner"),me->id(1))))
	{
		AddMenuItem("ʹ����Ʊ", "$9menpiao $1", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "menpiao") && !me->query_temp("was/renwu2_3"))
	{
		CContainer * menpiao=me->present("guan guang piao");
		if(wizardp(me)||(me->query_temp("was/renwu2_2") && menpiao && EQUALSTR(menpiao->querystr("owner"),me->id(1))))
			return do_menpiao(me, arg);
	}
	return 0;
}

int do_menpiao(CChar *me, char * arg)
{
	CContainer * env;
	CContainer * env1;
	char msg[255];
	if(EQUALSTR(querystr("family/family_name"),me->querystr("family/family_name")))
	{
		tell_object(me,"\n$HIC�㲻�ܽ����������������һ���ɣ�\n");
		return 1;
	}
	if(me->query_temp("was/renwu2_4"))
	{
		tell_object(me,"\n$HIC�㲻�ܽ��������������ȥ�ɣ�\n");
		return 1;
	}
	CContainer * menpiao=me->present("guan guang piao");
	if(wizardp(me)||(me->query_temp("was/renwu2_2") && menpiao && EQUALSTR(menpiao->querystr("owner"),me->id(1))))
	{
		if(menpiao)
			destruct(menpiao);
		tell_object(me,"\n$HIC����󺰵��������ģ����ϳ�����\n");
		env = load_room("����ɽ��");
		env->add("count",1);

		env1 = load_room(snprintf(msg, 255, "������-%d",env->query("count")/2));
		env1->set("name","������");
		env1->add("count",1);
		env1->set("family/family_name",me->querystr("family/family_name"));
		((CRoom *)env1)->remove_all_doors();
		((CRoom *)env1)->add_door("����ɽ��", "����ɽ��", snprintf(msg, 255, "������-%d",env->query("count")/2));
		//�����и����⣬��ҽ�ȥ���ֳ����Ļ��ͻ��д�������
		if(env1->query("count")>1)
		{
			message_vision("$YEL����󺰵�������λ�������ȿ��������ˡ�����~~~����", me);
			((CRoom *)env1)->remove_all_doors();
			((CRoom *)env1)->reset();
		}

		me->move(env1);
		me->set_temp("was/renwu2_3",1);//������
	}
	return 1;
}

ITEM_END;


