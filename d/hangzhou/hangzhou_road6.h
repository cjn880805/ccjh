//road6.h

//Sample for room: ������ʯ���6
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���6");

	//add npcs into the room
	add_npc("pub_liumang");
	add_npc("pub_liumang");
	add_npc("pub_liumang");
	add_npc("pub_liumang");
	add_npc("pub_liumangtou");
	
	//add_door("��������", "��������", "������ʯ���6");
	add_door("�����յ�1", "�����յ�1", "������ʯ���6");
	add_door("������ʯ���7", "������ʯ���7", "������ʯ���6");
	add_door("������ʯ���5", "������ʯ���5", "������ʯ���6");

	set("long","��������ˣ����У���˽Σ�����������ϲ�������������������������������ߡ��ϱ���ͨ���յ̡�������������");
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("wei/renwu8_2")&& !me->query_temp("wei/renwu8_4"))
	{
		AddMenuItem("�۲�ľ׮��", "$0kan $1", me);
	}
	if(me->query_temp("wei/renwu8_3") && !me->query_temp("wei/renwu8_4"))
	{
		AddMenuItem("��ľ׮ʹ�ý�", "$0jian $1", me);
	}
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("wei/renwu8_2"))
		return 0;
	if(strcmp(comm, "kan") == 0)
		return do_kan(me, arg);
	if(strcmp(comm, "jian") == 0)
		return do_jian(me, arg);
	return 0;
}

int do_kan(CChar *me, char * arg)
{
	say("����һ���ִ��Բľ׮�������Ǳ�����������������������ϸ�۲�ľ׮���棬�ɿ������м���һ����ƽ�糤�����С����", me);
	SendMenu(me);
	me->set_temp("wei/renwu8_3",1);//�۲������׮
	return 1;
}

int do_jian(CChar *me, char * arg)
{
	CContainer * jian=me->present("changjian");
	if(jian)
	{
		tell_object(me,"�㲦��һ�ѳ���������ľ׮�����С���������˽�ȥ��ֻ¶��������");
		tell_object(me,"ľ׮�µĵ��淢������һ�����졣");
		tell_object(me,"һ��޴�ġ���¡¡�������˹���������ͻȻ����һ��һ�ɼ����ĺڶ����㲻�������ص�����ȥ��");
		me->set_temp("wei/renwu8_4",1);//�����˵ض�
		me->move(load_room("���ݻ���ص�"));
	}
	else
	{
		say("�������ҿ���һ��Īչ��", me);
		SendMenu(me);
	}
	return 1;
}

ROOM_END;
