//road7.h

//Sample for room: �����7
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����7");


	add_door("���������4", "���������4", "���������7");
	add_door("���������6", "���������6", "���������7");

	set("long", "������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷ɳ۶���������һ·��������·��������������������֡�" );

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
