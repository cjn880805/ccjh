//road19.h

//Sample for room: ������ʯ���19
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road19);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���19");

	//add npcs into the room
	add_npc("pub_daoke");
	
	add_door("�����غ����3", "�����غ����3", "������ʯ���19");
	add_door("������ʯ���20", "������ʯ���20", "������ʯ���19");
	add_door("������ʯ���18", "������ʯ���18", "������ʯ���19");

	set("long","��������ˣ����У���˽Σ�����������ϲ�����������������������򶫺��������ߣ���������һ�������" );

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
