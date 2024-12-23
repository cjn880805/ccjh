//anjinmenkey.h
ITEM_BEGIN(CImupai1)

virtual void create(int nFlag = 0)		
{
	set_name("ʯ��","shi bei");
	set("no_get", "����һ���ʯ��");

};

virtual int do_look(CChar * me)
{
	say("���������Ҫ���˸������⣺", me);
	say("��־��ң��Ź��Ų������ھ���һ�ӣ���ǰȡ����ʮ���壬�ַ����ҳ��ϣ�ʹ�ø����ݡ��ᡢб������֮�;�Ϊʮ�壬��ɴ������أ����ô˸�", me);
	say("��ʧ�����Σ�����˸���Ե�������ء�", me);
	if(me->query("xy/renwu6") && !me->query("xy/renwu7") )
	{
		AddMenuItem("��", "$0tuei $1", me);
		AddMenuItem("��", "$0pai $1", me);
	}
	SendMenu(me);

	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(!strcmp(comm, "tuei")  && me->query("xy/renwu6") && !me->query("xy/renwu7") )
		return do_tuei(me);
	else if(!strcmp(comm, "pai")  && me->query("xy/renwu6") && !me->query("xy/renwu7") )
		return do_pai(me);
	return 0;
}

int do_tuei(CChar * me)
{
	CContainer * env=me->environment();
	CContainer * XyNpc;
	if(me->query_temp("xy/renwu6_5"))
		XyNpc=env->present("li qiou heng");
	else
		XyNpc=env->present("li cang hai");
	if(XyNpc && me->query_temp("xy/renwu6_1"))
	{
		if(EQUALSTR(XyNpc->querystr("owner"),me->id(1)) && me->query_temp("xy/renwu6_2"))
		{
			message_vision("$N����һ��ʯ����ֻ����Χ����һ�󡰸¸¡�֮����$N����һ�գ��������ȥ��", me);
			me->move(load_room("��ң�ȷ���֮��"));
			XyNpc->move(load_room("��ң�ȷ���֮��"));
			return 1;
		}
	}
	message_vision("$N����һ��ʯ����ֻ����Χ����һ�󡰸¸¡�֮�������֮���������ָֻ���ƽ����", me);
	return 1;
}

int do_pai(CChar * me)
{
	CContainer * env=me->environment();
	CContainer * XyNpc;
	if(me->query_temp("xy/renwu6_5"))
		XyNpc=env->present("li qiou heng");
	else
		XyNpc=env->present("li cang hai");
	if(XyNpc && me->query_temp("xy/renwu6_1"))
	{
		if(EQUALSTR(XyNpc->querystr("owner"),me->id(1)) && !me->query_temp("xy/renwu6_2"))
		{
			message_vision("$N����������������ƣ���ž����һ���ĵ�ʯ���ϡ�ʯ��һ��ҡ�Σ��������ָֻ���ƽ����", me);
			message_vision("$N����һ���������Ѿ�������һ����С��ʯ���ӡ�", me);
			me->set_temp("xy/renwu6_2",1);//ȡ������ʮ���ʯ����
			CContainer * shikuei=load_item("shikuei");
			shikuei->set_amount(45);
			if(shikuei)shikuei->move(env);
			return 1;
		}
	}
	message_vision("$N����������������ƣ���ž����һ���ĵ�ʯ���ϡ�ʯ������һ�Σ��������ָֻ���ƽ����", me);
	return 1;
}

ITEM_END;




