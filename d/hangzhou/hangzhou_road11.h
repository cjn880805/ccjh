//road11.h

//Sample for room: ������ʯ���11
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road11);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���11");

	add_npc("pub_playboy");

	add_door("������ʯ���12", "������ʯ���12", "������ʯ���11");
	add_door("������ʯ���10", "������ʯ���10", "������ʯ���11");
	add_door("����������", "����������", "������ʯ���11");

	set("long"," �غ�����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫ƽ���־��󡣽ֶ��ߵ�һ�ҵ����ﴫ�����������Ĵ�������");

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
