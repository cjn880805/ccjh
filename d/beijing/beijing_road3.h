//road3.h

//Sample for room: �����3
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����3");


	add_door("���������4", "���������4", "���������3");
	add_door("���������2", "���������2", "���������3");
	add_door("��������ͷ", "��������ͷ", "���������3");

	set("long", "������һ����������Ĵ�����ϡ��������������������ӵġ����̵ģ����Ŵ󳵵������Ͼ��Ͽ��������������������ǳ����֡���ʱ������������������߷ɳ۶���������һ·��������·��������������������֡�������������һ�������" );

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