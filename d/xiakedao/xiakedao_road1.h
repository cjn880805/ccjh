//road1.h

//Sample for room: ���͵�ɽ·1
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�ɽ·1");
	
	add_npc("pub_daoke");         //add by zdn 2001-07-16

	add_door("���͵�ɽ��", "���͵�ɽ��", "���͵�ɽ·1");
	add_door("���͵��ٲ�", "���͵��ٲ�", "���͵�ɽ·1");

    

/*****************************************************
        set("exits", ([
                "southup" : __DIR__"road2",
                "northdown" :__DIR__"shanmen",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp