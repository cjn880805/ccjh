//langan4.h

//Sample for room: ����Ǹ���4
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_langan4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǹ���4");

	//add npcs into the room
	add_npc("pub_fangshanu");

//	add_door("����Ǹ���3", "����Ǹ���3", "����Ǹ���4");

	set("long", "�����Ǹ������в㣬��¥��һ�������Ǽ�������گ���Ĵ���ŷ��Լ��������е��������Ҽһ������������谸����в�����෿����Ϊ���������ݿ�������һ����ɴ����" );

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
