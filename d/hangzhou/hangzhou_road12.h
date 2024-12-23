//road12.h

//Sample for room: ������ʯ���12
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���12");

	add_npc("pub_playboy");

	add_door("���ݷ����Ժ", "���ݷ����Ժ", "������ʯ���12");
	add_door("������ʯ���13", "������ʯ���13", "������ʯ���12");
	add_door("������ʯ���11", "������ʯ���11", "������ʯ���12");

	set("long"," �غ�����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫ƽ���־��󡣽ֶ�����һ������Ժ����Ժ�ﲻʱ�������ʵ�Ц����    ���������߱��ǰ׵��ˡ������߿�ͨ����ʯ���");

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
