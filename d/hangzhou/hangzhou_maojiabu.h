//maojiabu.h

//Sample for room: ����é�Ҳ�
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_maojiabu);

virtual void create()			
{
	set_name( "����é�Ҳ�");

	add_npc("pub_oldwoman");
	add_npc("pub_boy");
	add_npc("wei_jhlz");

	add_door("���ݻ�����", "���ݻ�����", "����é�Ҳ�");
	add_door("������·", "������·", "����é�Ҳ�");

	set("long","·���Ը��ż���С���������ſ�һλ�ϴ�������ι��������С������׷����Ϸ���������ϻ����롣�����Ƕ���ɽ��" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query("wei/renwu1") && !me->query("wei/renwu5"))
	{
		say("�����ӻ�������������һ��é��������������ӳ���������£�����������д�š�����������֡�",me);
		AddMenuItem("���������", "$0jinru $1", me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(!strcmp(comm, "jinru"))
	{
		return do_jinru(me, arg);
	}
	return 0;
}

int do_jinru(CChar *me, char * arg)
{
	if (me->query_temp("wei/renwu5_7"))
	{
		if(EQUALSTR(me->querystr_temp("apply/name"),"��������"))
		{
			CContainer * mianjue=me->present("mian ju");
			if(mianjue)
			{
				me->move(load_room("���������"));
				me->set_temp("wei/renwu5_8",1);//���������
			}
		}
	}
	else
	{
		say("���˾ܾ��ÿͣ�", me);
		SendMenu(me);
		return 0;
	}
	return 1;
}
ROOM_END;
