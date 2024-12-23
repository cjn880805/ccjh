//road1.h

//Sample for room: �����1
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����1");

	add_npc("pub_playboy");

	add_door("��������", "��������", "���������1");
	add_door("���������2", "���������2", "���������1");

	set("long", "������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷ɳ۶���������һ·��������·��������������������֡����߾��Ǿ��Ƕ��š���������һ��С·��" );

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
