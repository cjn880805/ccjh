//dongmen.h

//Sample for room: ���͵�����
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_dongmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�����");

	add_door("���͵�ʯ��1", "���͵�ʯ��1", "���͵�����");
	add_door("���͵�ӭ����", "���͵�ӭ����", "���͵�����");

    

/*****************************************************
        set("exits", ([
                "enter" : __DIR__"yingbin",
                "west" : __DIR__"shidong1",
        ]));
        set("objects", ([
                __DIR__"npc/dizi1" : 1]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp