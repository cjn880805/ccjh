//shanlu7.h

//Sample for room: ����ɽ·7
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ·7");
	
	add_npc("pub_playboy");         //add by zdn 2001-07-14


	add_door("�������ɽ��", "�������ɽ��", "����ɽ·7");
	add_door("�������ɽ��", "�������ɽ��", "����ɽ·7");

	set("long"," ɽ·��᫣��������ӡ�������ľ�Դ䣬����ï�ܡ�ɽ·���Ǻ���ͤ�������ＫĿԶ����Ⱥɽ���������۵ס���������ɽ��·������������ɽ��·��");

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
