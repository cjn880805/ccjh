//road18.h

//Sample for room: ������ʯ���18
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road18);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���18");
	
	add_npc("pub_youke");         // add by zdn 2001-07-14


	add_door("����ʯ�ݶ�", "����ʯ�ݶ�", "������ʯ���18");
	add_door("������ʯ���17", "������ʯ���17", "������ʯ���18");
	add_door("������ʯ���19", "������ʯ���19", "������ʯ���18");

	set("long","��������ˣ����У���˽Σ�����������ϲ�����������������������򶫱��������ߣ�������ʯ�ݶ���" );

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
