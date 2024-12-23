//road3.h

//Sample for room: ������ʯ���3
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���3");
	
	add_npc("pub_jianke");         //add by zdn 2001-07-14
	add_npc("pub_zhangxunqi"); 

	add_door("���ݻ�����", "���ݻ�����", "������ʯ���3");
	add_door("���ݺ鴺��", "���ݺ鴺��", "������ʯ���3");
	add_door("������ʯ���2", "������ʯ���2", "������ʯ���3");

	set("long","������߱�ֲ���ɣ���Ŀ�Դ䣬�ȸ���ѩ������Ϊ������ѩ�ɡ����������Ǻ鴺�š��������ϱ㵽�������¡��ϱ���һ����·��" );

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
