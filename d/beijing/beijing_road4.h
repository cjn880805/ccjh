//road4.h

//Sample for room: �����4
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����4");

	//add npcs into the room
	add_npc("pub_jianke");
	add_npc("pub_rongwu");
	
	add_door("���������8", "���������8", "���������4");
	add_door("���������7", "���������7", "���������4");
	add_door("���������3", "���������3", "���������4");

	set("long", "������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷ɳ۶���������һ·��������·��������������������֡��������������������Ͼ��ǡ��ϱ�ͨ�����ݳǡ�" );

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
