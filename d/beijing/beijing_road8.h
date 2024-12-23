//road8.h

//Sample for room: �����8
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����8");


	add_door("���������9", "���������9", "���������8");
	add_door("���������4", "���������4", "���������8");

	set("long", "������һ����������Ĵ�����ϡ����Ͼ��Ǳ����ǡ������ӵġ����̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷ɳ۶���������һ·������" );
	
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
