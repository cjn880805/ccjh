//road6.h

//Sample for room: ���͵�ɽ·6
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_road6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�ɽ·6");
	
	add_npc("pub_shizhe1");        //add by zdn 2001-07-16

	add_door("���͵�ʯ��8", "���͵�ʯ��8", "���͵�ɽ·6");
	add_door("���͵��б�ʯ", "���͵��б�ʯ", "���͵�ɽ·6");
	add_door("���͵�����", "���͵�����", "���͵�ɽ·6");

    

/*****************************************************
        set("outdoors", "xiakedao");
        set("exits", ([
                "southup" : __DIR__"road7",
                "northdown" : __DIR__"road5",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp