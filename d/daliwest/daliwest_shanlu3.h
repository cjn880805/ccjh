//shanlu3.h

//Sample for room: ɽ·3
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_shanlu3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ·3");
	
	add_npc("pub_shaonu");
	add_npc("pub_daoke");       // add by zdn 2001-0-13

	add_door("�����ɽ·2", "�����ɽ·2", "�����ɽ·3");
	add_door("����Ǳ���", "����Ǳ���", "�����ɽ·3");

	set("long", "һ����ɽ·���Ѵ�����ï�ܵ�ɭ���У��򶫲�Զ�ɴ�����������--����ǣ���ȥ�������ɽ�����ڽӽ��������ģ�����·�������൱ƽ��������ɽ����᫣���·�������ѡ�" );
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
