//milin2.h

//Sample for room:  ��������2
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_milin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������2");

	add_npc("pub_punk");    // add by zdn 2001-07-14
				
	add_door("���ҷ�����", "���ҷ�����", "��������2");
	add_door("���ҽ�����", "���ҽ�����", "��������2");

	set("long","���Ǻ�ɭɭ��һƬ���֣��ľ���죬Ũ�����ա����������Ǳ����£������ּ�������һ�����");

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
