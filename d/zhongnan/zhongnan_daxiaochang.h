//daxiaochang.h

//Sample for room: ����ɽ��У��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_daxiaochang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��У��");

	add_npc("quanzhen_pi");

	add_door("����ɽɽ��8", "����ɽɽ��8", "����ɽ��У��");
	add_door("����ɽʯ��1", "����ɽʯ��1", "����ɽ��У��");
	add_door("����ɽɽ·7", "����ɽɽ·7", "����ɽ��У��");

    

/*****************************************************
        set("exits", ([
                "northup"     : "/d/quanzhen/shijie1",
                "westup"      : __DIR__"shanlu7",
                "southdown"   : __DIR__"shanlu8",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/pi": 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
