//port2.h

//Sample for room: ���׽���
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_port2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���׽���");


	add_door("��ٹ�������", "��ٹ�������", "��ٹ����׽���");
	add_door("��ٹ�ɽ��", "��ٹ�ɽ��", "��ٹ����׽���");

	set("long","������һ��Сɽ�£���������ɽ��·������һ�������ź�罭�棬ֻ����ˮ���ڣ���Х���������紵�������Ż�����ȥ��");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("wei/renwu3_5"))
	{
		say("ɽ�µĹսǴ��ƺ���һ��é�ݡ�",me);
	}
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && !me->query("wei/renwu3"))
	{
		if(me->query("wei/renwu1") && me->query_temp("wei/renwu3_5") && !me->query_temp("wei/renwu3_7"))
		{
			int i;
			CContainer * env = me->environment();
			CContainer * canjiang;
			CContainer * canbing;
			CNpc * robber;
			if(!me->query_temp("wei/renwu3_6"))
			{
				canjiang=env->present("can jiang");
				if(!canjiang)
				{
					robber = load_npc("wei_canjiang");
					((CChar * )robber)->set("owner",me->id(1));
					((CChar * )robber)->move(env);
					
					canbing=env->present("can bing");
					if(!canbing)
					{
						for(i=0;i<4;i++)
							((CChar * )load_npc("wei_canbing"))->move(env);
					}
				}
				else
				{
					canbing=env->present("can bing");
					if(!canbing)
					{
						for(i=0;i<4;i++)
							((CChar * )load_npc("wei_canbing"))->move(env);
					}
				}
			}
			else
			{
				for(i=0;i<9;i++)
				{
					canbing=env->present("can bing");
					if(!canbing)
						break;
					else
					{
						destruct(canbing);
					}
				}
				tell_object(me,"�������˼�������������ȫ���ҳ�һ�ţ���һ�����ɢ�ˡ�");
				me->set_temp("wei/renwu3_7",1);//��ȫ���͵������׽���
			}
		}
	}
}

ROOM_END;
