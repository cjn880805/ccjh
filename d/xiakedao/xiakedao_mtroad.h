//mtroad.h

//Sample for room: ���͵�ɽ·
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_mtroad);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�ɽ·");
	
	add_npc("pub_dizi3");       //add by zdn 2001-07-16

	add_door("���͵�����", "���͵�����", "���͵�ɽ·");
	add_door("���͵��µ�", "���͵��µ�", "���͵�ɽ·");

    

/*****************************************************
        set("exits", ([
            "south" : __DIR__"mtyadi",
            "east"  : __DIR__"mtroad1",
        ]));
        set("objects",([
            __DIR__"npc/dingdang" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp