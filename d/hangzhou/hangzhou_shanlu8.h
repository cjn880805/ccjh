//shanlu8.h

//Sample for room: ����ɽ·8
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ·8");
	
	add_npc("pub_punk");              // add by zdn 2001-07-14


	add_door("������ʯ���7", "������ʯ���7", "����ɽ·8");
	add_door("���ݻ�����", "���ݻ�����", "����ɽ·8");

	set("long"," ɽ����ľï�ܣ������������ﻹ���������ɡ������߱㵽�˻��������ϱ�������ɽ��·��");

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
