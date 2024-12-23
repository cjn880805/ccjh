//xiaolu.h

//Sample for room:  ����С·
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_xiaolu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����С·");

	add_npc("animal_dushe");
				
	add_door("������ʯ��", "������ʯ��", "����С·");
	add_door("�䵱������", "�䵱������", "����С·");
//	add_door("�ɶ���������", "�ɶ���������", "����С·");
//	add_door("�ɶ���������", "�ɶ���������", "����С·");

	set("long","�����Ĵ�������Ľ��硣һ�������ĵ�С��·�����������������ũ������·�����˺��٣����ҴҸ�·��");

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
