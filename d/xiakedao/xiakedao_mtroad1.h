//mtroad1.h

//Sample for room: ���͵�����
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_mtroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�����");
	
	add_npc("wudang_dingdang");        //add by zdn 201-07-20

	add_door("���͵�ɽ·6", "���͵�ɽ·6", "���͵�����");
	add_door("���͵�ɽ·", "���͵�ɽ·", "���͵�����");

    

/*****************************************************
        set("exits", ([
            "east"  : "/d/henshan/hsroad5",
            "west"  : __DIR__"mtroad",
            "north" : __FILE__,
            "south" : __DIR__"mtroad2",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp