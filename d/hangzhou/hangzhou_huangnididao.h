//huangnididao.h ���ݻ���ص�


ROOM_BEGIN(CRhangzhou_huangnididao);

virtual void create()		
{
	set_name( "���ݻ���ص�");

	add_npc("wei_nixiang");

	add_door("������ʯ���6", "������ʯ���6", "���ݻ���ص�");

	set("long","�˴�û�г�·��ֻ��һ������");
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("wei/renwu8_5"))
	{
		say("���µ����񱳺�¶��һ��������", me);
		AddMenuItem("����", "$0jin $1", me);
	}
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("wei/renwu8_5"))
		return 0;
	if(strcmp(comm, "jin") == 0)
		return do_jin(me, arg);
	return 0;
}

int do_jin(CChar *me, char * arg)
{
	me->move(load_room("���ݶ�Һ�ص���"));
	return 1;
}

ROOM_END;
