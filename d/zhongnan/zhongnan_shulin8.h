//shulin8.h

//Sample for room: ����ɽ����8
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shulin8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����8");

	//add npcs into the room
//	add_npc("animal_deer");
	add_npc("pub_xuaniu");
	
	add_door("����ɽ������", "����ɽ������", "����ɽ����8");
	add_door("����ɽ���ԭ", "����ɽ���ԭ", "����ɽ����8");


/*****************************************************
        set("exits", ([
                "northwest"  : __DIR__"shenheyuan",
                "east"       : __DIR__"baoziyan",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/deer": 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
