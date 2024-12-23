//shierpan1.h

//Sample for room:  ����ʮ����1
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_shierpan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ʮ����1");

	add_npc("pub_girldizi");    // add by zdn 2001-07-14
				
	add_door("����������", "����������", "����ʮ����1");
	add_door("����ʮ����2", "����ʮ����2", "����ʮ����1");

	set("long","����ʯ�׶��۶��䣬�ųơ�ʮ���̡����ɴ����Ͽɴﻪ�϶��������������֡�");

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
