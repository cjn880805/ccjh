//road2.h

//Sample for room: ��ʯ�ٵ�2
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ʯ�ٵ�2");
	
	add_npc("pub_gongzi");      // add by zdn 2001-07=16

	add_door("���ݱ�", "���ݱ�", "������ʯ�ٵ�2");
	add_door("����ɽ·2", "����ɽ·2", "������ʯ�ٵ�2");
	add_door("���ݻ���ɽ", "���ݻ���ɽ", "������ʯ�ٵ�2");

	set("long", "������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ��������������һЩС��̯���ƺ���һ�����С�����������ݳ��ˡ�" );
	
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
