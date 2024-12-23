//road1.h

//Sample for room: ��ʯ�ٵ�1
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ʯ�ٵ�1");
	
	add_npc("pub_xianren");     //add by zdn 2001-07-16


	add_door("����", "����", "������ʯ�ٵ�1");
	add_door("���ݺ�ɽ��", "���ݺ�ɽ��", "������ʯ�ٵ�1");

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
