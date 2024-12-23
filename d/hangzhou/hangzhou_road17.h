//road17.h

//Sample for room: ������ʯ���17
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road17);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���17");

	//add npcs into the room
	add_npc("shaolin_chuyuan");/////////////////////////
	add_npc("pub_tiaofu");

	add_door("�������ɽ", "�������ɽ", "������ʯ���17");
	add_door("���ݻ���Ȫ", "���ݻ���Ȫ", "������ʯ���17");
	add_door("����Ǯ������", "����Ǯ������", "������ʯ���17");
	add_door("������ʯ���18", "������ʯ���18", "������ʯ���17");

	set("long"," ��������ˣ����У���˽Σ�����������ϲ�������������������������ϱ����ߣ������ǻ���Ȫ��������һ��ɽ·��");

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
