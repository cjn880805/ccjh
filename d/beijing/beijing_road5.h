//road5.h

//Sample for room: �����5
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����5");

	//add npcs into the room
	add_npc("pub_bing");

	add_door("�����ʳ�", "�����ʳ�", "���������5");
	add_door("���������6", "���������6", "���������5");
	add_door("��ľ�»���·3", "��ľ�»���·3", "���������5");

	set("long", "������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷ɳ۶���������һ·��������·��������������������֡����߾����������ˡ�" );

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
