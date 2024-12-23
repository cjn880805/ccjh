//dalu1.h

//Sample for room: ���ݴ�·1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_dalu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݴ�·1");

	//add npcs into the room
	add_npc("pub_tiaofu");/////////////////////////
	add_npc("honghua_honghua1");

	add_door("�����غ����3", "�����غ����3", "���ݴ�·1");
	add_door("�����غ����2", "�����غ����2", "���ݴ�·1");

	set("long","·�Ķ�����һ��Сɽ��ɽ�������дУ�����������ɽ�ϱ���һ�����������ĺõط�����ȴ��������ռΪ˽�С���·�򶫱��������졣");

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
