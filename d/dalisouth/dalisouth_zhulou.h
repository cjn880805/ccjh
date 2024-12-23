//zhulou.h

//Sample for room: ��¥
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLisouth_zhulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��¥");

	//add npcs into the room
	add_npc("pub_kid");
	
	add_door("�����", "�����", "�������¥");

	set("long", "һ���׼��̨����¥������ǽ�ڽ������ӣ���������һ�������ε���̨�����ڼ�������¯�����崫ͳϯ�ض�˯�����������޴�����ǽ���е��죬�����ڳ���ʯ�Ѽ�̨����޼Ҿߡ�" );
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
