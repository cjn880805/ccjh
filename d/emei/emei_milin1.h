//milin1.h

//Sample for room:  ��������1
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_milin1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������1");
	
	add_npc("animal_dushe");           // add by zdn 2001-07-14

	add_door("���ұ�����", "���ұ�����", "��������1");
	add_door("���ҷ�����", "���ҷ�����", "��������1");

	set("long","���Ǻ�ɭɭ��һƬ���֣��ľ���죬Ũ�����ա����ﶫ�¶����Ǳ����£������ּ�������һ�����");

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
