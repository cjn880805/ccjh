//road9.h

//Sample for room: �����9
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����9");

	add_npc("pub_playboy");

	add_door("����������", "����������", "���������9");
	add_door("���������8", "���������8", "���������9");
	add_door("�������ݳ�", "�������ݳ�", "���������9");

	set("long", "������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷ɳ۶���������һ·���������ϵ��˸������ž�װ���¼��������еĻ���������ŵ�������������ЩЩϰ��Ľ����ˡ�" );
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
