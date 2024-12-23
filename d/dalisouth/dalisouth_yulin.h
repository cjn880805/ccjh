//yulin.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_yulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	add_npc("pub_nongfu2");   // add by zdn 2001-07-13

	add_door("�����³����", "�����³����", "�������������");

	set("long", "����һƬʪ������֣�����ˮ��������·���У�ʮ���ɸߵľ޴������̸���ڣ����ɴֵü����˺ϱ�ҲΧ��ס����������֦�´�����ˮ�з�������������Ϊ����ľ��¡�������Ȼ�������ޣ�ȴ�Ƿ��ݾ۾ӵ���������������̨��������Խ�ڴ�������¶�ĸ�֦�ϣ��ö������Է���" );
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
