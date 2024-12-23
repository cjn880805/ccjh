//road6.h

//Sample for room: �����6
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����6");


	add_door("���������7", "���������7", "���������6");
	add_door("���������5", "���������5", "���������6");
	add_door("��ɽ����Ͽ", "��ɽ����Ͽ", "���������6");

	set("long", "������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷ɳ۶���������һ·��������·��������������������֡�������ԶԶ�ľͿ������������ǡ�������ͨ����ɽ��" );

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
