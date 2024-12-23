//shanlu6.h

//Sample for room: ɽ·6
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_shanlu6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ·6");

	add_npc("pub_daoke");
	add_npc("pub_nongfu2");    // add by zdn 2001-07-13

	add_door("����ǹŵ�", "����ǹŵ�", "�����ɽ·6");
	add_door("�����ɽ·5", "�����ɽ·5", "�����ɽ·6");

	set("long", "һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ��������һ���޼ʵ���˫���ɴ�ɭ�֣���˵��а�̽��������л����·���Լ��ɼ�һЩ����Ĵ���ɽ·ת�������š�" );
	
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
