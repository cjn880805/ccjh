//road9.h

//Sample for room: ������ʯ���9
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���9");

	add_npc("pub_playboy");


	add_door("���ݶ���", "���ݶ���", "������ʯ���9");
	add_door("������ʯ���8", "������ʯ���8", "������ʯ���9");
	add_door("������ʯ���10", "������ʯ���10", "������ʯ���9");

	set("long"," ��������ˣ����л�˽Σ�����������ϲ�����������������������������ߡ������ڴ�������ϱߡ��ϱ�������һ�������");

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
