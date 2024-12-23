//road2.h

//Sample for room: ������ʯ���2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���2");

	//add npcs into the room
	add_npc("pub_xianghuo");
	
	add_door("����ɽ·1", "����ɽ·1", "������ʯ���2");
	add_door("������ʯ���3", "������ʯ���3", "������ʯ���2");
	add_door("������ʯ���1", "������ʯ���1", "������ʯ���2");

	set("long","��������ˣ����У���˽Σ�����������ϲ����������������������ºͷ����塣�����������á�" );

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
