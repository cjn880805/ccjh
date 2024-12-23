//road5.h

//Sample for room: ������ʯ���5
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���5");

	//add npcs into the room
	add_npc("honghua_honghua1");
	add_npc("pub_tiaofu");

	add_door("������Ȫ", "������Ȫ", "������ʯ���5");
	add_door("������ʯ���6", "������ʯ���6", "������ʯ���5");
	add_door("�����غ����1", "�����غ����1", "������ʯ���5");
	add_door("������ʯ���4", "������ʯ���4", "������ʯ���5");

	set("long","��������ˣ����У���˽Σ�����������ϲ�����������������������ȥ��Ȫ�µ�·������������򶫱ߺ����ϱߡ�");

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
