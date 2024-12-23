//liuheta.h

//Sample for room: ����������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_liuheta);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");
	
	add_npc("pub_guest");      // add by zdn 2001-07-14

	add_npc("wei_fang"); 

	add_door("����Ǯ������", "����Ǯ������", "����������");

	set("long","��������ɽ����������������֮ǰ�������������������������͡�֮����֮��ҵ����ֹ�Լ�������ϡ����ǡ��죬�أ��ķ�������˼�������˽�����ʮ���㣬�����ķ����̽�������һ������ֻ�����塣");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}


void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && !me->query("wei/renwu6"))
	{
		if(me->query("wei/renwu1") && me->query_temp("wei/renwu6_1")&& !me->query_temp("wei/renwu6_10"))
		{
			CContainer * env = me->environment();
			CContainer * wei=env->present("fang yu");
			if(wei)
			{
				tell_object(me, "\n$YEL���ͻȻ������Ů�ӷ����˹�����\n");

				CFightRoom * obj =  (CFightRoom *)load_item("fight_room");	
				obj->set_name("���������Ů�ӵ�ս��", "fight_room");
				obj->move(env);
				
				CNpc * robber = load_npc("wei_mengmian");
				((CChar *)robber)->set("owner",me->id(1));
				((CChar *)robber)->move(obj);
				obj->Join_Team(((CChar *)robber), CFightRoom::FIGHT_TEAM_A);
				
				wei->move(obj);
				wei->set("help",1);
				obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_B);
				obj->Begin_Fight(0);
				
			}
		}
	}
}
ROOM_END;
