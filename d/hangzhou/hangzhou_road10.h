//road10.h

//Sample for room: ������ʯ���10
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���10");
	
	add_npc("pub_guest");          // add by zdn 2001-07-14


	add_door("����¥��¥", "����¥��¥", "������ʯ���10");
	add_door("���ݺ���ׯ", "���ݺ���ׯ", "������ʯ���10");
	add_door("������ʯ���11", "������ʯ���11", "������ʯ���10");
	add_door("������ʯ���9", "������ʯ���9", "������ʯ���10");

	set("long"," �غ�����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫ƽ���־��󡣽ֵĶ�����һ����¥��");

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
