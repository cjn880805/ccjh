//road2.h

//Sample for room: �����2
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����2");

	//add npcs into the room
	//add_npc("tangzi");
	add_npc("pub_xieqiufeng");
	
	add_door("���������3", "���������3", "���������2");
	add_door("���������1", "���������1", "���������2");

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
