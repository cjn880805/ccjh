//shierpan4.h

//Sample for room:  ����ʮ����4
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_shierpan4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ʮ����4");

	add_npc("pub_jianke");              // add by zdn 2001-07-14
				
	add_door("����ʮ����3", "����ʮ����3", "����ʮ����4");
	add_door("���һ��϶�", "���һ��϶�", "����ʮ����4");

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
