//atoubu.h

//Sample for room: ��ͷ��
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_atoubu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ͷ��");
	
	add_npc("pub_shaonu");
	add_npc("pub_shaonu");   // add by zdn 2001-07-13

	add_door("�������ˮ�ذ�", "�������ˮ�ذ�", "����ǰ�ͷ��");
	add_door("����Ǹ���ɽ����", "����Ǹ���ɽ����", "����ǰ�ͷ��");
	add_door("�������Ϫ��", "�������Ϫ��", "����ǰ�ͷ��");

	set("long", "��ͷ�����������Ĳ��䣬�͸���������һ����Ҳ�������ġ�����ɽ�����ܣ�����������ʽ�ɽ����������·ɥ������ɽ������������˵ȴ�Ǿ۱��裬ɽ��Ұ�������ζ��" );
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
