//road13.h

//Sample for room: ������ʯ���13
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road13);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���13");
	
	
	add_npc("pub_daoke");
	add_npc("pub_jianke");           // add by zdn 2001-07-14


	add_door("������ʯ���14", "������ʯ���14", "������ʯ���13");
	add_door("������ʯ���12", "������ʯ���12", "������ʯ���13");
	add_door("����������͵�", "����������͵�", "������ʯ���13");

	set("long","�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫ƽ���־��󡣽ֶ�����һ�ҿ͵ꡣ" );

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
