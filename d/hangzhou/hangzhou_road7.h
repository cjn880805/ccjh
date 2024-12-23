//road7.h

//Sample for room: ������ʯ���7
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���7");

	//add npcs into the room
	add_npc("quanzhen_youfang");
	
	add_door("����ɽ·8", "����ɽ·8", "������ʯ���7");
	add_door("����������", "����������", "������ʯ���7");
	add_door("������ʯ���8", "������ʯ���8", "������ʯ���7");
	add_door("������ʯ���6", "������ʯ���6", "������ʯ���7");

	set("long"," ��������ˣ����У���˽Σ�����������ϲ�����������������������������ߺͶ����ߡ������߱����ϱ�ɽ���ϱ���ͨ�������š�");

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
