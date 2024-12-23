//lingyinsi.h

//Sample for room: ����������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_lingyinsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");
	
	add_npc("pub_guest");           // add by zdn 2001-07-14


	add_door("������ʯ���1", "������ʯ���1", "����������");
	add_door("����������", "����������", "����������");

	set("long","���������������£���ǰ���峺��СϪ��Ϫ�Խ�����Ȫͤ�ͺ���ͤ���������Ŀ�ɼ����������������������ϱ�ص������" );

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
