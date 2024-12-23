//dating.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	//add npcs into the room
	add_npc("pub_zishanshizhe");
	add_npc("pub_zishanshizhe");
	add_npc("pub_zishanshizhe");
	
	add_door("����ǹŵ�", "����ǹŵ�", "����Ǵ���");

	set("long", "�������廪¥��ǰ�������쳣������������һ�������ȫ����ʯ�̵أ��ڰ���䣬����������ɶ�����ǧ�ˡ�ʱʱ�ɼ���������������ʳ�������ߡ�" );
	
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
//last, register the room into ../server/RoomSetup.cpp