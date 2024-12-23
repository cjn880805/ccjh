//road20.h

//Sample for room: ������ʯ���20
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road20);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���20");
	
	add_npc("pub_poorman");
	add_npc("pub_boy");          // add by zdn 2001-07-14


	add_door("�����յ�7", "�����յ�7", "������ʯ���20");
	add_door("������ʯ���16", "������ʯ���16", "������ʯ���20");
	add_door("������ʯ���19", "������ʯ���19", "������ʯ���20");

	set("long"," ��������ˣ����У���˽Σ�����������ϲ�����������������������������ߣ��������յ̡�");

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
