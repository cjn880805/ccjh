//shanlu1.h

//Sample for room: ����ɽ·1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ·1");
	
	add_npc("pub_xiaozei");           //add by zdn 2001-07-14


	add_door("���ݷ�����", "���ݷ�����", "����ɽ·1");
	add_door("������ʯ���2", "������ʯ���2", "����ɽ·1");

	set("long","һ�������߳�����ɽ·�������������������졣����ɽ·�ϣ�ֻ�����Է�����������ɫ���ˡ���ʱ�н���Ͳ�����������ϱ㵽�������á����¾��Ǵ����" );
 
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
